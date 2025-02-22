#include <stdio.h>

int main() {
    int low = 1, high = 100, guess, response;

    printf("Think of a number between 1 and 100, and I will try to guess it in 7 or fewer guesses.\n");

    // Loop that allows the computer to keep guessing until it finds the correct number
    int attempts = 0;
    while (low <= high) {
        // Calculate the middle value in the current range
        guess = (low + high) / 2;
        attempts++;

        // Ask the user if the guess is correct, too high, or too low
        printf("Is your number %d? (Enter 1 for correct, 2 for too high, 3 for too low): ", guess);
        scanf("%d", &response);

        if (response == 1) {
            printf("Yay! I guessed your number %d in %d attempts.\n", guess, attempts);
            break;  // Correct guess, exit the loop
        } else if (response == 2) {
            // If the guess is too high, adjust the high limit
            high = guess - 1;
        } else if (response == 3) {
            // If the guess is too low, adjust the low limit
            low = guess + 1;
        } else {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
