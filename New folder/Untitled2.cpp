#include <stdio.h>
int main(){
	int n1 , n2;
	
	printf("Enter first and second number:");
	scanf("%d\n%d",&n1 ,&n2);
	
	if (n1>n2){
		if (n1>100){
			printf("First number is significantly larger");
		}
		else{
				printf("first number is larger");
			}
	}else if (n1<n2){
		if (n1<0){
			printf("First number is negative and smaller");
		}
		else{
				printf("First number is smaller");
	    }
	}else {
		printf("both are equal");
		}

    return 0;
}