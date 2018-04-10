#ifndef LED_H
#define LED_H

#include "main.h"
#include "stm32f3xx_hal.h" // Move this to led_hw.h
#include "gpio.h"
#include <stdlib.h>
#include <stdbool.h>
#include "led_hw.h"
//#include "patterns.h"
//#include "animations.h"


void write_row(const uint8_t row);
void leds_off();
void leds_on();
void matrix_test(const uint32_t delay);
void blink(const uint32_t delay);
//void disp_pattern(const struct Pattern p);
//void print_pattern(const struct Pattern p);


#endif
