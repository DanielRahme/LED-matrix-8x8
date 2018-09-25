#ifndef LED_H
#define LED_H

//#include "main.h"
//#include "stm32f4xx_hal.h" // Move this to led_hw.h
//#include "gpio.h"
//#include <stdlib.h>
//#include <stdbool.h>
#include <stdarg.h>
#include "led_hw.h"
#include "patterns.h"
#include <stdint.h>
#include "animations.h"


struct Pattern inv_pat(const struct Pattern p);

void print_row(const uint8_t row);
void leds_off();
void leds_on();
void print_pattern(const struct Pattern p);
struct Pattern inv_pat(const struct Pattern p);
void row_scroll_down(const uint8_t row);
void row_scroll_up(const uint8_t row);
void col_scroll_right(const uint32_t delay_ms);
void col_scroll_left(const uint32_t delay_ms);
void blink();
void disp_pattern(const struct Pattern p, const uint32_t duration);
void arg_animate(uint16_t num_of_patterns, ...);
//void print_pattern(const struct Pattern p);


#endif
