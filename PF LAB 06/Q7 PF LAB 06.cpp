#include <stdio.h>
int main(){
	int number, original_n, digit1, digit2, digit3, result;
	printf("Enter a 3 digit number:");
	scanf("%d",&number);
	original_n = number;
	
	digit1 = number % 10;         
    number = number / 10;             

    digit2 = number % 10;         
    number = number / 10;           

    digit3 = number;    
	
	result = (digit1*digit1*digit1)+(digit2*digit2*digit2)+(digit3*digit3*digit3);      
	
	if(result==original_n){
		printf("Given number is an armstrong number");
	}  else {
		printf("Given number is not an armstrong number");
	}
	return 0;
}