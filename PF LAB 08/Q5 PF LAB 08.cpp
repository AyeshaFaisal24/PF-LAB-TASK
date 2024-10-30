#include <stdio.h>
int main() {
	int array[4][4] ;
	
	for (int i=0 ; i<4 ; i++){
		for (int j=0 ; j<4 ; j++){
			printf("Enter score of team %d ,round %d:",i+1,j+1);
			scanf("%d",&array[i][j]);
		}
	}
	
	int	max_array=array[0][0];
	
	for (int i=0 ; i<4 ; i++){
		for (int j=0 ; j<4 ; j++){
			if (array[i][j]>max_array){
				max_array = array [i][j];
			}
		}
	}

	
	for (int i=0 ; i<4 ; i++){
		for (int j=0 ; j<4 ; j++){
			for (int y=0 ; y<4 ; y++){
				for (int z=0 ; z<4 ; z++){
					if (array[i][j]<array[y][z]){
						int temp = array[i][j];
						array[i][j] = array[y][z];
						array[y][z] = temp;
					}
				}
			}
		}
	}
	
	printf("Scores in ascending order are:\n");
	for (int i=0 ; i<4 ; i++){
		for (int j=0 ; j<4 ; j++){
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}