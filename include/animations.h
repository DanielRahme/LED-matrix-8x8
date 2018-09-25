#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <stdlib.h>
#include "led.h"
#include "patterns.h"
#include "led_types.h"

struct Animation {
        int length;
        pattern_t *patterns;
};



void construct_anim(struct Animation *a, const int length);
void destruct_anim(struct Animation *a);
void add_animation(struct Animation *a, pattern_t *pat[]);
void disp_animation(struct Animation a, const int loops);
void animate(pattern_t *pats[], const int length, const int loops);

extern const pattern_t *anim_1[2];
extern const pattern_t *anim_cw_sqr[4];
extern const pattern_t *anim_ccw_sqr[4];
extern const pattern_t *anim_cw_sqr_inv[4];

extern const pattern_t *anim_half[1];


   

#endif
