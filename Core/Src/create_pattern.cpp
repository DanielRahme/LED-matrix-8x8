
#include "create_pattern.hpp"
#include "pattern.hpp"
#include "pixel.hpp"

namespace create_pattern {

pattern_t square(int x)
{
  pattern_t p = {};

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
