
#include "animations.h"
//#include "led.h"

//TODO: Make check functions.

//Change to bool and check != NULL
void construct_anim(struct Animation *a, const int length)
{
        a->length = length;
        a->patterns = (pattern_t *)malloc(sizeof(pattern_t) * length);
}

void destruct_anim(struct Animation *a)
{
        free(a->patterns);
        a->patterns = 0;
}


void add_animation(struct Animation *a, pattern_t *pat[])
{
        for (int i = 0; i < a->length; i++) 
                a->patterns[i] = *pat[i];    
}

void disp_animation(struct Animation a, const int loops)
{
        for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < loops; j++) {
			disp_pattern(a.patterns[i], 0);
			//HAL_Delay(a.patterns[i].delay);
			leds_off();
	        }
        }
}




void animate(pattern_t *pats[], const int length, const int loops)
{
	struct Animation anim;
	construct_anim(&anim, length);
        add_animation(&anim, pats);
        disp_animation(anim, loops);
	destruct_anim(&anim);
}


/********* Animations ****************/
/*const pattern_t *anim_1[2] = {&pat1, &pat2};
const pattern_t *anim_cw_sqr[4] = {&pat3a, &pat3b, &pat3c, &pat3d};
const pattern_t *anim_ccw_sqr[4] = {&pat3d, &pat3c, &pat3b, &pat3a};
const pattern_t *anim_cw_sqr_inv[4] = {&pat3a_inv, &pat3b_inv, &pat3c_inv, &pat3d_inv};

const pattern_t *anim_half[1] = {&pat_low_half};
*/



