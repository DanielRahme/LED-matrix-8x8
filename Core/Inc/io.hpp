#ifndef _IO_HPP
#define _IO_HPP

#include "io.hpp"
#include "main.h"
namespace io {

  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

  namespace pins
  {
    template <typename PortType = decltype(ROW_1_GPIO_Port)>
    struct pin_t {
      PortType port;                        // GPIO_TypeDef* port;
      int pin_num;

      void set();
      void reset();
      //void toggle();
    };

  }

  void write_row(int row, unsigned char value);
  void pins_default();
}

#endif
