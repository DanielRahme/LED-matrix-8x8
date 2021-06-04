#include "pin.hpp"
#include <nrf.h>


// Write pin (boolean)
bool Pin::operator=(bool v) 
{
  if (Pin::inverted) v = !v;
  auto port = (Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1);

  if (v)
    port->OUTSET = (1UL << Pin::num);
  else
    port->OUTCLR = (1UL << Pin::num);

  return v;
}

// Write pin, non-boolean
bool Pin::operator=(int v) 
{
  return *this = v > 0;
}

// Set pin
void Pin::set()
{
  *this = true;
}

// Reset pin
void Pin::reset() 
{
  *this = false;
}

void Pin::toggle() const {
  //HAL_GPIO_TogglePin((GPIO_TypeDef*)port, num);
}

void Pin::init() const {
  auto port = Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1;
  port->PIN_CNF[Pin::num] = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
                                (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos) |
                                (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) |
                                (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos) |
                                (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos);
}

// Read pin
Pin::operator bool() {
  //const auto state = HAL_GPIO_ReadPin((GPIO_TypeDef *)port, num);
  //return state == GPIO_PIN_SET;
}
