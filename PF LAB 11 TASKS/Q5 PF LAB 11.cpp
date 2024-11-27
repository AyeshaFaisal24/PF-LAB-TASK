#include <stdio.h>

struct phoneNumber{
	int areaCode , exchange , number;
};

int main(){
	struct phoneNumber N1 = {121 , 456 , 789};
	struct phoneNumber N2;
	
	printf("Enter area code:");
	scanf("%d",&N2.areaCode);
	printf("Enter the exchange number:");
	scanf("%d",&N2.exchange);
	printf("Enter number:");
	scanf("%d",&N2.number);
	
	printf("My number is(%d) %d-%d\n",N1.areaCode,N1.exchange,N1.number);
	printf("Your number is(%d) %d-%d",N2.areaCode,N2.exchange,N2.number);
	
	return 0;
}