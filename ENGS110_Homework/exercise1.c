#include <stdio.h>  // Include the standard input-output library

// Main function where execution starts
int main() {
    int num1, num2;  // Declare two integer variables to store the input numbers
    char op;          // Declare a character variable to store the operator (+, -, *, or /)

    // Prompt the user to input an arithmetic expression in the format: number operator number
    printf("Enter an arithmetic expression (number operator number): ");
    
    // Use scanf to read the user input. %d reads integers, %c reads a single character
    // The input should be in the format: num1 op num2 (e.g., 5 + 3)
    scanf("%d %c %d", &num1, &op, &num2);

    // The switch statement evaluates the operator entered by the user
    switch(op) {
        // Case for the '+' operator: Addition
        case '+':
            // If the operator is '+', perform addition and print the result
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;  // Exit the switch statement after performing the addition

        // Case for the '-' operator: Subtraction
        case '-':
            // If the operator is '-', perform subtraction and print the result
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;  // Exit the switch statement after performing the subtraction

        // Case for the '*' operator: Multiplication
        case '*':
            // If the operator is '*', perform multiplication and print the result
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;  // Exit the switch statement after performing the multiplication

        // Case for the '/' operator: Division
        case '/':
            // Check if num2 (the divisor) is zero to prevent division by zero
            if (num2 == 0) {
                // If num2 is zero, print an error message because division by zero is not allowed
                printf("Error: Division by zero is not allowed.\n");
            } else {
                // If num2 is non-zero, perform division and print the result with 3 decimal places
                printf("%d / %d = %.3f\n", num1, num2, (float)num1 / num2);
            }
            break;  // Exit the switch statement after handling division

        // Default case: If the operator is none of the above (+, -, *, /)
        default:
            // Print an error message if an invalid operator is entered
            printf("Error: Invalid operator.\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
