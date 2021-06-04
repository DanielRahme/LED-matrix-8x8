#ifndef _PIN_HPP
#define _PIN_HPP

struct Pin {
  int port = 0;
  int num = 0;
  int inverted = 0;

  constexpr Pin(int p = 0, int n = 0, int inv = 0) : port(p), num(n), inverted(inv) {};

  bool operator=(bool v) const;
  bool operator=(int v) const;
  explicit operator bool();

  void init() const;
  void set() const;
  void reset() const;
  void write(int value);
  void toggle() const;
};

#endif
