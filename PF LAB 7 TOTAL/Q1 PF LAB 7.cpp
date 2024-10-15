#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7 , 8 , 9, 10};
	int size = 10;
    
    int num, found = 0; 

    printf("Enter a number to search: ");
    scanf("%d", &num);

    for(int i = 0; i < size; i++) {
        if(array[i] == num) {
            printf("Number %d found at index %d.\n", num, i);
            found = 1; 
            break; 
        }
    }
    if(!found) {
        printf("Number %d not found in the array.\n", num);
	}
    return 0;
}