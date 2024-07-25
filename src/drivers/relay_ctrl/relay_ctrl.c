//
// Created by milho on 7/23/24.
//

#include "relay_ctrl.h"

#include <zephyr/drivers/gpio.h>

static const struct gpio_dt_spec relay_enable_pin =
	GPIO_DT_SPEC_GET_OR(DT_NODELABEL(enable), gpios, 0);

int relay_ctrl_init();