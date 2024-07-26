//
// Created by milho on 7/23/24.
//

#include "relay_ctrl.h"

#include <zephyr/drivers/gpio.h>

static const struct gpio_dt_spec enable_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), enable_gpios);

static const struct gpio_dt_spec clock_pin_spec =
	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), clock_gpios);

static const struct gpio_dt_spec data_pin_spec = GPIO_DT_SPEC_GET(DT_NODELABEL(relay), data_gpios);

// static const struct gpio_dt_spec reset_pin_spec =
// 	GPIO_DT_SPEC_GET(DT_NODELABEL(relay), reset_gpios);

int relay_ctrl_init()
{
	return 0;
}