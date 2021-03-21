#ifndef _PIXEL_HPP
#define _PIXEL_HPP

#include "pin.hpp"
#include "main.h"
#include "etl/array.h"

namespace pixel {

// Datatypes


// Matrix dimensions constants
static constexpr auto max_column = 8;
static constexpr auto max_row = 8;

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

// Public functions
void write_row(int row, unsigned char value);  // Remove later
void clear();

} // End namespace io

#endif
