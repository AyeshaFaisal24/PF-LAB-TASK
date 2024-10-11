
#include <stdio.h>
int main(){
    int number;

    do {
        printf("Enter a positive number:");
        scanf("%d", &number);
        if (number<0){
        	printf("NO\n");
		}
    } while (number <= 0); 
    
    printf("You entered a right number: %d",number);

    return 0;
}

