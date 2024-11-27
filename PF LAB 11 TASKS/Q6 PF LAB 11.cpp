#include <stdio.h>

struct invoice{
	char partNumber[10] , description[50];
	int quantity;
	float price;
};

void calculate(struct invoice I[] , int n){
	float invoiceAmount=0 ,	totalInvoiceAmount=0 ;
	for (int i=0 ; i<n ; i++){
		if(I[i].quantity < 0){
			I[i].quantity = 0;
		}
		if(I[i].price < 0){
			I[i].price = 0;
		}
		invoiceAmount = I[i].quantity * I[i].price;
		printf("Invoice amount of item %d is : %.2f\n",i+1,invoiceAmount);
		totalInvoiceAmount+=invoiceAmount;
	}
	printf("Total invoice amount of all itms is %.2f",totalInvoiceAmount);
}

int main(){
	struct invoice I[4] ={
		{"part#01" , "For external use only" , 3 , 23.5},
		{"part#02" , "Keep out of the reach of children" , 8 , 2.9},
		{"part#03" , "Best for dry skin" , 19 , 3.98}
	};
	
	calculate(I,3);
	
	return 0;
}