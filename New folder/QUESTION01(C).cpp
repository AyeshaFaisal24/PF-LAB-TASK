#include<stdio.h>
int main(){
	int marks;
	
	printf("Enter your marks:");
    scanf("%d",&marks);
    
    if (marks<0 || marks>100){
	printf("Wrong Entry");
	}
	else if (marks>90 || marks<100){
		printf("Grade A");
	}
	else if (marks>=80 || marks<=89){
		printf("Grade B");
	}
	else if ("marks>=70 || marks<=79"){
		printf("Grade C");
	}
	else if (marks>=60 || marks<=69){
		printf("Grade C");
	}
	else {
		printf("Grade F");
	}
}