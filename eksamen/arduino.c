#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Global variables
#define LED_D5 PD5
#define LED_D4 PD4
#define LED_D3 PD3
#define BUTTON_D2 PD2

// Function prototypes
void setup();
void loop();
void timer1_init();

volatile uint8_t button_pressed = 0;
volatile unsigned long timer_ms = 0;
volatile uint8_t timer_expired = 0;

typedef enum {
    LEDS_ON,
    LEDS_BLINKING,
    LEDS_OFF
} SystemState;

volatile SystemState current_state = LEDS_ON;


int main()
{
    setup(); // Initialize settings
    while (1)
    {
        loop(); // Continuously run the main loop
    }
}

void setup()
    {
DDRD |= (1 << LED_D5) | (1 << LED_D4) | (1 << LED_D3);

DDRD &= ~(1 << BUTTON_D2);

PORTD |= (1 << BUTTON_D2);

EICRA |= (1 << ISC01);
EICRA &= ~(1 << ISC00);

EIMSK |= (1 << INT0);

timer1_init();

sei();
    };

void timer1_init()
{
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS11) | (1 << CS10);
    OCR1A = 249;
    TIMSK1 |= (1 << OCIE1A);


}

ISR(TIMER1_COMPA_vect)
{
    timer_ms++;
    if(timer_ms >= 10000)
    {
        timer_expired = 1;
        timer_ms = 0;
        current_state = LEDS_BLINKING;
    }
}

ISR(INT0_vect)
 {
        button_pressed = 1; 
        timer_ms = 0;
 }

void loop()
{
if(current_state == LEDS_BLINKING)
{
    for (int i = 0; i < 3; i++)
    {
         PORTD &= ~((1 << LED_D3) | (1 << LED_D4) | (1 << LED_D5));
        _delay_ms(250);
        PORTD |= (1 << LED_D3) | (1 << LED_D4) | (1 << LED_D5);
        _delay_ms(250);

    }
    PORTD &= ~((1 << LED_D3) | (1 << LED_D4) | (1 << LED_D5));
    current_state = LEDS_OFF;
    _delay_ms(500);
}
    

PORTD |= (1 << LED_D3);
_delay_ms(1000);
PORTD |= (1 << LED_D4);
_delay_ms(1000);
PORTD |= (1 << LED_D5);
_delay_ms(500);


if(button_pressed)
{
    PORTD &= ~((1 << LED_D3) | (1 << LED_D4) | (1 << LED_D5));
    button_pressed = 0;
}
_delay_ms(1000);
}




// avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000UL itsbinfun.c -o itsbinfun.elf *udskift itsbinfun.c med filnavnet*

// avr-objcopy -O ihex itsbinfun.elf itsbinfun.hex *udskift itsbinfun.c med filnavnet*

// avrdude -c arduino -p m328p -P /dev/tty.usbserial-BG000IJ7 -b 57600 -D -U flash:w:itsbinfun.hex:i *udskift itsbinfun.c med filnavnet*
//DOBBELTJEK USB PORTEN