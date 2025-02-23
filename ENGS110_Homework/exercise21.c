#include <stdio.h>

int main() {
    int N, sum = 0;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Input N whole numbers and calculate their sum
    printf("Enter %d whole numbers:\n", N);
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);  // Input each number
        sum += num;  // Add the number to the sum
    }

    // Output the sum
    printf("The sum of all the numbers is: %d\n", sum);

    return 0;
}
