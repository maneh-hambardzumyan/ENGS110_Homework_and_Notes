#include <stdio.h>

int main() {
    int grade;

    // Prompt user to enter grade
    printf("Enter your grade (0-100): ");
    scanf("%d", &grade);

    // Validate input range
    if (grade < 0 || grade > 100) {
        printf("Invalid grade! Please enter a value between 0 and 100.\n");
    } 
    else if (grade < 60) {
        printf("Your grade: F\n");
    } 
    else if (grade < 70) {
        printf("Your grade: D\n");
    } 
    else if (grade < 80) {
        printf("Your grade: C\n");
    } 
    else if (grade < 90) {
        printf("Your grade: B\n");
    } 
    else {
        printf("Your grade: A\n");
    }

    return 0;
}
