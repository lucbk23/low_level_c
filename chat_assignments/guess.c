#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int num, guess, guesses = 0;
    
    srand(time(0));
    num = rand() % 100 + 1;

    printf("Guess the number between 1 and 100!\n");

    do {
        printf("Enter a guess: ");
        scanf("%d", &guess);
        guesses++; 
        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else { 
            printf("You guessed it in %d guesses!\n", guesses);
            break;
    }
        } while (guess != num);
    return 0;
}