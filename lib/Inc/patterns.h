#ifndef PATTERNS_H
#define PATTERNS_H

#include "main.h"
#include <stdlib.h>
#include "gpio.h"
#include "led.h"

struct Pattern {
        uint8_t delay;
        uint8_t pattern[8];
};

extern const struct Pattern pat_clear;
extern const struct Pattern pat1;
extern const struct Pattern pat2;

extern const struct Pattern pat3a;
extern const struct Pattern pat3b;
extern const struct Pattern pat3c;
extern const struct Pattern pat3d;

extern const struct Pattern pat3a_inv;
extern const struct Pattern pat3b_inv;
extern const struct Pattern pat3c_inv;
extern const struct Pattern pat3d_inv;

extern const struct Pattern pat_low_half;


#endif