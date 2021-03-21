#ifndef _PATTERN_HPP
#define _PATTERN_HPP

#include <array>
#include <bitset>

using led_row_t = std::bitset<8>;
using pattern_t = std::array<led_row_t, 8>;   // 8x8 pattern

struct Pattern {
  // Members
  pattern_t   pattern;
  int         row_duration;

  // Constructors
  constexpr Pattern(pattern_t p = {0}, int duration = 1) : pattern(p), row_duration(duration) {};

  // Functions
  // Rotate
  // Invert
  // etc...
};

#endif
