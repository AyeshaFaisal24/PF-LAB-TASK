#include <stdio.h>
int main(){
	int array[3][3] ,  r_sum[3] = {0}, c_sum[3] = {0} ;
	
	for (int i=0 ; i<3 ; i++){
		for (int j=0 ; j<3 ; j++){
			printf("Enter score for participant %d , activity %d:",i+1,j+1);
			scanf("%d",&array[i][j]);
		}
	}
	
	for (int i=0 ; i<3 ; i++){
		for (int j=0 ; j<3 ; j++){
		r_sum[i]+=array[i][j];
		c_sum[j]+=array[i][j];
		}
	}
	printf("\nScore of each participant is\n");
	for(int i=0 ; i<3 ; i++){
		printf("participant %d:%d\n",i+1,r_sum[i]);
	}
	
	printf("\nScore for each activity is\n");
	for(int j=0 ; j<3 ; j++){
		printf("activity %d:%d\n",j+1,c_sum[j]);
	}
	
	return 0;

}