#include <stdio.h>

int main() {
    int number, isPrime = 1;  // Declare an integer variable 'number' and a flag 'isPrime' set to 1 (assume prime initially).
    
    // Prompt the user to enter a number.
    printf("Enter a number: ");
    scanf("%d", &number);  // Read the input number and store it in 'number'.
    
    // Handle edge cases for numbers less than 2, as prime numbers are greater than 1.
    if (number <= 1) {
        isPrime = 0;  // Set isPrime to 0 for numbers less than or equal to 1.
    } else {
        // Check divisibility from 2 to the square root of the number.
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {  // If 'number' is divisible by 'i', it's not prime.
                isPrime = 0;  // Set isPrime to 0 (not prime).
                break;  // Exit the loop as we found a divisor.
            }
        }
    }
    
    // Print the result based on the value of 'isPrime'.
    if (isPrime) {
        printf("%d is a prime number.\n", number);  // If isPrime is 1, the number is prime.
    } else {
        printf("%d is not a prime number.\n", number);  // If isPrime is 0, the number is not prime.
    }
    
    return 0;  // Exit the program successfully.
}
