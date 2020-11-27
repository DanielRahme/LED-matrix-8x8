#ifndef _DISP_HPP
#define _DISP_HPP

#include "io.hpp"
#include "matrix.hpp"


auto my_delay = [](auto delay) {
  for (volatile auto i = 0; i < delay; i++)
    for (volatile auto j = 0; j < delay; j++)
      ;
};

struct Display {
  Display(uint32_t d = 0) : delay(d){};

  void operator=(Matrix m) {
    update(m);
  }

  void update(Matrix m) {
    auto n = 0;
    for (auto row : m.matrix) {
      io::pins_default();
      io::write_row(n++, row);
      my_delay(this->delay);
    }
  }

  //explicit operator bool();  // Read
  uint32_t delay = 0;
};
#endif
