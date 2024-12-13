// temperature.c
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    // Calculate Fahrenheit using the formula
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    // Calculate Celsius using the formula
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float temp;
    float converted;

    // Display the menu options
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option (1 or 2): ");

    // Read the user's choice from the menu
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Prompt for temperature in Celsius
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);

            // Call the conversion function
            converted = celsius_to_fahrenheit(temp);
            printf("%.2f°C = %.2f°F\n", temp, converted);
            break;
        case 2:
            // Prompt for temperature in Fahrenheit
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);

            // Call the conversion function
            converted = fahrenheit_to_celsius(temp);
            printf("%.2f°F = %.2f°C\n", temp, converted);
            break;
        default:
            // Handle invalid menu choices
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}