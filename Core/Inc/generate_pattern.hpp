
#ifndef _GENERATE_PATTERN_HPP
#define _GENERATE_PATTERN_HPP

#include "matrix.hpp"
#include "pattern.hpp"

namespace generate_pattern {

constexpr auto square_max_h = Matrix({0xff, 0b1000'0001, 0b1000'0001, 0b1000'0001,
                                0b1000'0001, 0b1000'0001, 0b1000'0001, 0xff});

Matrix rect(uint8_t width, uint8_t height);
Matrix square(uint8_t width);
pattern_t square_pat(int x);

}  // End namespace pattern

#endif
