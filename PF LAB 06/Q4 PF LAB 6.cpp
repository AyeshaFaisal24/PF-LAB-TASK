#include <stdio.h>
int main() {
    int number;
    int sum = 0;

    do{
    printf("Enter a number: ");
    scanf("%d", &number);
    sum += number;
    	printf("Current sum: %d\n", sum);
	}while (number != 0); 

    printf("Final sum: %d\n because of '0' as input", sum);

    return 0;
}