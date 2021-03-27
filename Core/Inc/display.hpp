#ifndef _DISP_HPP
#define _DISP_HPP

#include "pixel.hpp"
#include "matrix.hpp"
#include "animation.hpp"



struct Display {
  Display(uint32_t d = 0) : delay(d){}; // Constructor

  void operator=(Matrix m);       // Write
  void operator=(Animation a);       // Write
  //explicit operator bool();     // Read

  static void my_delay(uint32_t delay); // TODO: Replace this
  void update(Matrix m);
  //void update(Animation a);

  uint32_t delay = 0;
};

#endif
