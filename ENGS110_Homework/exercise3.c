#include <stdio.h>

int main() {
    int N, sum = 0;  // Declare two integer variables: N for user input and sum for storing the result.
    
    printf("Enter a number (1-1000): ");  // Prompt the user to enter a number.
    scanf("%d", &N);  // Read the integer input from the user and store it in variable N.
    
    if (N < 1 || N > 1000) {  // Check if the input is outside the valid range (1-1000).
        printf("Invalid input! Please enter a number between 1 and 1000.\n");  // Inform the user about invalid input.
        return 1;  // Exit the program with an error code (1).
    }
    
    for (int i = 1; i < N; i++) {  // Loop through numbers starting from 1 up to N-1.
        if (i % 3 == 0 || i % 5 == 0) {  // Check if the current number is divisible by 3 or 5.
            sum += i;  // Add the number to the sum if it is divisible by 3 or 5.
        }
    }
    
    printf(" %d is: %d\n", N, sum);  // Output the value of N and the calculated sum.
    
    return 0;  // Exit the program successfully (0).
}
