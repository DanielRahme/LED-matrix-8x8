
#include "io.hpp"
#include "main.h"
#include "etl/array.h"

namespace io 
{

namespace pins {

template<typename PortType>
void Pin<PortType>::set() {
  HAL_GPIO_WritePin(Pin::port, Pin::pin_num, GPIO_PIN_SET);
}

template<typename PortType>
void Pin<PortType>::reset() {
  HAL_GPIO_WritePin(Pin::port, Pin::pin_num, GPIO_PIN_RESET);
}

template <typename PortType>
void Pin<PortType>::write(int value) {
  auto bit_value = (value ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(Pin::port, Pin::pin_num, bit_value);
}

const auto R1 = Pin(ROW_1_GPIO_Port, ROW_1_Pin);
const auto R2 = Pin(ROW_2_GPIO_Port, ROW_2_Pin);
const auto R3 = Pin(ROW_3_GPIO_Port, ROW_3_Pin);
const auto R4 = Pin(ROW_4_GPIO_Port, ROW_4_Pin);
const auto R5 = Pin(ROW_5_GPIO_Port, ROW_5_Pin);
const auto R6 = Pin(ROW_6_GPIO_Port, ROW_6_Pin);
const auto R7 = Pin(ROW_7_GPIO_Port, ROW_7_Pin);
const auto R8 = Pin(ROW_8_GPIO_Port, ROW_8_Pin);
const auto C1 = Pin(COL_1_GPIO_Port, COL_1_Pin);
const auto C2 = Pin(COL_2_GPIO_Port, COL_2_Pin);
const auto C3 = Pin(COL_3_GPIO_Port, COL_3_Pin);
const auto C4 = Pin(COL_4_GPIO_Port, COL_4_Pin);
const auto C5 = Pin(COL_5_GPIO_Port, COL_5_Pin);
const auto C6 = Pin(COL_6_GPIO_Port, COL_6_Pin);
const auto C7 = Pin(COL_7_GPIO_Port, COL_7_Pin);
const auto C8 = Pin(COL_8_GPIO_Port, COL_8_Pin);

const etl::array<Pin<>, 8> pins_rows = {R1, R2, R3, R4, R5, R6, R7, R8};
const etl::array<Pin<>, 8> pins_colums = {C1, C2, C3, C4, C5, C6, C7, C8};
}  // End namespace pins

////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void write_row(int row, unsigned char value) {
  if (row < 0 || row > io::max_row)
    return;  // Boundry check, do with definition

  // Write to colums starting from leftmost one (MSB)
  for (auto col : io::pins::pins_colums) {
    col.write(value & 0b1000'0000);
    value <<= 1;
  }

  // Enable row
  //reset_pin(io::pins::pins_rows.at(row));
  auto row_enable = pins::pins_rows.at(row);
  row_enable.reset();
}

// Turn off all LEDs
void pins_default() {
  // Active low led pin, disable with high
  for (auto r : io::pins::pins_rows) {
    r.set();
  }

  for (auto c : io::pins::pins_colums) {
    c.reset();
  }
}

}  // End namespace io
