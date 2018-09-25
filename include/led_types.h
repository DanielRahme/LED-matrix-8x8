#ifndef LED_TYPES_H
#define LED_TYPES_H

#include <stdint.h>
#include <stdbool.h>

// TODO: move Animation struct here from include/animations.h

typedef struct {
        uint8_t delay;
        uint8_t pattern[8];
} pattern_t;

#endif
