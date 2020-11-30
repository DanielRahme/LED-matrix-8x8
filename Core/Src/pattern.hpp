
#ifndef _PATTERN_HPP
#define _PATTERN_HPP

#include "matrix.hpp"

namespace pattern {

constexpr auto square = Matrix({0xff, 0b1000'0001, 0b1000'0001, 0b1000'0001,
                                0b1000'0001, 0b1000'0001, 0b1000'0001, 0xff});

Matrix rect(uint8_t width, uint8_t height);

}  // End namespace pattern

#endif