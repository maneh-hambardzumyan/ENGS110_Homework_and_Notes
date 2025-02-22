#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables for the random number and the user's guess
    int randomNumber, userGuess;

    // Initialize random number generator using the current time as the seed
    srand(time(NULL));  // Using current time to ensure different numbers each time

    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;  // rand() generates a number between 0 and RAND_MAX, so we use modulus to restrict the range

    // Display a welcome message to the user
    printf("Welcome to the guessing game!\n");
    printf("I have selected a random number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    // Start a loop that will continue until the user guesses the correct number
    do {
        // Ask the user to enter their guess
        printf("Enter your guess: ");
        
        // Read the user's guess from input
        scanf("%d", &userGuess);

        // Check if the guess is too low
        if (userGuess < randomNumber) {
            printf("Too low! Try again.\n");
        }
        // Check if the guess is too high
        else if (userGuess > randomNumber) {
            printf("Too high! Try again.\n");
        }
        // If the guess is correct, congratulate the user
        else {
            printf("Congratulations! You've guessed the correct number %d.\n", randomNumber);
        }

    // The loop repeats as long as the user's guess is not equal to the random number
    } while (userGuess != randomNumber);

    return 0;  // Program ends successfully
}
