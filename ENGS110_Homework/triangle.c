#include <stdio.h>

int main() {
    int N;

    // Prompt the user to input an integer N (height of the triangle)
    printf("Enter the height of the triangle (N): ");
    scanf("%d", &N);

    // Drawing the first right-angled triangle with the right angle at the top-left
    printf("\nRight-angled triangle (Top-left right angle):\n");
    for (int i = 1; i <= N; i++) {
        // Print '*' for each row, where the number of '*' is equal to the row number
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");  // Move to the next line after each row
    }

    // Drawing the second right-angled triangle with the right angle at the bottom-left
    printf("\nRight-angled triangle (Bottom-left right angle):\n");
    for (int i = 1; i <= N; i++) {
        // Print spaces for the initial part of each row, followed by '*' characters
        for (int j = 1; j <= N - i; j++) {
            printf(" ");  // Print spaces to align the '*' to the right
        }
        for (int j = 1; j <= i; j++) {
            printf("*");  // Print '*' for the current row
        }
        printf("\n");  // Move to the next line after each row
    }

    return 0;  // Exit the program
}
