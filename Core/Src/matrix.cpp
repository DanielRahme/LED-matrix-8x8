#include "matrix.hpp"

auto my_delay = [](auto delay) {
  for (volatile auto i = 0; i < delay; i++)
    for (volatile auto j = 0; j < delay; j++)
      ;
};

// Temporary
void Matrix::display(int delay) {
  for (auto i = 0; i < io::max_row; i++) {
    io::pins_default();
    io::write_row(i, (*this).matrix.at(i));
    my_delay(delay);
  }
}
