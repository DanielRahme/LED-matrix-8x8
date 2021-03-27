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
#include "pixel.hpp"
#include "pin.hpp"
#include "display.hpp"
#include "create_pattern.hpp"
#include "pattern.hpp"
#include "animation.hpp"



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
  pixel::clear();

  constexpr auto refresh_rate = 12;
  Display disp(refresh_rate);  // Delay time


  // Generate a growing square
  auto square_patterns = [](){
    std::array<Pattern, 8> patterns = {};
    auto x = 1;
    for (auto& p : patterns)
      p = Pattern(create_pattern::square(x++));
    return patterns;
  }();

  const auto clip_1 = Animation(square_patterns, 10);

  while (true) {
    disp = clip_1;
  }
}
