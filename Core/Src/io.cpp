
#include "io.hpp"
#include "main.h"
#include "etl/array.h"

//#include "stm32f303xc.h"

typedef io::pin_t<decltype(ROW_1_GPIO_Port)> pin;


// Constants PINS
constexpr pin R1 = {ROW_1_GPIO_Port, ROW_1_Pin};
constexpr pin R2 = {ROW_2_GPIO_Port, ROW_2_Pin};
constexpr pin R3 = {ROW_3_GPIO_Port, ROW_3_Pin};
constexpr pin R4 = {ROW_4_GPIO_Port, ROW_4_Pin};
constexpr pin R5 = {ROW_5_GPIO_Port, ROW_5_Pin};
constexpr pin R6 = {ROW_6_GPIO_Port, ROW_6_Pin};
constexpr pin R7 = {ROW_7_GPIO_Port, ROW_7_Pin};
constexpr pin R8 = {ROW_8_GPIO_Port, ROW_8_Pin};
constexpr pin C1 = {COL_1_GPIO_Port, COL_1_Pin};
constexpr pin C2 = {COL_2_GPIO_Port, COL_2_Pin};
constexpr pin C3 = {COL_3_GPIO_Port, COL_3_Pin};
constexpr pin C4 = {COL_4_GPIO_Port, COL_4_Pin};
constexpr pin C5 = {COL_5_GPIO_Port, COL_5_Pin};
constexpr pin C6 = {COL_6_GPIO_Port, COL_6_Pin};
constexpr pin C7 = {COL_7_GPIO_Port, COL_7_Pin};
constexpr pin C8 = {COL_8_GPIO_Port, COL_8_Pin};

//constexpr pin pins[16] = { R1, R2, R3, R4, R5, R6, R7, R8, C1, C2, C3, C4, C5, C6, C7, C8 };
constexpr etl::array<pin, 8> pins_rows = {R1, R2, R3, R4, R5, R6, R7, R8}; 
constexpr etl::array<pin, 8> pins_colums = {C1, C2, C3, C4, C5, C6, C7, C8}; 


void set_pin(const pin p)
{
    HAL_GPIO_WritePin(p.port, p.pin_num, GPIO_PIN_SET);
}

void reset_pin(const pin p)
{
    HAL_GPIO_WritePin(p.port, p.pin_num, GPIO_PIN_RESET);
}


////////////////////////////////////////////////////////////////////////////////
// Public funtions
////////////////////////////////////////////////////////////////////////////////
void io::write_row(int row, unsigned char value)
{
    // Boundry check, do with definition
    if (row < 0 || row > io::max_row) return;

    // Write colums. Start from MSB column
    int current_column = 7;
    while (value) {
        if (value & 1) {
            set_pin(pins_colums.at(current_column));
        }
        else {
            reset_pin(pins_colums.at(current_column));
        }
        value >>= 1;
        current_column--;
    }

    // Enable row
    reset_pin(pins_rows.at(row));
}


// Turn off all LEDs
void io::pins_default()
{
    for (auto r : pins_rows) {
        set_pin(r);
    }

    for (auto c : pins_colums) {
        reset_pin(c);
    }
}
