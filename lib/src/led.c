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

void row_sw_off()
{
	for (int i = 0; i < ROWS; i++) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 1);

	}
}

struct Pattern inv_pat(const struct Pattern p)
{
	struct Pattern p_inv;
	p_inv.delay = 1;
	for (int i = 0; i < ROWS; i++) {
		p_inv.pattern[i] = ~p.pattern[i];
	}
	return p_inv;
}

void row_scroll_down(const uint8_t row, const uint32_t delay_ms)
{
	write_row(row);
	for (int i = 0; i < COLS; i++) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 0);
		HAL_Delay(delay_ms);
		row_sw_off();
	}

}

void row_scroll_up(const uint8_t row, const uint32_t delay_ms)
{
	write_row(row);
	for (int i = COLS-1; i >= 0; i--) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 0);
		HAL_Delay(delay_ms);
		row_sw_off();
	}
}

void col_scroll_right(const uint32_t delay_ms)
{
	uint8_t pos = 0x80;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < delay_ms; j++) {
			row_scroll_down(pos, 1);
		}
		pos >>= 1;
	}
}

void col_scroll_left(const uint32_t delay_ms)
{
	uint8_t pos = 0x01;
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < delay_ms; j++) {
			row_scroll_down(pos, 0);
		}
		pos <<= 1;
	}
}

void blink(const uint32_t delay)
{
	leds_on();
	HAL_Delay(delay);
	leds_off();
	HAL_Delay(delay);
}


void pattern(const struct Pattern p)
{
	for (int i = 0; i < ROWS; i++) {
		HAL_GPIO_WritePin(row_ports[i], row_pins[i], 0);
		write_row(p.pattern[i]);
		HAL_Delay(p.delay);
		leds_off();
	}
}

void disp_pattern(const struct Pattern p, const uint32_t duration)
{
	for (int i = 0; i < duration; i++) {
		pattern(p);
	}
}

void animate(uint16_t num_of_patterns, ...)
{
	va_list pat_list;
	va_start(pat_list, num_of_patterns);

	for (int i = 0; i < num_of_patterns; i++) {
		struct Pattern p = va_arg(pat_list, struct Pattern);
		disp_pattern(p, 10);
	}
	va_end(pat_list);
}
/*
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








