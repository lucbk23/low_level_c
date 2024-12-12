#include <stdio.h>

int main() {

    char word[] = "Hello World!";

    int i = 0;

    while(word[i]){
        putchar(word[i]);
        i++;
    }

    return 0;
}