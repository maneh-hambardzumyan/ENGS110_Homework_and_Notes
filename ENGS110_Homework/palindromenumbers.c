#include <stdio.h>

int main() {
    int number, reversed = 0, original, remainder;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &number);  // Read the input number

    original = number;  // Store the original number for comparison later

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;  // Get the last digit
        reversed = reversed * 10 + remainder;  // Build the reversed number
        number /= 10;  // Remove the last digit
    }

    // Check if the original number and the reversed number are the same
    if (original == reversed) {
        printf("%d is a palindrome number.\n", original);  // The number is a palindrome
    } else {
        printf("%d is not a palindrome number.\n", original);  // The number is not a palindrome
    }

    return 0;  // Exit the program
}
