#include <stdio.h>

int isPowerOfTwo(int num) {
    // A number is a power of 2 if it is greater than 0 and its binary AND with (num - 1) is 0.
    return (num > 0) && (num & (num - 1)) == 0;
}

int main() {
    int number;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &number);  // Read the input number

    // Check if the number is a power of 2 and print the result
    if (isPowerOfTwo(number)) {
        printf("%d is a power of 2.\n", number);  // If the number is a power of 2
    } else {
        printf("%d is not a power of 2.\n", number);  // If the number is not a power of 2
    }

    return 0;  // Exit the program
}
