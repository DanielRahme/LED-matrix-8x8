#include "leds.hpp"
#include "nrf.h"

namespace leds {

// Constants

// Columns = x and Rows = y
static constexpr int x0_port = NRF_P1_BASE;
static constexpr int x1_port = NRF_P1_BASE;
static constexpr int x2_port = NRF_P1_BASE;
static constexpr int x3_port = NRF_P1_BASE;
static constexpr int x4_port = NRF_P1_BASE;
static constexpr int x5_port = NRF_P0_BASE;
static constexpr int x6_port = NRF_P0_BASE;
static constexpr int x7_port = NRF_P0_BASE;
static constexpr int y0_port = NRF_P1_BASE;
static constexpr int y1_port = NRF_P1_BASE;
static constexpr int y2_port = NRF_P1_BASE;
static constexpr int y3_port = NRF_P1_BASE;
static constexpr int y4_port = NRF_P1_BASE;
static constexpr int y5_port = NRF_P1_BASE;
static constexpr int y6_port = NRF_P1_BASE;
static constexpr int y7_port = NRF_P1_BASE;

static constexpr int x0_num = 11;
static constexpr int x1_num = 12;
static constexpr int x2_num = 13;
static constexpr int x3_num = 14;
static constexpr int x4_num = 15;
static constexpr int x5_num = 2;
static constexpr int x6_num = 26;
static constexpr int x7_num = 27;
static constexpr int y0_num = 10;
static constexpr int y1_num = 8;
static constexpr int y2_num = 7;
static constexpr int y3_num = 6;
static constexpr int y4_num = 5;
static constexpr int y5_num = 4;
static constexpr int y6_num = 3;
static constexpr int y7_num = 2;

constexpr etl::array<Pin, 8> x_columns = {
    Pin(x0_port, x0_num, Pin::inv_t::no),
    Pin(x1_port, x1_num, Pin::inv_t::no),
    Pin(x2_port, x2_num, Pin::inv_t::no),
    Pin(x3_port, x3_num, Pin::inv_t::no),
    Pin(x4_port, x4_num, Pin::inv_t::no),
    Pin(x5_port, x5_num, Pin::inv_t::no),
    Pin(x6_port, x6_num, Pin::inv_t::no),
    Pin(x7_port, x7_num, Pin::inv_t::no)};

constexpr etl::array<Pin, 8> y_rows = {
    Pin(y0_port, y0_num, Pin::inv_t::yes),
    Pin(y1_port, y1_num, Pin::inv_t::yes),
    Pin(y2_port, y2_num, Pin::inv_t::yes),
    Pin(y3_port, y3_num, Pin::inv_t::yes),
    Pin(y4_port, y4_num, Pin::inv_t::yes),
    Pin(y5_port, y5_num, Pin::inv_t::yes),
    Pin(y6_port, y6_num, Pin::inv_t::yes),
    Pin(y7_port, y7_num, Pin::inv_t::yes)};


// Functions
void init()
{
  // Init pins
  for (auto col : leds::x_columns) col.init();
  for (auto row : leds::y_rows) row.init();
  // Zero out pins
  for (auto col : leds::x_columns) col.reset();
  for (auto row : leds::y_rows) row.reset();
}

void test()
{
  for (auto y : leds::y_rows) {
    y.set();

    // Set all columns, one-by-one
    for (auto x : leds::x_columns) {
      x.set();
      for (volatile unsigned long long j = 0; j < 100000UL; ++j)
        ; // Delay
    }

    y.reset();
    for (auto col : leds::x_columns)
      col.reset();    // Reset all columns
  }
}

void write_row(const int row, std::uint8_t value)
{
  int idx = 7;

  while (value) {
    if (value & 1) 
      x_columns[idx].set();

    --idx;
    value >>= 1;
  }
  y_rows[row].set();
}

void reset_rows()
{
  for (auto y : y_rows)
    y.reset();

}

void reset_columns()
{
  for (auto x : x_columns)
    x.reset();
}

void reset()
{
  reset_rows();
  reset_columns();
}

} // End namespace leds