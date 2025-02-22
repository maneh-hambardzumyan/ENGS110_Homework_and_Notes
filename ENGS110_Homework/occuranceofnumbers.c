#include <stdio.h>

int main() {
    // Array to store the count of each number (from 1 to 10)
    int count[10] = {0};  // Initialize all counts to 0

    int num;

    // Prompt the user to input numbers
    printf("Enter numbers between 1 and 10. Enter -1 to stop.\n");

    // Infinite loop to keep asking for numbers
    while (1) {
        // Ask the user for a number
        printf("Enter a number (1-10 or -1 to quit): ");
        scanf("%d", &num);

        // If the user enters -1, break out of the loop
        if (num == -1) {
            break;
        }

        // Check if the number is within the valid range (1-10)
        if (num >= 1 && num <= 10) {
            count[num - 1]++;  // Increment the count for the entered number
        } else {
            printf("Invalid input! Please enter a number between 1 and 10.\n");
        }
    }

    // Print the results
    printf("\nNumber counts:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d times\n", i + 1, count[i]);
    }

    return 0;
}
