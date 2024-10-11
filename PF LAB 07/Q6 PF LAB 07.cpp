#include <stdio.h>
int main(){
	int i , n=30 , array1[n] , min , max;
		
	printf("Enter %d elements:\n",n);
	for(i=0 ; i<n ; i++){
		scanf("%d",&array1[i]);
    }
	min=max=0;
	for(i=1 ; i<n ; i++){
		if(array1[i]<min){
			min=array1[i];
		}else if(array1[i]>max){
			max=array1[i];
		}
	}
	printf("minimum number is:%d\n",min);
	printf("maximum number is:%d",max);
	
	return 0;
}
