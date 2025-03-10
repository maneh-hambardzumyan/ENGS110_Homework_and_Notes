#include <stdio.h>  // Include the standard input/output library for input/output functions.

int sum_of_digits(int num) {  // Function to calculate the sum of digits of a number.
    int sum = 0;  // Initialize a variable to store the sum of digits, starting at 0.
    
    if (num < 0) num = -num;  // If the number is negative, convert it to positive.
    
    while (num > 0) {  // Loop through the digits of the number until it becomes 0.
        sum += num % 10;  // Add the last digit (num % 10) to the sum.
        num /= 10;  // Remove the last digit by dividing the number by 10.
    }
    
    return sum;  // Return the final sum of digits.
}

int main() {
    int number;  // Declare an integer variable to store the user input.
    scanf("%d", &number);  // Read the user input and store it in 'number'.
    
    printf("%d\n", sum_of_digits(number));  // Call the sum_of_digits function and print the result.
    
    return 0;  // Return 0 to indicate that the program has executed successfully.
}
