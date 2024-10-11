#include <stdio.h>
int main(){
	int i , sum=0 , n=15 , array1[n];
	
	printf("Enter %d elements you want the sum of:",n);
	for(i=0 ; i<n ; i++){
		scanf("%d",&array1[i]);
		for(i=0 ; i<n ; i++){
			sum+=array1[i];
		}
	}
	printf("sum is %d",sum);
	
	return 0;
}