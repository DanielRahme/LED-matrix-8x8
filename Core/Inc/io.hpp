#ifndef _IO_HPP
#define _IO_HPP

#include "io.hpp"
#include "main.h"

#define GPIOC_BASE 1u
#define GPIOB_BASE 2u

namespace io {

  // io constants
  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

  void write_row(int row, unsigned char value);
  void pins_default();

    struct Pin {

      constexpr Pin(uint32_t p = 0, uint16_t n = 0)
                    : port(p), num(n){};

      bool operator=(bool v);
      bool operator=(int v);
      explicit operator bool();

      void set();
      void reset();
      void write(int value);
      void toggle();

      uint32_t port = 0;
      uint16_t num = 0;
    };
}

#endif
