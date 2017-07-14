#ifndef PATTERNS_H
#define PATTERNS_H

#include "main.h"
#include <stdlib.h>
#include "gpio.h"
#include "led.h"

struct Pattern {
        int delay;
        uint8_t pattern[2];
};

extern const struct Pattern pat1;
extern const struct Pattern pat2;
extern const struct Pattern pat3a;
extern const struct Pattern pat3b;
extern const struct Pattern pat3c;
extern const struct Pattern pat3d;


#endif