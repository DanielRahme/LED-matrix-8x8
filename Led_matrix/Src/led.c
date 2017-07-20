#include "led.h"

#define ROWS 2 //change to 8 when matrix hw is done
#define COLS 8

const uint16_t col_pins[2] = {col0_Pin, col1_Pin};
const uint16_t row_pins[2] = {Row0_Pin, Row1_Pin};

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

void blink(const uint32_t delay)
{
        leds_on();
        HAL_Delay(delay);
        leds_off();
        HAL_Delay(delay);
}

void matrix_test(const uint32_t delay)
{
        for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                        HAL_GPIO_WritePin(GPIOA, row_pins[i], 1);
                        HAL_GPIO_WritePin(GPIOD, col_pins[j], 1);
                        HAL_Delay(delay);
                        leds_off();
                }
        }
}


void disp_pattern(const struct Pattern p)
{
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        bool enable = (p.pattern[i] >> 7-j) & 0x1;
                        HAL_GPIO_WritePin(GPIOA, row_pins[i], enable);
                        HAL_GPIO_WritePin(GPIOD, col_pins[j], enable);
                        HAL_Delay(p.delay);
                }
        }
}



void disp_animation_ptr(struct Animation *a, const int loops)
{
        for (int i = 0; i < a->length; i++) {
                for (int j = 0; j < loops; j++) {
			disp_pattern(a->patterns[i]);
			HAL_Delay(a->patterns[i].delay);
			leds_off();
	        }
        }
}



