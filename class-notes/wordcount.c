#include <stdio.h>

#define IN 1  // Inside a word
#define OUT 0 // Outside a word

int main() {
    int state = OUT; // Initial state is OUT
    int word_count = 0;
    char ch;

    printf("Enter text to count words (Ctrl+D to end):\n");

    // Loop to read characters until EOF (Ctrl+D to end input on Mac/Linux)
    while ((ch = getchar()) != EOF) {
        // Check if the character is a space, tab, or newline
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            // If we're inside a word, transition to OUT state
            if (state == IN) {
                state = OUT;
            }
        } else { // If it's a non-space character (part of a word)
            // If we're outside a word, transition to IN state and count the word
            if (state == OUT) {
                state = IN;
                word_count++; // Found a new word
            }
        }
    }

    // Print the total word count
    printf("Total word count: %d\n", word_count);

    return 0;
}
