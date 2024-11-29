#include <stdio.h>
#include <stdlib.h>

void makeEven(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {  
            array[i]--;  
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("No memory allocation.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    makeEven(array, n);

    printf("Array with only even numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
