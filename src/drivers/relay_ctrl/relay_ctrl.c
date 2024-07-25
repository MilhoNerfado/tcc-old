//
// Created by milho on 7/23/24.
//

#include "relay_ctrl.h"

#include <zephyr/drivers/gpio.h>

static const struct gpio_dt_spec relay_enable_pin =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), enable_gpios);

static const struct gpio_dt_spec relay_clock_pin =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), clock_gpios);

static const struct gpio_dt_spec relay_data_pin =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), data_gpios);

// static const struct gpio_dt_spec relay_reset_pin =
// 	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), reset_gpios);

int relay_ctrl_init();