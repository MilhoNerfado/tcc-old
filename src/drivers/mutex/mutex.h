//
// Created by milho on 7/23/24.
//

#ifndef MUTEX_H
#define MUTEX_H

#include <stdint.h>
#include <zephyr/drivers/gpio.h>

int mutex_init();

int mutex_set(uint32_t toggle);

#endif // MUTEX_H
