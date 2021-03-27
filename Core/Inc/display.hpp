#ifndef _DISP_HPP
#define _DISP_HPP

#include "pixel.hpp"
#include "animation.hpp"



struct Display {
  Display(uint32_t d = 0) : delay(d){}; // Constructor

  void operator=(Animation a);       // Write
  //explicit operator bool();     // Read

  static void my_delay(uint32_t delay); // TODO: Replace this


  uint32_t delay = 0;
};

#endif
