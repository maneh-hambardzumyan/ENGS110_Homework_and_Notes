#include <stdio.h>
#include <math.h>  // For the log10 function to determine the number of digits

int main() {
    int num1, num2;
    
    // Prompt the user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);  // Read the first number
    
    printf("Enter the second number: ");
    scanf("%d", &num2);  // Read the second number
    
    // Find the number of digits in the second number
    int digits = (int)log10(num2) + 1;  // log10(num2) gives the number of digits minus 1, so add 1

    // Concatenate the numbers
    int result = num1 * pow(10, digits) + num2;  // Multiply num1 by 10^digits and then add num2 to it

    // Print the concatenated result
    printf("The concatenated result is: %d\n", result);
    
    return 0;  // Exit the program successfully
}
