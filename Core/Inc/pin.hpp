#ifndef _PIN_HPP
#define _PIN_HPP

struct Pin {
  constexpr Pin(int p = 0, int n = 0, int inv = 0) : port(p), num(n), inverted(inv) {};

  bool operator=(bool v);
  bool operator=(int v);
  explicit operator bool();

  void set();
  void reset();
  void write(int value);
  void toggle() const;

  int port = 0;
  int num = 0;
  int inverted = 0;
};

#endif
