#ifndef _IO_HPP
#define _IO_HPP

#define HIGH 1
#define LOW  0

namespace io {

enum Pin {
    R_1 = 0,
    R_2 = 1,
    R_3 = 2,
    R_4 = 3,
    R_5 = 4,
    R_6 = 5,
    R_7 = 6,
    R_8 = 7,
    C_1 = 8,
    C_2 = 9,
    C_3 = 10,
    C_4 = 11,
    C_5 = 12,
    C_6 = 13,
    C_7 = 14,
    C_8 = 15
};

void write_pin(Pin pin, int value);

} // End namespace

#endif
