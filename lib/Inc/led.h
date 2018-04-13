#ifndef LED_H
#define LED_H

#include "main.h"
#include "stm32f4xx_hal.h" // Move this to led_hw.h
#include "gpio.h"
#include <stdlib.h>
#include <stdbool.h>
#include "led_hw.h"
#include "patterns.h"
//#include "animations.h"


struct Pattern inv_pat(const struct Pattern p);
void leds_off();
void leds_on();
struct Pattern inv_pat(const struct Pattern p);
void row_scroll_down(const uint8_t row, const uint32_t delay_ms);
void row_scroll_up(const uint8_t row, const uint32_t delay_ms);
void col_scroll_right(const uint32_t delay_ms);
void col_scroll_left(const uint32_t delay_ms);
void blink(const uint32_t delay);
void disp_pattern(const struct Pattern p, const uint32_t duration);
//void print_pattern(const struct Pattern p);


#endif
