#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <assert.h>     
 
typedef int element_type;

typedef int size_type;

struct array {
    element_type* start; 
    size_type size;      
    size_type capacity;  
};

struct array* array_create() {
    struct array* a = (struct array*)malloc(sizeof(struct array)); // allocate memory for the struct
    assert(a != NULL);  // crashes if allocation failed

    a->size = 0;        
    a->capacity = 2;    

    // allocate memory for the data array 
    a->start = (element_type*)malloc(a->capacity * sizeof(element_type));
    assert(a->start != NULL);  // crashes if allocation failed

    return a;
}

// Adds a new element to the end of the array
void array_push_back(struct array* a, element_type e) {
    assert(a != NULL);

    // If the array is full, doubles its capacity
    if (a->size >= a->capacity) {
        a->capacity *= 2;
        a->start = (element_type*)realloc(a->start, a->capacity * sizeof(element_type));
        assert(a->start != NULL); // make sure realloc didn't fail
    }

    a->start[a->size++] = e;
}

// Removes the last element from the array (if any)
void array_pop_back(struct array* a) {
    assert(a != NULL);

    if (a->size > 0) {
        a->size--; 
    }
}

// Inserts an element at a specific index, shifting elements to the right
void array_insert(struct array* a, size_type index, element_type e) {
    assert(a != NULL);
    assert(index <= a->size); // inserting at a->size is OK (appending)

    // If the array is full, doubles its capacity
    if (a->size >= a->capacity) {
        a->capacity *= 2;
        a->start = (element_type*)realloc(a->start, a->capacity * sizeof(element_type));
        assert(a->start != NULL);
    }

    // starting from the end shifts elements one position to the right 
    for (size_type i = a->size; i > index; --i) {
        a->start[i] = a->start[i - 1];
    }

    // Inserts the new element
    a->start[index] = e;
    a->size++;  
}

// Returns the number of elements in the array
size_type array_size(struct array* a) {
    assert(a != NULL);
    return a->size;
}

// Returns the total capacity of the array
size_type array_capacity(struct array* a) {
    assert(a != NULL);
    return a->capacity;
}

// Prints the contents of the array, its size, and capacity
void array_print(struct array* a) {
    assert(a != NULL);

    for (size_type i = 0; i < a->size; ++i) {
        printf("%d ", a->start[i]);
    }
    printf("\nsize = %d\n", a->size);
    printf("capacity = %d\n\n", a->capacity);
}

// Returns 1 if the array is empty, otherwise returns 0
int array_empty(struct array* a) {
    assert(a != NULL);
    return a->size == 0;
}


int main() {
    // Create a new dynamic array
    struct array* a = array_create();

    // Add some elements to the end
    array_push_back(a, 10);
    array_push_back(a, 20);
    array_push_back(a, 30);

    printf("After push_back:\n");
    array_print(a);  // should print: 10 20 30

    // Inserts new element in the middle
    array_insert(a, 1, 99);  // insert 99 at index 1
    printf("After insert at index 1:\n");
    array_print(a);  // should print: 10 99 20 30

    
    array_pop_back(a);
    printf("After pop_back:\n");
    array_print(a);  // should print: 10 99 20

    return 0;
}
