#ifndef _IO_HPP
#define _IO_HPP

namespace io {
  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

  void write_row(int row, unsigned char value);
  void pins_default();
}

#endif
