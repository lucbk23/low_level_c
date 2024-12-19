#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Global variables


// Function prototypes
void setup();
void loop();
void buzz(uint8_t duration_ms);

int main()
{
    setup(); // Initialize settings
    while (1)
    {
        loop(); // Continuously run the main loop
    }
}

// avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000UL itsbinfun.c -o itsbinfun.elf *udskift itsbinfun.c med filnavnet*

// avr-objcopy -O ihex itsbinfun.elf itsbinfun.hex *udskift itsbinfun.c med filnavnet*

// avrdude -c arduino -p m328p -P /dev/tty.usbserial-BG000IJ7 -b 57600 -D -U flash:w:itsbinfun.hex:i *udskift itsbinfun.c med filnavnet*
//DOBBELTJEK USB PORTEN