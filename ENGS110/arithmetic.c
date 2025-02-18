#include <stdio.h>

int main() {
    int num1, num2;
    char op;
      
    printf("Enter an arithmetic expression (number operator number): ");
    scanf("%d %c %d", &num1, &op, &num2);
    
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
            
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
            
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
            
        case '/':
            // Check for division by zero
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                // Print division result as a floating-point number (3 decimal places)
                printf("%d / %d = %.3f\n", num1, num2, (double)num1 / num2);
            }
            break;
            
        default:
            printf("Error: Invalid operator.\n");
    }
    
    return 0;
}
