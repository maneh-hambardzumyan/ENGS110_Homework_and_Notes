#include <stdio.h>

int main() {
    int N;

    // Prompt the user to input an integer N (base of the isosceles triangle)
    printf("Enter the base of the isosceles triangle (N): ");
    scanf("%d", &N);

    // The height of the isosceles triangle will be (N+1)/2 to maintain symmetry
    int height = (N + 1) / 2;

    // Drawing the isosceles triangle
    for (int i = 1; i <= height; i++) {
        // Print spaces to center the triangle
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }

        // Print '*' for the current row, where the number of '*' increases as the row number increases
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;  // Exit the program
}
