#include <stdio.h>
int main(){
	int n;
	
	printf("Enter the side length for your square:");
	scanf("%d",&n);
	
	int half = n/2 ;
	
	for (int i=0 ; i<n ;i++){
		for (int j=0 ; j<n ; j++){
			
			if (i==j){
				printf("*");
			}
			else if (i==0 || j==0 || i==n-1 || j==n-1){
				printf("*");
			}
			else if (half==i && half==j){
				printf("*");
			}
			else if ((i+j) == (n-1)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}