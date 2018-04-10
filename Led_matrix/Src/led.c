#include "led.h"

#define ROWS 8 //change to 8 when matrix hw is done
#define COLS 8

void write_row(const uint8_t row)
{
	for (int i = 0; i < COLS; i++) {
		int state = row & (1 << (COLS - 1 - i));
		HAL_GPIO_WritePin(col_ports[i], col_pins[i], state);
	}
}

void leds_off()
{
	for (int i = 0; i < ROWS; i++) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 1);
		HAL_GPIO_WritePin(col_ports[i], col_pins[i], 0);

	}
}

void leds_on()
{
	for (int i = 0; i < ROWS; i++) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 0);
		HAL_GPIO_WritePin(col_ports[i], col_pins[i], 1);

	}
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
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			HAL_GPIO_WritePin(GPIOA, row_pins[i], 1);
			HAL_GPIO_WritePin(GPIOD, col_pins[j], 1);
			HAL_Delay(delay);
			leds_off();
		}
	}
}

/*
void disp_pattern(const struct Pattern p)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			bool enable = (p.pattern[i] >> 7-j) & 0x1;
			HAL_GPIO_WritePin(GPIOA, row_pins[i], enable);
			HAL_GPIO_WritePin(GPIOD, col_pins[j], enable);
			HAL_Delay(p.delay);
		}
		leds_off();
	}
}

void print_row(const uint8_t row)
{
	if (!row) {
		printf(". . . . . . . .");
		return;
	}


	for (int i = 0; i < ROWS; i++) {	
		bool enable = (row >> 7-i) & 0x1;
		printf(enable ? " #" : " .");
	}
}


void print_pattern(const struct Pattern p)
{
	for (int i = 0; i < ROWS; i++) {
		print_row(p.pattern[i]);
		printf("\n");
	}
}
*/








