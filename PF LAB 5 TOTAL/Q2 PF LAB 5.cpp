#include <stdio.h>
int main(){
	int ANGLE1 , ANGLE2 , ANGLE3 , sum;
	
	printf("Enter angle 1:");
	scanf("%d",&ANGLE1);
	printf("Enter angle 2:");
	scanf("%d",&ANGLE2);
	printf("Enter angle 3:");
	scanf("%d",&ANGLE3);
	
	if (ANGLE1>=0 && ANGLE2>=0 && ANGLE3>=0){
		sum = ANGLE1 + ANGLE2 + ANGLE3;
		if (sum == 180){
			printf("Triangle is valid");
		}else{
			printf("Invalid triangle");
		}
    }else{
		printf("Angle cannot be negative");
    }
    return 0;
}