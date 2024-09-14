#include <stdio.h>
int main (){
	int units;
	float electricity_bill ;
	
	printf("Enter total units consumed:");
	scanf("%d",&units);
	
	if (units<=30){
		electricity_bill = 0.60 * units;
		printf("your bill is=%0.2f\n",electricity_bill);
		}
	else if (units>=31 && units<=110){
		electricity_bill = 0.85 * units;
		printf("your bill is=%0.2f\n",electricity_bill);
	}
	else if (units>=111 && units<=210){
	    electricity_bill = 1.30 * units;
	    printf("your bill is=%0.2f\n",electricity_bill);
	}
	else {
		electricity_bill = 1.60 * units;
		printf("your bill is=%0.2f\n",electricity_bill);
	}
	printf("you will receive an extra surcharge of 15 percent\n");
    electricity_bill = electricity_bill * 0.15 + electricity_bill;
	printf("Total Bill=Rs%0.2f\n",electricity_bill);
	
	return 0;
}
	
	
	
	
	