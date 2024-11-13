#include <stdio.h>

int add(int *n, int *sum) {
    if (*n == 0) {  
        return *sum;
    } else {
        int d1 = *n % 10;  
        *sum += d1;        
        *n /= 10;         
    }
     return add(n, sum); 
}

int main() {
    int n;
    int sum = 0;

    printf("Enter the number: ");
    scanf("%d", &n);

    int _sum = add(&n, &sum); 
    printf("Sum of digits is: %d\n", _sum);

    return 0;
}
