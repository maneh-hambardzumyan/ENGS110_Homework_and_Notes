#include <stdio.h>

int main() {
    // Declare an array to hold 10 numbers
    int numbers[10];
    
    // Declare variables for the minimum and maximum values
    int min, max;

    // Ask the user to input 10 numbers
    printf("Please enter 10 numbers:\n");

    // Input the first number separately to initialize min and max
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);

        // For the first number, initialize both min and max to the same value
        if (i == 0) {
            min = numbers[i];  // Set min to the first number
            max = numbers[i];  // Set max to the first number
        } else {
            // Compare the current number with min and max to find the new min and max
            if (numbers[i] < min) {
                min = numbers[i];  // Update min if the current number is smaller
            }
            if (numbers[i] > max) {
                max = numbers[i];  // Update max if the current number is larger
            }
        }
    }

    // After the loop, print the results
    printf("\nThe smallest number is: %d\n", min);
    printf("The largest number is: %d\n", max);

    return 0;  // Program ends successfully
}
