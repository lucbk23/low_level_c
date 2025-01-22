#include <stdio.h>

int main () {
    int num, i;
    long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

int temp = num;
factorial = 1;
while (temp > 0){
    factorial *= temp;
    temp--;
    printf("Factorial of %d is %lld\n", num, factorial);
}
    return 0;
    // if (num < 0) {
    //     printf("Factorial is not defined for negative numbers\n");
    //     return 1;
    // }
    // for (i =1; i <= num; i++){
    //     factorial *= i;
    // }
    // printf("Factorial of %d is %lld\n", num, factorial);
    // return 0;
}
// test the difference between while and for loop