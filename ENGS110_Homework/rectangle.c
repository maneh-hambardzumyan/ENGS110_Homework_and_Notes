#include <stdio.h>

int main() {
    int N, M;

    // Prompt the user to input two integers: N (number of rows) and M (number of columns)
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    // Draw the rectangle
    for (int i = 0; i < N; i++) {
        // Loop for each row

        for (int j = 0; j < M; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                // Print '*' on the borders (first row, last row, first column, last column)
                printf("*");
            } else {
                // Print a space for the inside of the rectangle
                printf(" ");
            }
        }

        // Print a newline after each row
        printf("\n");
    }

    return 0;  // Exit the program
}
