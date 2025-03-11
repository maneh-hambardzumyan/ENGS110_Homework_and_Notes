#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void search_csv(const char *filename, int column, const char *search_value) {
    FILE *file = fopen(filename, "r"); // Open the CSV file in read mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int found = 0;

    // Read the CSV file line by line
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        
        // Skip the first line (header)
        if (line_number == 1) {
            continue;
        }

        // Split the line into columns using the comma as a delimiter
        char *token;
        int current_column = 1;
        int match_found = 0;

        token = strtok(line, ","); // Get the first token (column)
        while (token != NULL) {
            // If we are in the specified column and the value matches
            if (current_column == column && strcmp(token, search_value) == 0) {
                match_found = 1; // Set match found flag
                break;
            }
            token = strtok(NULL, ","); // Get the next token
            current_column++;
        }

        // If the value was found in the specified column, print the entire row
        if (match_found) {
            printf("Row %d: %s", line_number, line);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching rows found for column %d and value '%s'.\n", column, search_value);
    }

    fclose(file); // Close the file after processing
}

int main() {
    char filename[] = "example"; // CSV file name
    int column;
    char search_value[100];

    // Prompt the user for column number and search value
    printf("Enter column number to search: ");
    scanf("%d", &column);
    getchar(); // Consume newline after reading integer

    printf("Enter the search value: ");
    fgets(search_value, sizeof(search_value), stdin);
    search_value[strcspn(search_value, "\n")] = 0; // Remove trailing newline

    // Call the function to search the CSV file
    search_csv(filename, column, search_value);

    return 0;
}
