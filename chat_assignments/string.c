#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); //kan bruges istedet for scanf fordi den læser hele linjen til det første \n eller \0. scanf læser kun til det første mellemrum.
    char *start = str; // The pointer is pointing at the first element in the array.
    char *end = str + strlen(str) -1; // The pointer is pointing at the last element in the array.

    printf("Original string: %s\n", str);
    printf("\n");

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        // move the pointers
        start++;
        end--;
    }
    printf("Reversed string: %s\n", str);

    return 0;
}