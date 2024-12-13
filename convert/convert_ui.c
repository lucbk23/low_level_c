#include <stdio.h>
#include <stdlib.h> // For exit()
#include <ctype.h>  // For isdigit()
#include <string.h> // For memset()
#include "convert_ui.h"
#include "temperature.h"
#include "distance.h"
#include "currency.h"

// Function prototypes for input handling
int get_valid_int();
float get_valid_float();

void start_converter() {
    int main_choice;

    while (1) {
        // Display the main menu options
        printf("General Converter\n");
        printf("1. Temperature Conversion\n");
        printf("2. Distance Conversion\n");
        printf("3. Currency Conversion\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");

        // Read the user's choice
        main_choice = get_valid_int();

        // Handle the user's choice using a switch statement
        switch (main_choice) {
            case 1:
                temperature_menu();
                break;
            case 2:
                distance_menu();
                break;
            case 3:
                currency_menu();
                break;
            case 4:
                printf("Exiting the converter.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}

// Function to safely read an integer from user input
int get_valid_int() {
    int value;
    char ch;
    while (1) {
        if (scanf("%d", &value) == 1) {
            // Successfully read an integer
            // Clear any remaining characters on the line
            while ((ch = getchar()) != '\n' && ch != EOF);
            return value;
        } else {
            // Failed to read an integer, clear the invalid input
            printf("Invalid input. Please enter a number: ");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

// Function to safely read a float from user input
float get_valid_float() {
    float value;
    char ch;
    while (1) {
        if (scanf("%f", &value) == 1) {
            // Successfully read a float
            // Clear any remaining characters on the line
            while ((ch = getchar()) != '\n' && ch != EOF);
            return value;
        } else {
            // Failed to read a float, clear the invalid input
            printf("Invalid input. Please enter a valid number: ");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

// Handles the temperature conversion menu
void temperature_menu() {
    int choice;
    float temp, converted;

    // Display temperature conversion options
    printf("\nTemperature Conversion\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option (1 or 2): ");

    // Read the user's choice
    choice = get_valid_int();

    if (choice == 1) {
        // Prompt for temperature in Celsius
        printf("Enter temperature in Celsius: ");
        temp = get_valid_float();

        // Convert and display the result
        converted = celsius_to_fahrenheit(temp);
        printf("%.2f°C = %.2f°F\n\n", temp, converted);
    } else if (choice == 2) {
        // Prompt for temperature in Fahrenheit
        printf("Enter temperature in Fahrenheit: ");
        temp = get_valid_float();

        // Convert and display the result
        converted = fahrenheit_to_celsius(temp);
        printf("%.2f°F = %.2f°C\n\n", temp, converted);
    } else {
        printf("Invalid choice.\n\n");
    }
}

// Handles the distance conversion menu
void distance_menu() {
    int choice;
    float distance, converted;

    // Display distance conversion options
    printf("\nDistance Conversion\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("Choose an option (1 or 2): ");

    // Read the user's choice
    choice = get_valid_int();

    if (choice == 1) {
        // Prompt for distance in Kilometers
        printf("Enter distance in Kilometers: ");
        distance = get_valid_float();

        // Convert and display the result
        converted = kilometers_to_miles(distance);
        printf("%.2f km = %.2f miles\n\n", distance, converted);
    } else if (choice == 2) {
        // Prompt for distance in Miles
        printf("Enter distance in Miles: ");
        distance = get_valid_float();

        // Convert and display the result
        converted = miles_to_kilometers(distance);
        printf("%.2f miles = %.2f km\n\n", distance, converted);
    } else {
        printf("Invalid choice.\n\n");
    }
}

// Handles the currency conversion menu
void currency_menu() {
    int choice;
    float amount, converted;

    // Display currency conversion options
    printf("\nCurrency Conversion\n");
    printf("1. USD to EUR\n");
    printf("2. EUR to USD\n");
    printf("3. USD to GBP\n");
    printf("4. GBP to USD\n");
    printf("Choose an option (1-4): ");

    // Read the user's choice
    choice = get_valid_int();

    if (choice == 1) {
        // USD to EUR conversion
        printf("Enter amount in USD: ");
        amount = get_valid_float();

        converted = usd_to_eur(amount);
        printf("$%.2f USD = €%.2f EUR\n\n", amount, converted);
    } else if (choice == 2) {
        // EUR to USD conversion
        printf("Enter amount in EUR: ");
        amount = get_valid_float();

        converted = eur_to_usd(amount);
        printf("€%.2f EUR = $%.2f USD\n\n", amount, converted);
    } else if (choice == 3) {
        // USD to GBP conversion
        printf("Enter amount in USD: ");
        amount = get_valid_float();

        converted = usd_to_gbp(amount);
        printf("$%.2f USD = %.2f GBP\n\n", amount, converted);
    } else if (choice == 4) {
        // GBP to USD conversion
        printf("Enter amount in GBP: ");
        amount = get_valid_float();

        converted = gbp_to_usd(amount);
        printf("%.2f GBP = $%.2f USD\n\n", amount, converted);
    } else {
        printf("Invalid choice.\n\n");  
    }
}

    //Explanation
/*Modular Design:

Each conversion type is separated into its own module (temperature.c, distance.c, currency.c) with  header files (.h files).
This separation makes the code organized and easier to maintain.
Header Files:

The header files declare the functions implemented in the corresponding .c files.
They  included where needed using #include "filename.h".
Main Program (convert.c):

Contains the main function, which calls start_converter() to begin the application.
User Interface (convert_ui.c):

Manages user interaction, displays menus, and handles user input.
Uses switch statements to navigate between different conversion options.
Calls the appropriate functions from the conversion modules based on user choice.
Includes detailed comments explaining each part of the code.
Compilation:

All source files are compiled together to resolve dependencies between them.
The -o option specifies the output executable name (converter).
Notes
Adding More Conversions:

To add more conversion types (e.g., weight, volume), create new modules (weight.c, weight.h) and update convert_ui.c accordingly.
Currency Conversion Rates:

The currency conversion rates are hard-coded for simplicity.
For real-time rates, you would need to implement functionality to fetch data from a financial API.
Input Validation:

Currently, the program assumes the user enters valid input.
You may enhance the code to include error checking for invalid inputs.*/