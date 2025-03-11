#include <stdio.h>
#include <stdlib.h>

void find_parentheses(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file"); // Print error message if file cannot be opened
        return;
    }

    int row = 1, col = 1; // Initialize row and column counters
    int ch; // To store the current character from the file
    int found_any = 0; // Flag to check if any parentheses were found

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) { 
        // Check if the character is an opening or closing parenthesis
        if (ch == '{' || ch == '}') {
            found_any = 1; // Mark that we found a parenthesis
            printf("Found '%c' at row %d, column %d\n", ch, row, col);
        }
        
        col++; // Increment column for each character read
        if (ch == '\n') { // If newline encountered, increment row and reset column
            row++;
            col = 1;
        }
    }

    if (!found_any) {
        printf("No parentheses found in the file.\n");
    }

    fclose(file); // Close the file after processing
}

int main() {
    // Use __FILE__ to get the current file name (program's own source file)
    char filename[] = __FILE__; 

    printf("Scanning file: %s\n", filename);
    find_parentheses(filename); // Call the function to find parentheses
    return 0;
}
