#include <stdio.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    char *ptr = str;
    int vowel_count = 0;

    while(*ptr != '\0') {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'
            || *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            vowel_count++;
        }
        ptr++;
    }
    printf("Number of vowels: %d\n", vowel_count);
    return 0;
}

