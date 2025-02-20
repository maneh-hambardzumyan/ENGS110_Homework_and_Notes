#include <stdio.h>

int main() {
    int N, sum = 0;
    
    printf("Enter a number (1-1000): ");
    scanf("%d", &N);
    
    if (N < 1 || N > 1000) {
        printf("Invalid input! Please enter a number between 1 and 1000.\n");
        return 1;
    }
    
    for (int i = 1; i < N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    
    printf(" %d is: %d\n", N, sum);
    
    return 0;
}
