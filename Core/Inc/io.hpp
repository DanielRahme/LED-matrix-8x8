#ifndef _IO_HPP
#define _IO_HPP

class io {

public:
    enum state {
        high = 1,
        low = 0
    };

    enum pin {
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

    // Functions
    static void write_pin(pin p, state value);
    static void set_pin(pin p);
    static void reset_pin(pin p);
    static void write_row(pin row, unsigned char value);
    static void pins_default();
};

#endif
