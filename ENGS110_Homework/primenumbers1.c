#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;  // Numbers less than or equal to 1 are not prime
    }

    // Check divisibility from 2 to the square root of num
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {  // If num is divisible by i, it is not prime
            return 0;
        }
    }

    return 1;  // Return 1 if num is prime
}

int main() {
    int N;

    // Prompt the user to input a number
    printf("Enter a number: ");
    scanf("%d", &N);

    // Print all prime numbers in the range 1 to N
    printf("Prime numbers in the range 1 to %d are:\n", N);
    for (int i = 1; i <= N; i++) {
        if (is_prime(i)) {
            printf("%d ", i);  // Print the prime number
        }
    }
    printf("\n");  // Print a newline after listing primes

    return 0;  // Exit the program successfully
}
