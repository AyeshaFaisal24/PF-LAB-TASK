#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &N);

        int *array = (int *)malloc(N * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the elements of the array:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        char operation;
        printf("\nEnter operation (I for insertion, D for deletion): ");
        scanf(" %c", &operation);

        if (operation == 'I') {
            int position, value;
            printf("Enter the position (0-based) and value to insert: ");
            scanf("%d %d", &position, &value);

            array = (int *)realloc(array, (N + 1) * sizeof(int));
            if (array == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }

            for (int i = N; i > position; i--) {
                array[i] = array[i - 1];
            }
            array[position] = value;
            N++; 

        } else if (operation == 'D') {
            int position;
            printf("Enter the position (0-based) to delete: ");
            scanf("%d", &position);

            for (int i = position; i < N - 1; i++) {
                array[i] = array[i + 1];
            }
            N--; 
            array = (int *)realloc(array, N * sizeof(int));
            if (N > 0 && array == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }
        } else {
            printf("Invalid operation.\n");
        }

        printf("Modified array: ");
        printArray(array, N);

        free(array);
    }

    return 0;
}
