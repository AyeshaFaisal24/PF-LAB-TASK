#include <stdio.h>
int main(){
	int percentage;
	char grade;
	
	printf("Enter your percentage from 0 to 100:");
	scanf("%d",&percentage);
	
	grade = (percentage >= 90 && percentage <= 100) ? 'A' : 
            (percentage >= 80 && percentage <= 89)  ? 'B' :
            (percentage >= 70 && percentage <= 79)  ? 'C' :
            (percentage >= 60 && percentage <= 69)  ? 'D' : 'F';
	 
	 printf("Grade is %c",grade);
	 
	 return 0;
}
