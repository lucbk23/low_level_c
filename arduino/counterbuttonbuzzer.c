#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Global variable to count button presses
volatile uint8_t click_count = 0;

// Function Prototypes
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
    return 0;
}

void setup()
{
    // Set PD4 as output for the LED
    // DDD4 this means 00010000 which is the same as 0x04 so when bitshifting it 
    // DDR means data-direction register. Looking at DDRD means we are setting the data direction for the D register

    DDRD |= (1 << DDD4);
    
    // Set PB0 as input for the button
    // DDDRB this means 00000001 which is the same as 0x01 so when bitshifting it
    // DDR means data-direction register. Looking at DDRB means we are setting the data direction for the B register
    // the & ~ means we are setting the bit to 0 (input) and the rest to 1 (output)
    DDRB &= ~(1 << PB0);
    
    // Turn on the internal pull-up resistor for PB0
    // The pull-up resistor is always on "high"
    // When the button is pressed, the pin is pulled to "low"
    // we do this because we want the resistor to be on high to protect the button from short circuits
    PORTB |= (1 << PB0);
    
    // Set PD5 as output for the buzzer
    DDRD |= (1 << DDD5);
    PORTD &= ~(1 << PD5); // Make sure the buzzer is off at start
    
    // Configure the external interrupt for the button
    // Set interrupt to trigger on the falling edge (button press)
    // The button is connected to INT0 (PD2)
    //EICRA is the external interrupt control register A
    //ISC01 is the interrupt sense control bit for INT0 - this is standard value as 1 which means falling edge
    EICRA |= (1 << ISC01); // ISC01 = 1
    //ISC00 is set to 0 which means rising edge, but we dont use this currently. We use the falling edge
    EICRA &= ~(1 << ISC00); // ISC00 = 0
    
    // Enable the external interrupt INT0
    //EIMSK is the external interrupt mask register
    //INT0 is the external interrupt request 0 enable bit - we set the bit to 1 to enable the interrupt
    EIMSK |= (1 << INT0);
    
    // Allow interrupts to occur
    //SET Interrupt Enable Bit in the Status Register
    sei();
}

// Interrupt Service Routine for INT0 (button press)
// INT0 is the interrupt request 0 - this is the button press
// The vector is the flag that tells us if the INT0 has been triggered to be a 1 or a 0
ISR(INT0_vect) {
    click_count++; // Increase the press count
    
    if (click_count == 3) {
        buzz(100); // Activate buzzer for 100ms on the third press
        PORTD ^= (1 << PD4); // Toggle the LED on PD4
    }
}

void loop()
{
    if (click_count == 4) {
        click_count = 0; // Reset the press count after the fourth press
    }
}

// Function to control the buzzer
void buzz(uint8_t duration_ms)
{
    uint16_t i;
    // Create a buzzing sound by toggling PD5 rapidly
    for (i = 0; i < (duration_ms * 2); i++) {
        PORTD ^= (1 << PD5); // Turn buzzer on/off
        _delay_ms(0.5);      // Short delay for buzzing sound
    }
    PORTD &= ~(1 << PD5); // Turn the buzzer off after buzzing
}