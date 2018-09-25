#ifndef LED_H
#define LED_H

#include <stdarg.h>
#include <stdio.h>
#include "led_hw.h"
#include "patterns.h"
#include "led_types.h"
#include "geometry.h"

#define ROWS 8 //change to 8 when matrix hw is done
#define COLS 8

pattern_t inv_pat(const pattern_t p);

void print_row(const uint8_t row);
void leds_off();
void leds_on();
void print_pattern(const pattern_t p);
pattern_t inv_pat(const pattern_t p);
void row_scroll_down(const uint8_t row);
void row_scroll_up(const uint8_t row);
void col_scroll_right(const uint32_t delay_ms);
void col_scroll_left(const uint32_t delay_ms);
void blink();
void disp_pattern(const pattern_t p, const uint32_t duration);
void arg_animate(uint16_t num_of_patterns, ...);


#endif
