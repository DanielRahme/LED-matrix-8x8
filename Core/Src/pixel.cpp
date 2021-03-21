
#include "pixel.hpp"
#include "main.h"
#include "etl/array.h"

namespace pixel
{

////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void write_row(int row, unsigned char value) {
  if (row < 0 || row > pixel::max_row)
    return;  // Boundry check, do with definition

  // Write to colums starting from leftmost one (MSB)
  for (auto col : pixel::pins_colums) {
    col = value & 0b1000'0000;
    value <<= 1;
  }

  // Enable row (active low)
  auto row_to_enable = pixel::pins_rows.at(row);
  row_to_enable.reset();
}

// Turn off all LEDs
void clear() {
  // Active low led pin, disable with high
  for (auto r : pixel::pins_rows) {
    r.set();
  }

  for (auto c : pixel::pins_colums) {
    c.reset();
  }
}

}  // End namespace io
