#include <stdio.h>
int main(){
	int hours;
	
	printf("Enter hours in 24 hour format:");
	scanf("%d",&hours);
	
	if (hours<0 || hours>23){
		printf("Invalid Input\n");
	}
	else if (hours>=6 && hours<12){
		printf("Good Morning\n");
	}
	else if (hours>=12 && hours<18){
		printf("Good Afternoon\n");
	}
	else if (hours>=18 && hours<24){
		printf("Good Evening\n");
	}
	else {
		printf("Good Night\n");
	}
	return 0;
}