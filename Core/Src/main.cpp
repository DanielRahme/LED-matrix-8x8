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
#include "pin.hpp"
#include "matrix.hpp"
#include "etl/array.h"
#include "display.hpp"
#include "pattern.hpp"

void error() {
  constexpr auto blue1 = Pin(GPIOE_BASE, LD9_Pin);
  constexpr auto blue2 = Pin(GPIOE_BASE, LD4_Pin);
  while (true) {
    blue1.toggle();
    blue2.toggle();
    Display::my_delay(1000);
  }
}

int main() {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  io::clear();

  constexpr auto refresh_rate = 12;
  Display disp(refresh_rate);  // Delay time

  disp = pattern::square_max_h;

  const auto duration = 4;

  while (true) {

    for (auto i = 0; i < io::max_column+1; i++) {
      const auto sqr = pattern::square(i);

      for (unsigned long j = 0; j < duration; j++) {
        disp = sqr;
      }
    }

  }

  error(); // Should never reach here
}
