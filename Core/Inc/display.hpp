#ifndef _DISP_HPP
#define _DISP_HPP

#include "io.hpp"
#include "matrix.hpp"



struct Display {
  Display(uint32_t d = 0) : delay(d){}; // Constructor

  void operator=(Matrix m);       // Write
  //explicit operator bool();     // Read

  static void my_delay(uint32_t delay); // TODO: Replace this
  void update(Matrix m);

  uint32_t delay = 0;
};
#endif
