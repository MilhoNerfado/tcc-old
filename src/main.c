/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

#include "drivers/mutex/mutex.h"

int main(void)
{
	int err;

	err = mutex_init();

	if (err != 0) {
		printk("Failed to init the mutex driver");
		return -1;
	}

	return 0;
}

static int cmd_mutex_clear(void)
{
	return mutex_set(0);
}