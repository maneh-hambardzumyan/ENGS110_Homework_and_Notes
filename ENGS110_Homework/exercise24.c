#include <stdio.h>

int main() {
    int N, M;

    // Ask for the number of elements in the sequence
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Declare an array of size N

    // Input N numbers into the array
    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user which element to delete (M-th element)
    printf("Enter the position M to delete (1-based index): ");
    scanf("%d", &M);

    // Check if M is valid
    if (M < 1 || M > N) {
        printf("Invalid position! M must be between 1 and %d.\n", N);
        return 1;
    }

    // Delete the M-th element by shifting elements to the left
    for (int i = M - 1; i < N - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements to the left
    }

    // Decrease the size of the array (effectively one element is deleted)
    N--;

    // Output the array after deletion
    printf("Array after deletion:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
