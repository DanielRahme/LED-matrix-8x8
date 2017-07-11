#ifndef LED_H
#define LED_H

#include "main.h"
#include "stm32f3xx_hal.h"
#include "gpio.h"
#include <stdlib.h>
#include <stdbool.h>

struct Pattern {
        int delay;
        uint8_t pattern[2];
};

struct Animation {
        int length;
        struct Pattern *patterns;
};



void leds_off();
void leds_on();
void blink();
void matrix();
void disp_pattern(const struct Pattern p);
void disp_animation(const struct Animation a, const int loops);

#endif