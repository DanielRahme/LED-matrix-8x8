#ifndef _IO_HPP
#define _IO_HPP

class io {
 private:
  static constexpr int max_column = 8;
  static constexpr int max_row = 8;

 public:
  static void write_row(int row, unsigned char value);
  static void pins_default();
};

#endif
