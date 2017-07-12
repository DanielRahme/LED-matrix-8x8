#ifndef LED_H
#define LED_H

#include "main.h"
#include "stm32f3xx_hal.h"
#include "gpio.h"
#include <stdlib.h>
#include <stdbool.h>
#include "patterns.h"
#include "animations.h"


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