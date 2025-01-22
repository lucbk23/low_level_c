#include <stdio.h>

int main () {
    float num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (op) {
        case '+':
           result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Division by zero not allowed\n");
                return 1;
            }
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }
    printf("Result: %.2f\n", result);
    return 0;
}