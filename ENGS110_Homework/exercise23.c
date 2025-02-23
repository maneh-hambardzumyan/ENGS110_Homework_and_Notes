#include <stdio.h>

void sortAscending(int arr[], int N) {
    // Sort the array in ascending order using Bubble Sort
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int N) {
    // Sort the array in descending order using Bubble Sort
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N, choice;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];  // Declare an array to hold N numbers

    // Input N numbers
    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for sorting order choice
    printf("Enter 1 for ascending order, 2 for descending order: ");
    scanf("%d", &choice);

    // Sort the array based on user's choice
    if (choice == 1) {
        sortAscending(arr, N);
        printf("Sorted in ascending order: ");
    } else if (choice == 2) {
        sortDescending(arr, N);
        printf("Sorted in descending order: ");
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Output the sorted array
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
