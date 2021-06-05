
#include "display.hpp"
#include "leds.hpp"

void Display::update()
{
  leds::reset();
  leds::write_row(this->idx_row, this->pattern[this->idx_row]);

  this->idx_row = (this->idx_row + 1) % 8;
}

pattern_t Display::operator=(pattern_t p)
{
  this->pattern = p;
  this->idx_row = 0;  // Reset row index
  return this->pattern;
}

Display::operator pattern_t()
{
  return this->pattern;
}