#ifndef _PATTERN_HPP
#define _PATTERN_HPP

#include <array>
#include <bitset>

using led_row_t = std::bitset<8>;
using pattern_t = std::array<led_row_t, 8>;   // 8x8 pattern

struct Pattern {
  // Members
  pattern_t   pattern;
  // Constructors
  constexpr Pattern(pattern_t p = {0}) : pattern(p){};

  // Functions
  // Rotate
  // Invert
  // etc...
};

#endif
