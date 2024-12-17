#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define DDRB *(volatile uint8_t *)0x2A
#define DDRD *(volatile uint8_t *)0x2B
#define PORTB *(volatile uint8_t *)0x25
#define PORTD *(volatile uint8_t *)0x2A

// Optional: Function prototypes
void setup(void);
void loop(void);

void setup(void) {
    // Configure PB1 and PB2 as outputs
    DDRB |= (1 << DDB1) | (1 << DDB2);

    // Configure PD1 and PD2 as outputs
    DDRD |= (1 << DDD1) | (1 << DDD2);
}

void loop(void) {
    // Turn PB1 and PB2 on
    PORTB |= (1 << PORTB1) | (1 << PORTB2);

    // Turn PD1 and PD2 on
    PORTD |= (1 << PORTD1) | (1 << PORTD2);

    _delay_ms(1000); // Wait for 1 second

    // Turn PB1 and PB2 off
    PORTB &= ~((1 << PORTB1) | (1 << PORTB2));

    // Turn PD1 and PD2 off
    PORTD &= ~((1 << PORTD1) | (1 << PORTD2));

    _delay_ms(1000); // Wait for 1 second
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
    return 0;
}