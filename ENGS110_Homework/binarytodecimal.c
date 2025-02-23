#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char binary[65];  // To store the binary number, up to 64 bits
    int decimal = 0;

    // Ask the user to input a binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Check if the input is valid (only contains '0' or '1')
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary number! Only '0' and '1' are allowed.\n");
            return 1;
        }
    }

    // Convert the binary number to decimal
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);  // Calculate the corresponding decimal value
        }
    }

    // Print the decimal equivalent
    printf("The decimal equivalent of %s is: %d\n", binary, decimal);

    return 0;
}
