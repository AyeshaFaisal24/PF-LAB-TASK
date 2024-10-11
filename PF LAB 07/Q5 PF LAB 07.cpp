#include <stdio.h>
int main(){
	int i, n=20 , array1[n];
	
	printf("Enter %d elements:\n",n);
	for(i=0 ; i<n ; i++){
		scanf("%d",&array1[i]);
	}	
	printf("Number in revese order are:");
	
	for(i=n-1 ; i>0 ; i--){
		printf("%d",array1[i]);
	}
	
	return 0;
}
