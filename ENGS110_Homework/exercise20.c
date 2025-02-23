#include <stdio.h>

int main() {
    int N;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Declare an array to hold N numbers

    // Input N numbers
    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the numbers in reverse order
    printf("The numbers in reverse order are:\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
