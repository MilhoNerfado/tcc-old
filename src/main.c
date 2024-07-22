/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec load_switch =
	GPIO_DT_SPEC_GET_OR(DT_NODELABEL(load_switch), gpios, {0});

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);

	if (!gpio_is_ready_dt(&load_switch)) {
		printf("The load switch pin GPIO port is not ready.\n");
		return 0;
	}

	printf("Initializing pin with inactive level.\n");

	int err = gpio_pin_configure_dt(&load_switch, GPIO_OUTPUT_INACTIVE);
	if (err != 0) {
		printf("Configuring GPIO pin failed: %d\n", err);
		return 0;
	}

	printf("Waiting one second.\n");

	k_sleep(K_MSEC(1000));

	printf("Setting pin to active level.\n");

	err = gpio_pin_set_dt(&load_switch, 1);
	if (err != 0) {
		printf("Setting GPIO pin level failed: %d\n", err);
	}
	return 0;
}
