#include "led_hw.h"

const uint16_t row_pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const uint16_t col_pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// Define the ports and pins for the MCU.
/*
const uint16_t row_pins[8] = {row_1_Pin, row_2_Pin, row_3_Pin, row_4_Pin, row_5_Pin, row_6_Pin, row_7_Pin, row_8_Pin};
const uint16_t col_pins[8] = {col_1_Pin, col_2_Pin, col_3_Pin, col_4_Pin, col_5_Pin, col_6_Pin, col_7_Pin, col_8_Pin};
void * row_ports[8] = {GPIOB, GPIOB, GPIOC, GPIOC, GPIOC, GPIOC, GPIOA, GPIOA};
void * col_ports[8] = {GPIOA, GPIOA, GPIOA, GPIOB, GPIOC, GPIOA, GPIOA, GPIOB};
*/
