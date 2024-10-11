#include <stdio.h>
int main() {
    int number, i, isPrime = 1 , a = 0, b = 1, nextTerm = 0;;

    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i < number; i++) {
            if (number % i == 0) {
                isPrime = 0;  
            }
        }
    }
    if (isPrime) {
        printf("%d is a prime number.\n", number);
        printf("Fibonacci series up to %d:\n", number);

        printf("%d, ", a);
        if (number > 0) {
            printf("%d, ", b);
        }

        nextTerm = a + b;
        while (nextTerm <= number) {
            printf("%d, ", nextTerm);
            a = b;
            b = nextTerm;
            nextTerm = a + b;
        }
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}