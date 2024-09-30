#include <stdio.h>
int main(){
	int number , counter;
    printf("Enter number:");
    scanf("%d",&number);
	counter = 0;
	(number & 1)? counter+=1: counter+=0;
	(number & 2)? counter+=1: counter+=0;
	(number & 4)? counter+=1: counter+=0;
	(number & 8)? counter+=1: counter+=0;
	(number & 16)? counter+=1: counter+=0;
	(number & 32)? counter+=1: counter+=0;
	(number & 64)? counter+=1: counter+=0;
	(number & 128)? counter+=1: counter+=0;

     printf("Counter is %d", counter);
     
     return 0 ;
 }


