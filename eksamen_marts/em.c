#include <stdio.h>
#include <string.h>

// Funktion til at tælle antallet af UTF-8 tegn i en streng
int utf8_strlen(const char *str) {
    int len = 0;
    while (*str) {
        if ((*str & 0xC0) != 0x80) { //0xC0 = 11000000 og 0x80 = 10000000
            len++;
        }
        str++;
    }
    return len;
}

// Funktion til at udskrive strengen og en underline med korrekt længde bruger ledende bytes til at finde antallet af bytes
void underline(const char *str) {
    printf("%s\n", str);
    int len = utf8_strlen(str);
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    char *str = "Æbler"; //julemanden og juletræet er emojis og den fylder så 4 byte istedet for hvert
    char str2[] = "Æblet";
    str = str2;
    //tegn der nogmalt fylder 1 undtagen æ som er non ascii og derfor fylder 2 byte
    underline(str);
    printf("Antallet af karakterer: %d\n", utf8_strlen(str)); 
    return 0;
}