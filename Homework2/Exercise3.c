#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    if (str == NULL || *str == '\0') {
        return; // Handle null or empty string
    }

    // Pointers to the start and end of the string
    char *start = str;
    char *end = str + strlen(str) - 1;

    // Swap characters until the pointers meet in the middle
    while (start < end) {
        // Swap characters at start and end
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers towards the center
        start++;
        end--;
    }
}

int main() {
    char str[] = "I have done my homework!"; // Example string

    printf("Original string: %s\n", str);
    
    reverse_string(str); // Reverse the string in-place

    printf("Reversed string: %s\n", str);

    return 0;
}
