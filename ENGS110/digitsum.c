#include <stdio.h>

int sum_of_digits(int num) {
    int sum = 0;
    if (num < 0) num = -num;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int number;
    scanf("%d", &number);
    printf("%d\n", sum_of_digits(number));
    return 0;
}
