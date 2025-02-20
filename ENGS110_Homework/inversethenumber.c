#include <stdio.h>

int main() {
    int number;  // Declare an integer variable to store the input number.
    
    // Prompt the user to enter an integer.
    printf("Enter an integer number: ");
    scanf("%d", &number);  // Read the input number from the user and store it in 'number'.

    // Check if the number is 0, because the inverse of 0 is undefined.
    if (number == 0) {
        printf("Inverse of 0 is undefined.\n");
    } else {
        // Calculate the inverse (reciprocal) of the number.
        float inverse = 1.0 / number;  // Use 1.0 to ensure floating-point division.

        // Print the inverse (reciprocal) of the number.
        printf("The inverse (reciprocal) of %d is: %.6f\n", number, inverse);  // Print with 6 decimal places.
    }

    return 0;  // Exit the program successfully.
}
