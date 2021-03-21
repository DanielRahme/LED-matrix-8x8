
#include "display.hpp"

void Display::operator=(Matrix m) { 
  Display::update(m); 
}

void Display::my_delay(uint32_t delay) {
  for (volatile auto i = 0; i < delay; i++)
    for (volatile auto j = 0; j < delay; j++)
      ;
}

void Display::update(Matrix m) {
  const auto lines = m.matrix;
  auto colums = pixel::pins_colums;
  auto rows = pixel::pins_rows;

  pixel::clear();

  for (auto r = 0; r < pixel::max_row; r++) {
    for (auto c = 0; c < pixel::max_column; c++) {
      colums[c] = (lines[r] >> (pixel::max_column - 1 - c)) & 1;  // Write to column
    }
    rows[r].reset();  // Enable row row
    my_delay(this->delay);
    rows[r].set();  // Disable row row
  }
}
