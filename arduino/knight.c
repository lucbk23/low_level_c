#include <avr/io.h>
#include <avr/iom328p.h>
#include <util/delay.h>
#include <stdio.h>

// Define LED pins
#define LED1 PD2
#define LED2 PD3
#define LED3 PD4

void setup();
void loop();

int main(void)
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
    // Set PD2, PD3, PD4 as output
    DDRD |= (1 << LED1) | (1 << LED2) | (1 << LED3);
}

void loop()
{
    static uint8_t current_led = LED1;
    static int direction = 1; // 1 for forward, -1 for backward

    // Turn on the current LED
    PORTD |= (1 << current_led);
    _delay_ms(500); // Adjust delay as needed

    // Turn off the current LED
    PORTD &= ~(1 << current_led);

    // Update the current LED based on direction
    current_led += direction;

    // Reverse direction at the ends
    if (current_led == LED3) {
        direction = -1;
    } else if (current_led == LED1) {
        direction = 1;
    }
}