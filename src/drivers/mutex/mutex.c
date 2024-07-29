//
// Created by milho on 7/23/24.
//

#include "mutex.h"

static const struct gpio_dt_spec enable_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), enable_gpios);

static const struct gpio_dt_spec clock_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), clock_gpios);

static const struct gpio_dt_spec data_pin_spec = GPIO_DT_SPEC_GET(DT_NODELABEL(relay), data_gpios);

// static const struct gpio_dt_spec reset_pin_spec =
// 	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), reset_gpios);

static int mutex_data_push(bool data);

static struct self {
	bool is_init;
} self = {
	.is_init = false,
};

int mutex_init(void)
{
	int err;

	if (self.is_init) {
		return 0;
	}

	if (gpio_is_ready_dt(&enable_pin_spec) != 0) {
		return -ENODEV;
	}
	if (gpio_is_ready_dt(&clock_pin_spec) != 0) {
		return -ENODEV;
	}
	if (gpio_is_ready_dt(&data_pin_spec) != 0) {
		return -ENODEV;
	}

	err = gpio_pin_configure_dt(&enable_pin_spec, GPIO_OUTPUT_HIGH);
	if (err != 0) {
		return err;
	}
	err = gpio_pin_configure_dt(&clock_pin_spec, GPIO_OUTPUT_HIGH);
	if (err != 0) {
		return err;
	}
	err = gpio_pin_configure_dt(&data_pin_spec, GPIO_OUTPUT_HIGH);
	if (err != 0) {
		return err;
	}

	self.is_init = true;

	return 0;
}

int mutex_set(uint32_t toggle)
{
	if (!self.is_init) {
		return -ENOEXEC;
	}

	for (int i = 0; i < CONFIG_RELAY_LEN; ++i) {
		relay_data_push(toggle & 1);
		toggle >>= 1;
	}

	/* TODO: toggle enable. Should check data sheet for behaviour */
	gpio_pin_set_dt(&enable_pin_spec, 0);
	gpio_pin_set_dt(&enable_pin_spec, 1);
	gpio_pin_set_dt(&enable_pin_spec, 0);

	return 0;
}

static int mutex_push(const bool data)
{
	if (!self.is_init) {
		return -ENOEXEC;
	}

	gpio_pin_set_dt(&data_pin_spec, data);

	/* TODO: Toggle clock. Should check data sheet for behaviour */
	gpio_pin_set_dt(&clock_pin_spec, 1);
	gpio_pin_set_dt(&clock_pin_spec, 0);

	return 0;
}