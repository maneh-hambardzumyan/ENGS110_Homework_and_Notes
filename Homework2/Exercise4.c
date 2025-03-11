#include <stdio.h>
#include <string.h>

void compress_string(char *str) {
    if (str == NULL || *str == '\0') {
        return; // Handle null or empty string
    }

    char *read = str;   // Pointer for reading the original string
    char *write = str;  // Pointer for writing the compressed string
    int count;

    while (*read != '\0') {
        // Start counting occurrences of the current character
        char current_char = *read;
        count = 0;

        // Count consecutive occurrences of the current character
        while (*read == current_char) {
            count++;
            read++;  // Move to the next character
        }

        // Write the current character to the result
        *write = current_char;
        write++;

        // Write the count as a string
        if (count > 1) {
            char count_str[10]; // To store the count as a string
            snprintf(count_str, sizeof(count_str), "%d", count);
            // Write the count to the result
            for (int i = 0; count_str[i] != '\0'; i++) {
                *write = count_str[i];
                write++;
            }
        }
    }

    *write = '\0';  // Null-terminate the compressed string
}

int main() {
    char str[] = "aabbccccdde"; // Updated example string

    printf("Original string: %s\n", str);
    
    compress_string(str);  // Compress the string in-place

    printf("Compressed string: %s\n", str);

    return 0;
}
