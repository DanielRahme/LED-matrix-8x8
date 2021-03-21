
#include "generate_pattern.hpp"
#include "pattern.hpp"

namespace generate_pattern {

Matrix rect(uint8_t width, uint8_t height) {

    auto m = Matrix();
    if (width == 0 && height == 0) return m;

    const auto hline = (1 << width) - 1;
    const auto offset = pixel::max_column - width;

    for (auto i = 0; i < height; i++) {
      m.matrix[i] = hline << offset;
    }
    return m;
}

Matrix square(uint8_t width) {
  return rect(width, width);
}

pattern_t square_pat(int x)
{
  pattern_t p = {0};

  // Check size is valid
  if (x <= 0) return p;

    const auto hline = (1 << x) - 1;
    const auto offset = pixel::max_column - x;

    for (auto i = 0; i < x; i++) {
      p[i] = hline << offset;
    }
    return p;
}

}  // End namepsace pattern
