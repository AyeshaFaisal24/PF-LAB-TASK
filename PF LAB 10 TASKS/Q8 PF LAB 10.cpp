#include <stdio.h>

void printtArray(int n , int array[] ,int index){
	if(index==n){
		return;
	}else{
		printf("Element %d is : %d\n",index+1 , array[index]);
	}
	printtArray(n,array,index+1);
}

int main(){
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	
	int array[n];
	for (int i=0 ; i<n ; i++){
		printf("Enter the element %d:",i+1);
		scanf("%d",&array[i]);
	}
	printtArray(n,array,0);
	return 0;
}