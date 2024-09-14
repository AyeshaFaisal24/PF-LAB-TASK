#include <stdio.h>
int main (){
    int  amount;
	float discounted_amount , saved_amount;
	
	printf("Enter the amount of online shopping:");
	scanf("%d",&amount);
	
	if (amount<1500){
		discounted_amount = amount - amount * 0.07;
	}
	else if (amount<3000 && amount>1500){
		discounted_amount = amount - amount * 0.12;
	}
	else if (amount<5000 && amount>3000){
		discounted_amount = amount - amount * 0.22;
	}
	else if (amount<5000){
		discounted_amount = amount - amount * 0.30;
	}
	
	printf("Your amount after discount is:Rs%0.2f\n",discounted_amount);
    saved_amount = amount - discounted_amount;
    printf("Your saved amount is:Rs%0.2f\n",saved_amount);

	return 0;
}
