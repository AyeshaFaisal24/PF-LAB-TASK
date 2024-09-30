#include <stdio.h>
int main(){
	int number;
	
	printf("Enter number:");
	scanf("%d",&number);
	
	(number & 1)? printf("Number is odd") : printf("Number is even");
	
	return 0;
}