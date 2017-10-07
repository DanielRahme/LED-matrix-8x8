#ifndef LED_H
#define LED_H

#include "main.h"
#include "stm32f3xx_hal.h"
#include "gpio.h"
#include <stdlib.h>
#include <stdbool.h>
#include "patterns.h"
#include "animations.h"



void leds_off();
void leds_on();
void matrix_test(const uint32_t delay);
void matrix_test(const uint32_t delay);
void disp_pattern(const struct Pattern p);
void print_pattern(const struct Pattern p);


#endif