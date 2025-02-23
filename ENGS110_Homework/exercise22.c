#include <stdio.h>

int main() {
    int N;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];

    // Input N whole numbers
    printf("Enter %d whole numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the array is sorted in ascending or descending order
    int ascending = 1;  // Flag for ascending order
    int descending = 1; // Flag for descending order

    // Loop through the array to check the order
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[i - 1]) {
            ascending = 0;  // If not in ascending order
        }
        if (arr[i] > arr[i - 1]) {
            descending = 0;  // If not in descending order
        }
    }

    // Output the result
    if (ascending || descending) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
