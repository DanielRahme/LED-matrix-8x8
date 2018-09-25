#ifndef LED_TYPES
#define LED_TYPES

#include <stdint.h>
#include <stdbool.h>

// TODO: move Animation struct here from include/animations.h

typedef struct {
        uint8_t delay;
        uint8_t pattern[8];
} pattern_t;

#endif
