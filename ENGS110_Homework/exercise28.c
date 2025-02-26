#include <stdio.h>
#include <string.h>

// Function to check if str2 is a substring of str1
int isSubstring(char str1[], char str2[]) {
    // If str2 is empty, it is trivially a substring of str1
    if (str2[0] == '\0') {
        return 1;
    }

    // Loop through str1 to check if str2 is a substring
    for (int i = 0; str1[i] != '\0'; i++) {
        // Check if the substring str2 starts at position i in str1
        int j = 0;
        while (str1[i + j] == str2[j] && str2[j] != '\0') {
            j++;
        }

        // If we've matched all characters of str2, it's a substring
        if (str2[j] == '\0') {
            return 1;
        }
    }
    
    // If no match was found, it's not a substring
    return 0;
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

    // Check if str2 is a substring of str1
    if (isSubstring(str1, str2)) {
        printf("'%s' is a substring of '%s'.\n", str2, str1);
    } else {
        printf("'%s' is not a substring of '%s'.\n", str2, str1);
    }

    return 0;
}
