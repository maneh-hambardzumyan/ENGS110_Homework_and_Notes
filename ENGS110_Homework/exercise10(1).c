#include <stdio.h>

int main() {
    int N, M;
    char drawChar;

    // Prompt the user to input two integers: N (number of rows) and M (number of columns)
    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    // Prompt the user to input the character to be used for drawing
    printf("Enter the character to draw the rectangle: ");
    scanf(" %c", &drawChar);  // The space before %c is used to ignore any leftover newline character

    // Draw the rectangle
    for (int i = 0; i < N; i++) {
        // Loop for each row

        for (int j = 0; j < M; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                // Print the drawChar on the borders (first row, last row, first column, last column)
                printf("%c", drawChar);
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
