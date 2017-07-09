#include "led.h"

const uint16_t col[2] = {col0_Pin, col1_Pin};
const uint16_t row[2] = {Row0_Pin, Row1_Pin};

void leds_off()
{
        HAL_GPIO_WritePin(GPIOA, Row0_Pin | Row1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, col0_Pin | col1_Pin | col2_Pin | col3_Pin | col4_Pin | col5_Pin | col6_Pin | col7_Pin, GPIO_PIN_RESET);
}

void leds_on()
{
        HAL_GPIO_WritePin(GPIOA, Row0_Pin | Row1_Pin, 1);
        HAL_GPIO_WritePin(GPIOD, col0_Pin | col1_Pin | col2_Pin | col3_Pin | col4_Pin | col5_Pin | col6_Pin | col7_Pin, 1);
}

void blink()
{
        const int delay = 200;
        leds_on();
        HAL_Delay(delay);
        leds_off();
        HAL_Delay(delay);
}

void matrix()
{
        const int delay = 200;
        for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                        HAL_GPIO_WritePin(GPIOA, row[i], 1);
                        HAL_GPIO_WritePin(GPIOD, col[j], 1);
                        HAL_Delay(delay);
                        leds_off();
                }
        }
}