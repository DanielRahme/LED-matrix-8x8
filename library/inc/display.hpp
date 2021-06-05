#ifndef _DISPLAY_HPP
#define _DISPLAY_HPP

#define ETL_NO_STL 1
#include "etl/array.h"
#include <cstdint>

using pattern_t = etl::array<std::uint8_t, 8>;

struct Display {
  pattern_t pattern;
  int idx_row = 0;

  constexpr Display(pattern_t p = {0}) : pattern(p){};

  void update();

  pattern_t operator=(pattern_t p);
  explicit operator pattern_t();
};

#endif