#include <stdio.h>

// Function to print the binary representation of an 8-bit number
void printBinary8(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    unsigned char a, b; // 8-bit unsigned integers
    unsigned char guess;

    // Input two unsigned 8-bit integers
    printf("Enter the first number (a) [0-255]: ");
    scanf("%hhu", &a);

    printf("Enter the second number (b) [0-255]: ");
    scanf("%hhu", &b);

    // Display the binary representation of the inputs
    printf("\nBinary representation of inputs (8 bits):\n");
    printf("a = %-3u: ", a);
    printBinary8(a);
    printf("\n");

    printf("b = %-3u: ", b);
    printBinary8(b);
    printf("\n");

    // Prompt for AND operation
    printf("\nWhat do you think the result of a & b (AND) is in decimal? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (a & b));
    printBinary8(a & b);
    printf("\n");

    // Prompt for OR operation
    printf("\nWhat do you think the result of a | b (OR) is in decimal? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (a | b));
    printBinary8(a | b);
    printf("\n");

    // Prompt for XOR operation
    printf("\nWhat do you think the result of a ^ b (XOR) is in decimal? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (a ^ b));
    printBinary8(a ^ b);
    printf("\n");

    // Prompt for NOT operation (only for 'a')
    printf("\nWhat do you think the result of ~a (NOT) is in decimal (8-bit)? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (unsigned char)~a);
    printBinary8(~a);
    printf("\n");

    // Prompt for Left Shift
    printf("\nWhat do you think the result of a << 1 (Left shift) is in decimal (8-bit)? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (a << 1) & 0xFF); // Mask to 8 bits
    printBinary8((a << 1) & 0xFF);
    printf("\n");

    // Prompt for Right Shift
    printf("\nWhat do you think the result of a >> 1 (Right shift) is in decimal (8-bit)? ");
    scanf("%hhu", &guess);
    printf("Correct answer: %-3u: ", (a >> 1));
    printBinary8(a >> 1);
    printf("\n");

    return 0;
}
