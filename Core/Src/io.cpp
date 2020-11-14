
#include "io.hpp"
#include "main.h"
#include "etl/array.h"

//#include "stm32f303xc.h"

// using pin = io:pin::pin_t<decltype(ROW_1_GPIO_Port)>;  // Define pin. Use the
// port type here

namespace io 
{

namespace pins {

// using pin = io::pins::pin_t<decltype(ROW_1_GPIO_Port)>;

template<typename PortType>
void pin_t<PortType>::set() {
  HAL_GPIO_WritePin(pin_t::port, pin_t::pin_num, GPIO_PIN_SET);
}

template<typename PortType>
void pin_t<PortType>::reset() {
  HAL_GPIO_WritePin(pin_t::port, pin_t::pin_num, GPIO_PIN_RESET);
}

using pin = io::pins::pin_t<>;  // io::pins::pin_t<decltype(ROW_1_GPIO_Port)>;
constexpr pin R1 = {ROW_1_GPIO_Port, ROW_1_Pin};
constexpr pin R2 = {ROW_2_GPIO_Port, ROW_2_Pin};
constexpr pin R3 = {ROW_3_GPIO_Port, ROW_3_Pin};
constexpr pin R4 = {ROW_4_GPIO_Port, ROW_4_Pin};
constexpr pin R5 = {ROW_5_GPIO_Port, ROW_5_Pin};
constexpr pin R6 = {ROW_6_GPIO_Port, ROW_6_Pin};
constexpr pin R7 = {ROW_7_GPIO_Port, ROW_7_Pin};
constexpr pin R8 = {ROW_8_GPIO_Port, ROW_8_Pin};
constexpr pin C1 = {COL_1_GPIO_Port, COL_1_Pin};
constexpr pin C2 = {COL_2_GPIO_Port, COL_2_Pin};
constexpr pin C3 = {COL_3_GPIO_Port, COL_3_Pin};
constexpr pin C4 = {COL_4_GPIO_Port, COL_4_Pin};
constexpr pin C5 = {COL_5_GPIO_Port, COL_5_Pin};
constexpr pin C6 = {COL_6_GPIO_Port, COL_6_Pin};
constexpr pin C7 = {COL_7_GPIO_Port, COL_7_Pin};
constexpr pin C8 = {COL_8_GPIO_Port, COL_8_Pin};

constexpr etl::array<pin, 8> pins_rows = {R1, R2, R3, R4, R5, R6, R7, R8};
constexpr etl::array<pin, 8> pins_colums = {C1, C2, C3, C4, C5, C6, C7, C8};


}  // End namespace pinso

void set_pin(const io::pins::pin p) {
  HAL_GPIO_WritePin(p.port, p.pin_num, GPIO_PIN_SET);
}

void reset_pin(const io::pins::pin p) {
  HAL_GPIO_WritePin(p.port, p.pin_num, GPIO_PIN_RESET);
}

void write_pin(const io::pins::pin p, int value) {
  HAL_GPIO_WritePin(p.port, p.pin_num,
                    static_cast<decltype(GPIO_PIN_RESET)>(value));
}

////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void write_row(int row, unsigned char value) {
  if (row < 0 || row > io::max_row)
    return;  // Boundry check, do with definition

  // Write to colums starting from leftmost one (MSB)
  for (auto col : io::pins::pins_colums) {
    write_pin(col, value & 0b1000'0000);
    value <<= 1;
  }

  // Enable row
  reset_pin(io::pins::pins_rows.at(row));
}

// Turn off all LEDs
void pins_default() {
  // Active low led pin, disable with high
  for (auto r : io::pins::pins_rows) {
    // set_pin(r);
    r.set();
  }

  for (auto c : io::pins::pins_colums) {
    // reset_pin(c);
    c.reset();
  }
}

}  // End namespace io
