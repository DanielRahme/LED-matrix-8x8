#include "pin.hpp"
#include "main.h"
#include "etl/array.h"

// struct Pin methods and operators
bool Pin::operator=(bool v) {
  if (this->inverted) v = !v;
  auto bit_value = (v ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_GPIO_WritePin((GPIO_TypeDef*)this->port, this->num, bit_value);
  return v;
}

bool Pin::operator=(int v) {
  return *this = v > 0;
}

void Pin::set() {
  *this = true;
}

void Pin::reset() {
  *this = false;
}

void Pin::toggle() const {
  HAL_GPIO_TogglePin((GPIO_TypeDef*)port, num);
}

Pin::operator bool() {
  const auto state = HAL_GPIO_ReadPin((GPIO_TypeDef *)port, num);
  return state == GPIO_PIN_SET;
}
