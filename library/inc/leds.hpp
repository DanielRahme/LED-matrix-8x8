#ifndef _LEDS_HPP
#define _LEDS_HPP

#define ETL_NO_STL 1

#include "etl/array.h"
#include "pin.hpp"
#include <cstdint>

namespace leds {

extern const etl::array<Pin, 8> x_columns;
extern const etl::array<Pin, 8> y_rows;

void init();
void write_row(const int row, std::uint8_t value);
void write_row(const int row, const std::uint8_t prev_value, const std::uint8_t next_value);
void reset_rows();
void reset_columns();
void reset();

void test();
void toggle_test_columns();
void toggle_test_rows();

}

#endif