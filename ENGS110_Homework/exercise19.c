#include <stdio.h>

int main() {
    int arr[10];
    int N;
    
    // Input 10 integers into the array
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the value of N to search for
    printf("Enter the value N to search for: ");
    scanf("%d", &N);

    // Search for the first occurrence of N and remove it
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == N) {
            // Shift elements left
            for (int j = i; j < 9; j++) {
                arr[j] = arr[j + 1];
            }
            // Set the last element to zero
            arr[9] = 0;
            found = 1;
            break; // Exit the loop once we remove the first occurrence of N
        }
    }

    // If N was found, print the modified array
    if (found) {
        printf("Modified array: ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("The value %d was not found in the array.\n", N);
    }

    return 0;
}
