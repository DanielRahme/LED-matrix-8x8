
#include "animations.h"

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

void add_animation(struct Animation *a, const struct Pattern pat[])
{
        for (int i = 0; i < a->length; i++) 
                a->patterns[i] = pat[i];    
}



/********* Animations ****************/
//const struct Pattern anim_test[3] = {pat1, pat2, pat3d};

