#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "main.h"
#include "stm32f3xx_hal.h"
#include <stdlib.h>
#include "gpio.h"
#include "led.h"
#include "patterns.h"

struct Animation {
        int length;
        struct Pattern *patterns;
};



void construct_anim(struct Animation *a, const int length);
void destruct_anim(struct Animation *a);
void add_animation(struct Animation *a, const struct Pattern pat[]);
void add_animation_ptr(struct Animation *a, const struct Pattern *pat[]);
void disp_animation(struct Animation a, const int loops);
void animate(struct Pattern *pats[], const int length, const int loops);

extern const struct Pattern *anim_1[2];
extern const struct Pattern *anim_cw_sqr[4];
extern const struct Pattern *anim_ccw_sqr[4];
extern const struct Pattern *anim_cw_sqr_inv[4];


   

#endif