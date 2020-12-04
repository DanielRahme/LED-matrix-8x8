
#ifndef _PATTERN_HPP
#define _PATTERN_HPP

#include "matrix.hpp"

namespace pattern {

constexpr auto square_max_h = Matrix({0xff, 0b1000'0001, 0b1000'0001, 0b1000'0001,
                                0b1000'0001, 0b1000'0001, 0b1000'0001, 0xff});

Matrix rect(uint8_t width, uint8_t height);
Matrix square(uint8_t width);

}  // End namespace pattern

#endif