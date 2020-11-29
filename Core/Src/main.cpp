/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  * LED matrix 8x8 on STM32F3Discovery MCU board
  * COLUMS (active HIGH)  : Pins = <PB8 - PB15>
  * ROWS (active LOW)     : Pins = <PC0 - PC8>
  ******************************************************************************
  */

#define ETL_COMPILER_IAR

#include "main.h"
#include "system_clock.h"
#include "gpio.h"
#include "io.hpp"
#include "matrix.hpp"
#include "etl/array.h"
#include "display.hpp"

int main() {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  io::clear();

  auto matrix = Matrix({1, 2, 4, 8, 16, 32, 64, 128});
  constexpr auto blue1 = io::Pin(GPIOE_BASE, LD9_Pin);
  constexpr auto blue2 = io::Pin(GPIOE_BASE, LD4_Pin);

  Display disp(500);  // Delay time
  disp = matrix;      // Write to display

  while (1) {
    disp = matrix;

    blue1.toggle();
    blue2.toggle();
    Display::my_delay(1000);
  }
}
