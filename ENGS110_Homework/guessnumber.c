#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, userGuess;

    // Initialize random number generator
    srand(time(NULL));

    // Generate random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the guessing game!\n");
    printf("I have selected a random number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    // Start guessing loop
    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        if (userGuess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (userGuess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the correct number %d.\n", randomNumber);
        }

    } while (userGuess != randomNumber);

    return 0;
}
