#include "pin.hpp"
#include <nrf.h>
#include <cstdint>
#include "nrf_gpio.h"

// Write pin (boolean)
bool Pin::operator=(bool v) const
{
  auto port = (Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1);

  if (v)
    port->OUTSET = (1UL << Pin::num);
  else
    port->OUTCLR = (1UL << Pin::num);

  return v;
}

// Write pin, non-boolean
bool Pin::operator=(int v) const
{
  return *this = v > 0;
}

// Set pin
void Pin::set() const
{
  *this = (this->inv == Pin::inv_t::no);
}

// Reset pin
void Pin::reset() const
{
  *this = (this->inv == Pin::inv_t::yes);
}

// Read pin
Pin::operator int()
{
  auto port = (Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1);
  volatile std::uint32_t value = port->OUT;
  return value & (1 << this->num);
}

void Pin::toggle() const
{
  auto port = (Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1);
  volatile std::uint32_t value = port->OUT;
  value = value & (1 << this->num);
  *this = !(value);
}

void Pin::init() const
{
  auto port = Pin::port == NRF_P0_BASE ? NRF_P0 : NRF_P1;
  port->PIN_CNF[Pin::num] = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
                            (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos) |
                            (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos) |
                            (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos) |
                            (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos);
}


