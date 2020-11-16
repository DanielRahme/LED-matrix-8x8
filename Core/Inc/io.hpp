#ifndef _IO_HPP
#define _IO_HPP

#include "io.hpp"
#include "main.h"

namespace io {

  using port_t = decltype(GPIOB);

  // io constants
  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

  void write_row(int row, unsigned char value);
  void pins_default();

    struct Pin {

      constexpr Pin(port_t p = 0, uint16_t n = 0)
                    : port(p), num(n){};

      bool operator=(bool v);
      bool operator=(int v);
      void set();
      void reset();
      void write(int value);
      void toggle();

      port_t port = 0;
      uint16_t num = 0;
    };

}

#endif
