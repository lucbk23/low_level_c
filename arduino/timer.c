#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

void setup();
void loop();

int main()
{
    setup();
    while (1)
    {
        loop();
    }

    return 0;
}

void setup()
{
    // cli stands for clear interrupt flag
    cli();

    // Set CTC (Clear Timer on Compare Match) mode
    TCCR1B |= (1 << WGM12);

    // Set normal port operation
    TCCR1A = 0;


    // Set prescaler to 1024
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // Enabling interrupt on compare match
    TIMSK1 |= (1 << OCIE1A);

    // Set pin 1 as output and turn it on.
    DDRB |= (1 << DDB1);
    PORTB &= ~(1 << PORTB1);

    // Set OC1A on compare match
    // TCCR1A |= (1 << COM1A1) | (1 << COM1B1); 
    //Set the compare value
    OCR1A = 15624;

    // sei stands for set interrupt flag
    sei();

}


ISR(TIMER1_COMPA_vect) {
    static int counter;
    counter++;

    if (counter == 10) {
        PORTB |= (1 << PORTB1);
    } else if (counter == 20) {
        PORTB &= ~(1 << PORTB1);
        counter = 0;
    }
}

void loop()
{

}