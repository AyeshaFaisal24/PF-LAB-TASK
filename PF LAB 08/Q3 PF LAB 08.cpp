#include <stdio.h>
int main(){
	int n;
	
	printf("Enter the number:");
	scanf("%d",&n);
	
	for (int i=n ; i>=1 ; i--){
		for (int j=0 ; j<(n-i) ; j++){
			printf(" ");
		}
		for (int j=i ; j>=1 ;j-- ){
			printf("%d ",j);
		}
		printf("\n");
	}
	
	for (int i=2 ; i<=n ; i++){
		for (int j=0 ; j<(n-i) ; j++){
			printf(" ");
		}
		for (int j=i ; j>=1 ;j-- ){
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}