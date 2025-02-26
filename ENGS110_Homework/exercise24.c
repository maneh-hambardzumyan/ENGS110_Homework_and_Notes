#include <stdio.h>

// Function to delete the M-th element from the sequence
void deleteElement(int arr[], int *n, int m) {
    // Check if the position M is valid (1 <= M <= N)
    if (m < 1 || m > *n) {
        printf("Invalid position M\n");
        return;
    }
    
    // Shift all elements after the M-th element to the left
    for (int i = m - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Decrease the size of the array by 1
    (*n)--;
}

int main() {
    int arr[] = {1, 4, 5, 6, 3};  // Initial sequence
    int n = 5;  // Length of the sequence
    int m = 3;  // Position of the element to delete (e.g., the 3rd element)
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Delete the M-th element
    deleteElement(arr, &n, m);
    
    // Print the array after deletion
    printf("Array after deleting the %d-th element: ", m);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

