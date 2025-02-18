#include <stdio.h>

int main() {
    int num1, num2;
    char op;
<<<<<<< HEAD:ENGS110/arithmeticoperations.c
    
    printf("Enter an arithmetic expression (number operator number): ");
    scanf("%d %c %d", &num1, &op, &num2);
    
  
=======
      
    printf("Enter an arithmetic expression (number operator number): ");
    scanf("%d %c %d", &num1, &op, &num2);
    
>>>>>>> 9086e5b153a478fb97e7bfcab2f31f70e2bb6443:ENGS110/arithmetic.c
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
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
               
                printf("%d / %d = %.3f\n", num1, num2, (double)num1 / num2);
            }
            break;
            
        default:
            printf("Error: Invalid operator.\n");
    }
    
    return 0;
}
