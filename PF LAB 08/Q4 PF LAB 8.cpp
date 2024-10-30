#include <stdio.h>
int main(){
	int m , n , sum=0;
	
	printf("Enter the first dimension for your matrix:");
	scanf("%d",&m);
	printf("Enter the second dimension for your matrix:");
	scanf("%d",&n);
	
	
	int matrix1[m][n] , matrix2[m][n] , result[m][n] ;

	printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
	
  printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

   for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    printf("The resulting matrix after addition is:\n");
    for (int i=0 ; i<m ; i++){
    	for (int j=0 ; j<n ; j++){
    		printf("%d\t",result[i][j]);
		}
		printf("\n");
	}

	return 0;
}