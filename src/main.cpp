#include <avr/io.h>
#include <util/delay.h>


int main() {
    auto toggle = [](auto pin){
        DDRD |= 1 << pin;
        PORTD ^= 1 << pin;
    };


    while(1){
        toggle(PIN4);
        _delay_ms(2000);
    }
}

