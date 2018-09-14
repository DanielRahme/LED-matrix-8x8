
#include "animations.h"
//#include "led.h"

//TODO: Make check functions.

//Change to bool and check != NULL
void construct_anim(struct Animation *a, const int length)
{
        a->length = length;
        a->patterns = (struct Pattern *)malloc(sizeof(struct Pattern) * length);
}

void destruct_anim(struct Animation *a)
{
        free(a->patterns);
        a->patterns = 0;
}


void add_animation(struct Animation *a, struct Pattern *pat[])
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




void animate(struct Pattern *pats[], const int length, const int loops)
{
	struct Animation anim;
	construct_anim(&anim, length);
        add_animation(&anim, pats);
        disp_animation(anim, loops);
	destruct_anim(&anim);
}


/********* Animations ****************/
/*const struct Pattern *anim_1[2] = {&pat1, &pat2};
const struct Pattern *anim_cw_sqr[4] = {&pat3a, &pat3b, &pat3c, &pat3d};
const struct Pattern *anim_ccw_sqr[4] = {&pat3d, &pat3c, &pat3b, &pat3a};
const struct Pattern *anim_cw_sqr_inv[4] = {&pat3a_inv, &pat3b_inv, &pat3c_inv, &pat3d_inv};

const struct Pattern *anim_half[1] = {&pat_low_half};
*/



