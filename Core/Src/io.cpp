
#include "io.hpp"
#include "main.h"
#include "etl/array.h"

namespace io 
{
// struct Pin methods and operators
bool Pin::operator=(bool v) {
  auto bit_value = (v ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin((GPIO_TypeDef*)Pin::port, Pin::num, bit_value);
  return v;
}

bool Pin::operator=(int v) {
  return *this = v > 0;
}

void Pin::set() {
  *this = true;
}

void Pin::reset() {
  *this = false;
}

void Pin::toggle() const {
  HAL_GPIO_TogglePin((GPIO_TypeDef*)port, num);
}

Pin::operator bool() {
  const auto state = HAL_GPIO_ReadPin((GPIO_TypeDef *)port, num);
  return state == GPIO_PIN_SET;
}


////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void write_row(int row, unsigned char value) {
  if (row < 0 || row > io::max_row)
    return;  // Boundry check, do with definition

  // Write to colums starting from leftmost one (MSB)
  for (auto col : io::pins_colums) {
    col = value & 0b1000'0000;
    value <<= 1;
  }

  // Enable row (active low)
  auto row_to_enable = io::pins_rows.at(row);
  row_to_enable.reset();
}

// Turn off all LEDs
void clear() {
  // Active low led pin, disable with high
  for (auto r : io::pins_rows) {
    r.set();
  }

  for (auto c : io::pins_colums) {
    c.reset();
  }
}

}  // End namespace io
