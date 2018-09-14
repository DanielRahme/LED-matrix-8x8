#ifndef PATTERNS_H
#define PATTERNS_H

//#include "main.h"
#include <stdlib.h>
#include <stdint.h>
//#include "gpio.h"
#include "led.h"

struct Pattern {
        uint8_t delay;
        uint8_t pattern[8];
};

extern const struct Pattern pat_clear;

extern const struct Pattern pat_smile_1;
extern const struct Pattern pat_smile_2;
extern const struct Pattern pat_smile_3;

extern const struct Pattern pat_pi;

extern const struct Pattern pat_dance_1a;
extern const struct Pattern pat_dance_1b;


extern const struct Pattern pat_square_1a;
extern const struct Pattern pat_square_1b;
extern const struct Pattern pat_square_1c;
extern const struct Pattern pat_square_1d;

#endif
