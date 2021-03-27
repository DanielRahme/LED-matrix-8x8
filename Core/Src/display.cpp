
#include "display.hpp"
#include <array>
#include "pin.hpp"
#include "main.h"

using pins_t = std::array<Pin, 8>;
constexpr auto MAX_COLUMS = 8;
constexpr auto MAX_ROWS   = 8;

constexpr auto R1 = Pin(GPIOC_BASE, ROW_1_Pin, 1);
constexpr auto R2 = Pin(GPIOC_BASE, ROW_2_Pin, 1);
constexpr auto R3 = Pin(GPIOC_BASE, ROW_3_Pin, 1);
constexpr auto R4 = Pin(GPIOC_BASE, ROW_4_Pin, 1);
constexpr auto R5 = Pin(GPIOC_BASE, ROW_5_Pin, 1);
constexpr auto R6 = Pin(GPIOC_BASE, ROW_6_Pin, 1);
constexpr auto R7 = Pin(GPIOC_BASE, ROW_7_Pin, 1);
constexpr auto R8 = Pin(GPIOC_BASE, ROW_8_Pin, 1);
constexpr auto C1 = Pin(GPIOB_BASE, COL_1_Pin);
constexpr auto C2 = Pin(GPIOB_BASE, COL_2_Pin);
constexpr auto C3 = Pin(GPIOB_BASE, COL_3_Pin);
constexpr auto C4 = Pin(GPIOB_BASE, COL_4_Pin);
constexpr auto C5 = Pin(GPIOB_BASE, COL_5_Pin);
constexpr auto C6 = Pin(GPIOB_BASE, COL_6_Pin);
constexpr auto C7 = Pin(GPIOB_BASE, COL_7_Pin);
constexpr auto C8 = Pin(GPIOB_BASE, COL_8_Pin);

// Pins
pins_t rows = {R1, R2, R3, R4, R5, R6, R7, R8};
pins_t colums = {C1, C2, C3, C4, C5, C6, C7, C8};

void reset_leds()
{
  for (auto row : rows)
    row.reset();

  for (auto col : colums)
    col.reset();
}

void update_anim(Animation a) {
  auto [patterns, frame_time] = a;

  auto write_row = [](auto row_idx, auto value){
    reset_leds();

    for (auto i = 0; i < colums.size(); i++) {
      colums[i] = value[i];
    }
    // Enable row
    rows.at(row_idx).set();
  };

  auto write_to_disp = [&](auto frame){
    for (auto i = 0; i < MAX_ROWS; i++) {
      write_row(i, frame[i]);
    }
  };

  // Write frame-by-frame with a duration time
  for (auto frame : patterns) {
    for(auto i = 0; i < frame_time; i++)
      write_to_disp(frame.pattern);
  }
}


void Display::operator=(Animation a) { 
  update_anim(a);
}


void Display::my_delay(uint32_t delay) {
  for (volatile auto i = 0; i < delay; i++)
    for (volatile auto j = 0; j < delay; j++)
      ;
}
