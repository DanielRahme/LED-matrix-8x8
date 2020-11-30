
#include "pattern.hpp"

namespace pattern {

Matrix rect(uint8_t width, uint8_t height) {

    auto m = Matrix();
    if (width == 0 && height == 0) return m;

    const auto hline = (1 << width) - 1;
    const auto offset = io::max_column - width;

    for (auto i = 0; i < height; i++) {
      m.matrix[i] = hline << offset;
    }
    return m;
}

Matrix square(uint8_t width) {
  return rect(width, width);
}

}  // End namepsace pattern
