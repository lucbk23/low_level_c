#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the binary representation of an 8-bit number
void printBinary8(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Randomly decide if the program will use signed or unsigned integers
    int useSigned = rand() % 2; // 0 for unsigned, 1 for signed
    unsigned char guess;
    int shiftAmount = rand() % 3 + 1; // Random shift amount between 1 and 3

    if (useSigned) {
        printf("Working with signed 8-bit integers:\n\n");

        // Generate two random 8-bit signed integers
        char a = (char)(rand() % 256 - 128); // Range: -128 to 127
        char b = (char)(rand() % 256 - 128); // Range: -128 to 127

        // Display the values and their binary representation
        printf("a = %-4d: ", a);
        printBinary8((unsigned char)a);
        printf("\n");

        printf("b = %-4d: ", b);
        printBinary8((unsigned char)b);
        printf("\n");

        // Ask about AND operation
        printf("\nWhat do you think the result of a & b (AND) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", a & b);
        printBinary8((unsigned char)(a & b));
        printf("\n");

        // Ask about OR operation
        printf("\nWhat do you think the result of a | b (OR) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", a | b);
        printBinary8((unsigned char)(a | b));
        printf("\n");

        // Ask about XOR operation
        printf("\nWhat do you think the result of a ^ b (XOR) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", a ^ b);
        printBinary8((unsigned char)(a ^ b));
        printf("\n");

        // Ask about NOT operation (only for 'a')
        printf("\nWhat do you think the result of ~a (NOT) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", (char)~a);
        printBinary8((unsigned char)~a);
        printf("\n");

        // Ask about Left Shift
        printf("\nWhat do you think the result of a << %d (Left shift) is in decimal? ", shiftAmount);
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", (a << shiftAmount) & 0xFF);
        printBinary8((a << shiftAmount) & 0xFF);
        printf("\n");

        // Ask about Right Shift
        printf("\nWhat do you think the result of a >> %d (Right shift) is in decimal? ", shiftAmount);
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4d, Binary: ", a >> shiftAmount);
        printBinary8(a >> shiftAmount);
        printf("\n");

    } else {
        printf("Working with unsigned 8-bit integers:\n\n");

        // Generate two random 8-bit unsigned integers
        unsigned char a = (unsigned char)(rand() % 256); // Range: 0 to 255
        unsigned char b = (unsigned char)(rand() % 256); // Range: 0 to 255

        // Display the values and their binary representation
        printf("a = %-4u: ", a);
        printBinary8(a);
        printf("\n");

        printf("b = %-4u: ", b);
        printBinary8(b);
        printf("\n");

        // Ask about AND operation
        printf("\nWhat do you think the result of a & b (AND) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", a & b);
        printBinary8(a & b);
        printf("\n");

        // Ask about OR operation
        printf("\nWhat do you think the result of a | b (OR) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", a | b);
        printBinary8(a | b);
        printf("\n");

        // Ask about XOR operation
        printf("\nWhat do you think the result of a ^ b (XOR) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", a ^ b);
        printBinary8(a ^ b);
        printf("\n");

        // Ask about NOT operation (only for 'a')
        printf("\nWhat do you think the result of ~a (NOT) is in decimal? ");
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", (unsigned char)~a);
        printBinary8(~a);
        printf("\n");

        // Ask about Left Shift
        printf("\nWhat do you think the result of a << %d (Left shift) is in decimal? ", shiftAmount);
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", (a << shiftAmount) & 0xFF);
        printBinary8((a << shiftAmount) & 0xFF);
        printf("\n");

        // Ask about Right Shift
        printf("\nWhat do you think the result of a >> %d (Right shift) is in decimal? ", shiftAmount);
        scanf("%hhu", &guess);
        printf("Correct answer: Decimal: %-4u, Binary: ", a >> shiftAmount);
        printBinary8(a >> shiftAmount);
        printf("\n");
    }

    return 0;
}
