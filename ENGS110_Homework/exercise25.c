#include <stdio.h>

#define MAX_SIZE 100  // Maximum size for the array

// Function to insert K at the beginning of the array
void insertAtBeginning(int arr[], int *n, int k) {
    // Check if there's enough space for the new element
    if (*n >= MAX_SIZE) {
        printf("Array is full, cannot insert at the beginning.\n");
        return;
    }
    
    // Shift all elements to the right by one position to make space at the beginning
    for (int i = *n; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert K at the beginning
    arr[0] = k;
    
    // Increase the size of the array
    (*n)++;
}

// Function to insert K at the end of the array
void insertAtEnd(int arr[], int *n, int k) {
    // Check if there's enough space for the new element
    if (*n >= MAX_SIZE) {
        printf("Array is full, cannot insert at the end.\n");
        return;
    }
    
    // Insert K at the end
    arr[*n] = k;
    
    // Increase the size of the array
    (*n)++;
}

// Function to insert K at the M-th position in the array
void insertAtPosition(int arr[], int *n, int k, int m) {
    // Check if the position is valid (1 <= M <= N+1)
    if (m < 1 || m > *n + 1) {
        printf("Invalid position M\n");
        return;
    }
    
    // Check if there's enough space for the new element
    if (*n >= MAX_SIZE) {
        printf("Array is full, cannot insert at position %d.\n", m);
        return;
    }
    
    // Shift elements to the right to make space for the new element
    for (int i = *n; i >= m; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert K at the M-th position (1-based index)
    arr[m - 1] = k;
    
    // Increase the size of the array
    (*n)++;
}

int main() {
    int arr[MAX_SIZE] = {1, 4, 5, 6, 3};  // Initial sequence
    int n = 5;  // Length of the sequence
    int k = 10; // Element to insert
    int m = 3;  // Position to insert at (1-based index)
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insert at the beginning
    insertAtBeginning(arr, &n, k);
    printf("Array after inserting %d at the beginning: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insert at the end
    insertAtEnd(arr, &n, k);
    printf("Array after inserting %d at the end: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insert at the M-th position (e.g., 3rd position)
    insertAtPosition(arr, &n, k, m);
    printf("Array after inserting %d at the %d-th position: ", k, m);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}