#include <stdio.h>
#include "led.h"

int main()
{
        print_pattern(pat_pi);
        print_pattern(pat_dance_1a);

        for (int i = -3; i < 13; i++) {
                pattern_t rect = draw_square(i);
                print_pattern(rect);
        }

        printf("Bye bye world!\n");

        return 0;
}
