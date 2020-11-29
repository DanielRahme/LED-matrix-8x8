
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
  auto n = 0;
  for (auto row : m.matrix) {
    io::clear();
    io::write_row(n++, row);
    my_delay(this->delay);
  }
}
