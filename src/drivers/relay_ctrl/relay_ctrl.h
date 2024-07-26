//
// Created by milho on 7/23/24.
//

#ifndef RELAY_CTRL_H
#define RELAY_CTRL_H

#include <stdint.h>
#include <zephyr/drivers/gpio.h>

int relay_ctrl_init();

int relay_ctrl_set(uint32_t toggle);

#endif // RELAY_CTRL_H
