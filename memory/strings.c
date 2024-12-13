#include <stdio.h>

int main() {

    char question[]= "What is your name?";
    char greeting[]= "Well, hello there!";
    char name[8];

    puts(question);
    gets(name);

    puts(greeting);
    puts(name);

    return 0;
}
