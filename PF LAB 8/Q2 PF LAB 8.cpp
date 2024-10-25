#include <stdio.h>
int main(){
	int grade[4][4];
	
	printf("Enter the grades of 4 students\n");
	for (int i=0 ; i<4 ; i++){
		for (int j=0 ; j<4 ; j++){
			printf("Enter grade for student %d , subject %d:",i+1,j+1);
			scanf("%d",&grade[i][j]);
			
			if (grade[i][j]<0){
				grade[i][j]=0 ;
			}
		}
	}
	printf("grade after update are:\n");
	for(int i=0 ; i<4 ; i++){
		for(int j=0 ; j<4 ; j++){
			printf("%d",grade[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}