
#include "io.hpp"
#include "main.h"

//#include "stm32f303xc.h"

struct pin_t {
    GPIO_TypeDef* port;
    uint16_t pin_num;
};

// Constants PINS
const pin_t R1 = { ROW_1_GPIO_Port, ROW_1_Pin };
const pin_t R2 = { ROW_2_GPIO_Port, ROW_2_Pin };
const pin_t R3 = { ROW_3_GPIO_Port, ROW_3_Pin };
const pin_t R4 = { ROW_4_GPIO_Port, ROW_4_Pin };
const pin_t R5 = { ROW_5_GPIO_Port, ROW_5_Pin };
const pin_t R6 = { ROW_6_GPIO_Port, ROW_6_Pin };
const pin_t R7 = { ROW_7_GPIO_Port, ROW_7_Pin };
const pin_t R8 = { ROW_8_GPIO_Port, ROW_8_Pin };

const pin_t C1 = { COL_1_GPIO_Port, COL_1_Pin };
const pin_t C2 = { COL_2_GPIO_Port, COL_2_Pin };
const pin_t C3 = { COL_3_GPIO_Port, COL_3_Pin };
const pin_t C4 = { COL_4_GPIO_Port, COL_4_Pin };
const pin_t C5 = { COL_5_GPIO_Port, COL_5_Pin };
const pin_t C6 = { COL_6_GPIO_Port, COL_6_Pin };
const pin_t C7 = { COL_7_GPIO_Port, COL_7_Pin };
const pin_t C8 = { COL_8_GPIO_Port, COL_8_Pin };

const pin_t pins[16] = { R1, R2, R3, R4, R5, R6, R7, R8, C1, C2, C3, C4, C5, C6, C7, C8 };

void io::write_pin(io::pin p, io::state value)
{
    GPIO_PinState state = (value ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pins[p].port, pins[p].pin_num, state);
}
