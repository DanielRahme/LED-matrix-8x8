#ifndef _IO_HPP
#define _IO_HPP

#include "io.hpp"
#include "main.h"
namespace io {

  // io constants
  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

  void write_row(int row, unsigned char value);
  void pins_default();

  namespace pins
  {                        
    
    // ROW_1_GPIO_port of type = GPIO_TypeDef* port;
    template <typename PortType = decltype(ROW_1_GPIO_Port)>
    struct pin_t {
      PortType port;
      int pin_num;

      void set();
      void reset();
      void write(int value);
      //void toggle();
    };

  }

}

#endif
