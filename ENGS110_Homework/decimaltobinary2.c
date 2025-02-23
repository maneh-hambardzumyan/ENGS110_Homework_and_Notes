#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, int bits) {
    // Handle the case for negative numbers (2's complement)
    if (num < 0) {
        // If number is negative, convert to 2's complement representation
        num = (1 << bits) + num;  // Add 2^n to the negative number to get the 2's complement
    }

    // Print the binary representation in the specified number of bits
    for (int i = bits - 1; i >= 0; i--) {
        // Extract the current bit and print it (shift right and mask)
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    int num, bits = 4;

    // Ask the user to input a decimal number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the binary equivalent of the number (in 4 bits)
    printf("The binary equivalent of %d is: ", num);

    decimalToBinary(num, bits);

    printf("\n");

    return 0;
}
