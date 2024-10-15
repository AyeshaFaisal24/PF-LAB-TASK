#include <stdio.h>
int main() {
    int array[10];
    int temp;   
    
    for(int i = 0; i < 10; i++) {
    	printf("Enter 10 numbers:\n");
        scanf("%d", &array[i]);
    }
    
    temp = array[0];
    
    for(int i = 0; i < 9; i++) {
        array[i] = array[i + 1];
    }
    
    array[9] = temp;
    
    printf("Array after shifting left by 1 position:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}