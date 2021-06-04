#ifndef _LEDS_HPP
#define _LEDS_HPP

#define ETL_NO_STL 1

#include "etl/array.h"
#include "pin.hpp"

namespace leds {

extern const etl::array<Pin, 8> x_columns;
extern const etl::array<Pin, 8> y_rows;

void init();
void test();

}

#endif