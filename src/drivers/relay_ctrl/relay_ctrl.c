//
// Created by milho on 7/23/24.
//

#include "relay_ctrl.h"

static const struct gpio_dt_spec enable_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), enable_gpios);

static const struct gpio_dt_spec clock_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), clock_gpios);

static const struct gpio_dt_spec data_pin_spec = GPIO_DT_SPEC_GET(DT_NODELABEL(relay), data_gpios);

// static const struct gpio_dt_spec reset_pin_spec =
// 	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), reset_gpios);

int relay_ctrl_init(void)
{
	int err;

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

	return 0;
}

int relay_ctrl_set(uint32_t toggle)
{

	return 0;
}