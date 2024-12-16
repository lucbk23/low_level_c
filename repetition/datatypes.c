#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quiz();
void checkAnswer(int correct, int userAnswer);

int main() {
    printf("Welcome to the Data Type Quiz!\n\n");
    printf("You will be asked about typical sizes of various C data types.\n");
    printf("Try to guess the correct size in bytes!\n\n");

    quiz();

    return 0;
}

void quiz() {
    // Array of data types and their typical sizes in bytes
    const char *dataTypes[] = {
        "char", "short", "int", "long", "float", "double",
        "unsigned char", "unsigned short", "unsigned int", "unsigned long"
    };
    int sizes[] = {
        sizeof(char), sizeof(short), sizeof(int), sizeof(long),
        sizeof(float), sizeof(double),
        sizeof(unsigned char), sizeof(unsigned short), sizeof(unsigned int), sizeof(unsigned long)
    };

    int numQuestions = sizeof(dataTypes) / sizeof(dataTypes[0]);

    // Seed random number generator
    srand(time(NULL));

    for (int i = 0; i < 5; i++) { // Ask 5 questions
        int index = rand() % numQuestions; // Pick a random data type

        printf("\nQuestion %d: What is the typical size of %s in bytes?\n", i + 1, dataTypes[index]);
        printf("1 byte\n2 bytes\n4 bytes\n8 bytes\n");

        int userAnswer;
        printf("Your answer (1, 2, 4, or 8): ");
        while (scanf("%d", &userAnswer) != 1 || (userAnswer != 1 && userAnswer != 2 && userAnswer != 4 && userAnswer != 8)) {
            printf("Invalid input. Please enter 1, 2, 4, or 8: ");
            while (getchar() != '\n'); // Clear the input buffer
        }

        // Check the user's answer
        int correctAnswer = sizes[index];

        checkAnswer(correctAnswer, userAnswer);
    }
}

void checkAnswer(int correct, int userAnswer) {
    if (userAnswer == correct) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer was %d bytes.\n", correct);
    }
}