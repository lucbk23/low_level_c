#include <stdio.h>

void my_func(int m);

int main() {

    int a = 1234;
    int b = 5678;

    b = a;
    a = 17;

    printf("--------b=a, a=17--------\n");

    printf("Value of a: %d\n", a);
    printf("Address of a: %d\n", &a);

    printf("Value of b: %d\n", b);
    printf("Address of b: %d\n", &b);

    my_func(b);

    printf("--------efter my_func\n");
    printf("Value of a: %d\n", a);
    printf("Address of a: %d\n", &a);

    printf("Value of b: %d\n", b);
    printf("Address of b: %d\n", &b);
    return 0;
}

void my_func(int m) {

    int a = 512;
    m = 21;
    printf("--------Inde i my_func\n");

    printf("Value of a: %d\n", a);
    printf("Address of a: %d\n", &a);

    printf("Value of m: %d\n", m);
    printf("Address of m: %d\n", &m);

    printf("--------afslut my_func\n");
}
