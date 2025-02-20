#include <stdio.h>

int main() {
    int N;

    // Prompt the user to input an integer N (height of the isosceles triangle)
    printf("Enter the height of the isosceles triangle (N): ");
    scanf("%d", &N);

    // Drawing the isosceles triangle
    for (int i = 1; i <= N; i++) {
        // Print spaces to center the triangle
        for (int j = 1; j <= N - i; j++) {
            printf(" ");
        }

        // Print '*' for the current row, where the number of '*' is (2 * i - 1)
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;  // Exit the program
}
