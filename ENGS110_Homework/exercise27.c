#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sort the characters in a string
void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (str[i] > str[j]) {
                // Swap characters if they are out of order
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to check if two strings are anagrams
int areAnagrams(char str1[], char str2[]) {
    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;  // Not anagrams
    }
    
    // Convert both strings to lowercase for case-insensitive comparison
    for (int i = 0; str1[i]; i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; str2[i]; i++) {
        str2[i] = tolower(str2[i]);
    }

    // Sort both strings
    sortString(str1);
    sortString(str2);

    // Compare the sorted strings
    if (strcmp(str1, str2) == 0) {
        return 1;  // They are anagrams
    } else {
        return 0;  // Not anagrams
    }
}

int main() {
    char str1[100], str2[100];
    
    // Input the two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Remove the newline character that fgets may add
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("'%s' and '%s' are anagrams.\n", str1, str2);
    } else {
        printf("'%s' and '%s' are not anagrams.\n", str1, str2);
    }

    return 0;
}
