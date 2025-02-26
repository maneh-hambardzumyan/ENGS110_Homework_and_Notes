include <stdio.h>
#include <ctype.h>  // For the functions toupper() and tolower()

// Function to convert the string to uppercase
void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);  // Convert each character to uppercase
    }
}

// Function to convert the string to lowercase
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);  // Convert each character to lowercase
    }
}

int main() {
    char str[100];  // Array to store the input string
    int choice;  // To store user choice (1 for uppercase, 2 for lowercase)
    
    // Prompt the user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Use fgets to read a line including spaces
    
    // Remove the newline character that fgets might add
    str[strcspn(str, "\n")] = '\0';
    
    // Ask user whether to convert to uppercase or lowercase
    printf("Choose an option:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    // Perform the conversion based on user input
    if (choice == 1) {
        toUpperCase(str);  // Convert to uppercase
        printf("String in uppercase: %s\n", str);
    } else if (choice == 2) {
        toLowerCase(str);  // Convert to lowercase
        printf("String in lowercase: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}