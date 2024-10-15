#include <stdio.h>
int main() {
    int array1[12] , array2[6]; 
    
    printf("Enter 12 numbers:\n");
    for(int i = 0; i < 12; i++) {
        scanf("%d", &array1[i]);
    }
    
    for(int i = 0; i < 6; i++) {
        array2[i] = array1[2 * i] + array1[2 * i + 1];  
    }
    
    printf("The sum of consecutive pairs are:\n");
    for(int i = 0; i < 6; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    return 0;
}