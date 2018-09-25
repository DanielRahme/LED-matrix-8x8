#include "geometry.h"

uint8_t bit_width(const uint8_t length)
{
        return (1 << length) - 1;
}


pattern_t draw_square(const uint8_t width)
{
        return draw_rect(width, width);
}


pattern_t draw_rect(const uint8_t width, const uint8_t height)
{
        pattern_t rect = {0};

        if (height > COLS || width > ROWS)
                return rect;

        rect.pattern[0]         = bit_width(width);
        rect.pattern[height-1]  = bit_width(width);

        for (int i = 1; i < (height-1); i++) {
                rect.pattern[i] = (1 << (width-1)) + 1;
        }

        return rect;
}
