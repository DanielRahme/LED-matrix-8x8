
#ifndef _PATTERN_HPP
#define _PATTERN_HPP

#include "matrix.hpp"

namespace pattern {

constexpr auto square = Matrix({0xff, 0b1000'0001, 0b1000'0001, 0b1000'0001,
                                0b1000'0001, 0b1000'0001, 0b1000'0001, 0xff});

}  // End namespace pattern

#endif