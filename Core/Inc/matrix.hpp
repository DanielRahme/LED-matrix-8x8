#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include "etl/array.h"
#include "io.hpp"

using matrix_t = etl::array<uint8_t, io::max_row>;

struct Matrix {
  constexpr Matrix(matrix_t m) : matrix(m){};

  // void operator=(matrix_t m);
  void display(int delay);  // Temporary method
  // int rotate_90() // TODO
  // int rotate(Angle r); // TODO

  matrix_t matrix = {};
};

#endif
