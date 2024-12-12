#include <avr/io.h>
#include <stdio.h>

#define DDRD *(volatile unsigned char *)0x2A
#define PORTD *(volatile unsigned char *)0x2B

void wait(){
    for (volatile long i = 0; i < 1000000; i++);
    {
        = i;
    }
}

void setup(){
    DDRD = 0xFF;
    DDRB = _BV(5);
}
void loop(){

}

void outchar(char c){
    PORTD = c;
}


int main() {
    setup();

    char word[] = "Hello World!";

    int i = 0;

    while(word[i]){
        PORTB |= _BV(5);
        outchar(word[i]);
        i++;
        wait();
        PORTB &= ~_BV(5);
        wait();
    }

    return 0;
}