#include "temperature.h"

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