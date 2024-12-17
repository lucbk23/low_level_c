#include <avr/io.h>
#include <util/delay.h>

void setup();
void loop();

int main()
{
    setup();
    while (1) {
        loop();
    }
    return 0;
}

void setup()
{
    DDRD |= ((1 << DDD2) | (1 << DDD3) | (1 << DDD4) | (1 << DDD5) | (1 << DDD6) | (1 << DDD7));
    DDRB |= ((1 << DDB0) | (1 << DDB1));
}

void loop()
{
    PORTD |= ((1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7));
    PORTB |= ((1 << PORTB0) | (1 << PORTB1));
    _delay_ms(1000);
    PORTD &= ~((1 << PORTD2) | (1 << PORTD3) | (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7));
    PORTB &= ~((1 << PORTB0) | (1 << PORTB1));
    _delay_ms(1000);
}