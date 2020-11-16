
#include "io.hpp"
#include "main.h"
#include "etl/array.h"

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000UL)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400UL)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800UL)


namespace io 
{
// struct Pin methods and operators
bool Pin::operator=(bool v) {
  auto bit_value = (v ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin((GPIO_TypeDef*)Pin::port, Pin::num, bit_value);
  return v;
}

bool Pin::operator=(int v) {
  return *this = v > 0;
}

void Pin::set() {
  *this = true;
}

void Pin::reset() {
  *this = false;
}

void Pin::toggle() {
  HAL_GPIO_TogglePin((GPIO_TypeDef*)Pin::port, Pin::num);
}

// Constants of used GPIO Pins
constexpr auto R1 = Pin(GPIOC_BASE, ROW_1_Pin);
constexpr auto R2 = Pin(GPIOC_BASE, ROW_2_Pin);
constexpr auto R3 = Pin(GPIOC_BASE, ROW_3_Pin);
constexpr auto R4 = Pin(GPIOC_BASE, ROW_4_Pin);
constexpr auto R5 = Pin(GPIOC_BASE, ROW_5_Pin);
constexpr auto R6 = Pin(GPIOC_BASE, ROW_6_Pin);
constexpr auto R7 = Pin(GPIOC_BASE, ROW_7_Pin);
constexpr auto R8 = Pin(GPIOC_BASE, ROW_8_Pin);
constexpr auto C1 = Pin(GPIOB_BASE, COL_1_Pin);
constexpr auto C2 = Pin(GPIOB_BASE, COL_2_Pin);
constexpr auto C3 = Pin(GPIOB_BASE, COL_3_Pin);
constexpr auto C4 = Pin(GPIOB_BASE, COL_4_Pin);
constexpr auto C5 = Pin(GPIOB_BASE, COL_5_Pin);
constexpr auto C6 = Pin(GPIOB_BASE, COL_6_Pin);
constexpr auto C7 = Pin(GPIOB_BASE, COL_7_Pin);
constexpr auto C8 = Pin(GPIOB_BASE, COL_8_Pin);

constexpr etl::array<Pin, 8> pins_rows = {R1, R2, R3, R4, R5, R6, R7, R8};
constexpr etl::array<Pin, 8> pins_colums = {C1, C2, C3, C4, C5, C6, C7, C8};

////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void write_row(int row, unsigned char value) {
  if (row < 0 || row > io::max_row)
    return;  // Boundry check, do with definition

  // Write to colums starting from leftmost one (MSB)
  for (auto col : io::pins_colums) {
    col = value & 0b1000'0000;
    value <<= 1;
  }

  // Enable row (active low)
  auto row_to_enable = io::pins_rows.at(row);
  row_to_enable.reset();
}

// Turn off all LEDs
void pins_default() {
  // Active low led pin, disable with high
  for (auto r : io::pins_rows) {
    r.set();
  }

  for (auto c : io::pins_colums) {
    c.reset();
  }
}

}  // End namespace io
