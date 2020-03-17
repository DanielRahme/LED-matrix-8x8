#include <avr/io.h>
#include <util/delay.h>

#define PIN PIN4

template<typename T>
void set_pin(T& port, int pin) {
    port |= 1 << pin;
}

template<typename T>
void clear_pin(T& port, int pin) {
    port &= ~(1 << pin);
}

template<typename T>
void toggle_pin(T& port, int pin) {
    port ^= 1 << pin;
}

int main() {
    set_pin(DDRD, PIN);

    while(1){
        toggle_pin(PORTD, PIN);
        _delay_ms(1000);
    }
}

