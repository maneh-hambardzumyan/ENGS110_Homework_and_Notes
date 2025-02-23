#include <stdio.h>

int main() {
    int num;
    
    // Ask the user to input a number
    printf("Enter a number (between 0 and 15): ");
    scanf("%d", &num);

    // Check if the number is within the 4-bit range
    if (num < 0 || num > 15) {
        printf("Please enter a number between 0 and 15.\n");
        return 1;
    }

    // Print the binary equivalent of the number (in 4 bits)
    printf("The binary equivalent of %d is: ", num);
    
    // Loop to extract each bit
    for (int i = 3; i >= 0; i--) {
        // Shift the number to the right by i bits and mask with 1 to get the current bit
        int bit = (num >> i) & 1;
        
        // Print the bit
        printf("%d", bit);
    }

    // Move to the next line after printing the binary number
    printf("\n");

    return 0;
}
