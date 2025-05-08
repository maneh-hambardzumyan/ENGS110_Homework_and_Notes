#include "array.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Creates and initializes a new dynamic array
struct array* array_create()
{
    struct array* arr = (struct array*)malloc(sizeof(struct array));
    assert(arr != NULL);
    
    memset(arr, 0, sizeof(struct array));
    arr->size = 0;
    arr->capacity = 2;
    arr->start = (element_type*)malloc(arr->capacity * sizeof(element_type));
    
    return arr;
}

// Appends a new item to the end of the array
void array_push_back(struct array* arr, element_type value)
{
    assert(arr != NULL);

    // If array is full, make room for more items
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->start = (element_type*)realloc(arr->start, arr->capacity * sizeof(element_type));
        assert(arr->start != NULL);
    }

    arr->start[arr->size] = value;
    arr->size++;
}

// Deletes the last element in the array
void array_pop_back(struct array* arr)
{
    assert(arr != NULL);
    assert(arr->size > 0);

    arr->size--;
}

// Adds an element at a specific position in the array
void array_insert(struct array* arr, size_type index, element_type value)
{
    assert(arr != NULL);
    assert(index <= arr->size);  // valid positions include end

    // If no space left, double the capacity
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->start = (element_type*)realloc(arr->start, arr->capacity * sizeof(element_type));
        assert(arr->start != NULL);
    }

    // Shift all items from the index onward to the right
    for (size_type i = arr->size; i > index; --i) {
        arr->start[i] = arr->start[i - 1];
    }

    arr->start[index] = value;
    arr->size++;
}

// Returns how many items are currently stored
size_type array_size(struct array* arr)
{
    assert(arr != NULL);
    return arr->size;
}

// Returns how much space is allocated in total
size_type array_capacity(struct array* arr)
{
    assert(arr != NULL);
    return arr->capacity;
}

// Prints out the array's contents
void array_print(struct array* arr)
{
    assert(arr != NULL);

    for (size_type i = 0; i < arr->size; ++i) {
        printf("%d ", arr->start[i]);
    }

    printf("\nsize = %d", arr->size);
    printf("\ncapacity = %d\n\n", arr->capacity);
}

// Checks if there are any elements in the array
int array_empty(struct array* arr)
{
    assert(arr != NULL);
    return arr->size == 0;
}

// Example main function testing the array

int main() {
    struct array* myArray = array_create();

    array_push_back(myArray, 5);
    array_push_back(myArray, 10);
    array_push_back(myArray, 15);

    array_insert(myArray, 1, 7);  

    array_print(myArray);   
         
    array_pop_back(myArray);     

    array_print(myArray);        

    if (array_empty(myArray)) {
        printf("Array is empty\n");
    } else {
        printf("Array is not empty\n");
    }

    return 0;
}
