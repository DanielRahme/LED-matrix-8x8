
#include "animations.h"

//Not working as intended

/*
struct Animation *create_animation(const uint8_t n)
{
        struct Animation *a = malloc(n * sizeof(struct Pattern) + sizeof(struct Animation));
        
        a->length = n;
        for (int i = 0; i < n; i++)
                a->patterns[i] = (struct Pattern){0};
        return a;
}


struct Animation *anim2;
anim2 = create_animation(n);
anim2->patterns[0] = pat1;
anim2->patterns[1] = pat2
anim2->patterns[2] = pat3d;
anim2->patterns[3] = pat3c;
*/

/*
struct Pattern p[4] = {pat1, pat2, pat3d, pat3c};
struct Pattern *p_ptr = p;
struct Animation a2 = {
        .length = 4,
        .patterns = p_ptr;
};
*/