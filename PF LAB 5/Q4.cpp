#include <stdio.h>
int main(){
	float purchase_amount;
	int membership;
	
	printf("Enter the purchase amount:");
	scanf("%f", &purchase_amount);
	printf("Enter membership status(1/0):");
	scanf("%d", &membership);
	
    (purchase_amount>100 && membership==1)? printf("You will get the discount") : printf("You will not get the dicount");
	
	return 0;
}