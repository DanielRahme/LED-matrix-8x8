#ifndef _PIN_HPP
#define _PIN_HPP

struct Pin
{
  enum class inv_t {
    no,
    yes
  };

  // Members
  int port = 0;
  int num = 0;
  inv_t inv = inv_t::no;

  constexpr Pin(int p = 0, int n = 0, inv_t i = inv_t::no) : port(p), num(n), inv(i){};

  // Overload functions
  bool operator=(bool v) const;
  bool operator=(int v) const;
  explicit operator bool();

  // Functions
  void init() const;
  void set() const;
  void reset() const;
  void write(int value);
  void toggle() const;
};

#endif
