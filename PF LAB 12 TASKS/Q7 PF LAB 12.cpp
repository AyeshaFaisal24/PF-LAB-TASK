#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("No memory allocation.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("No memory allocation\n");
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    int rowToModify, colToModify, newValue;
    printf("\nEnter the row and column to modify (0-based index): ");
    scanf("%d %d", &rowToModify, &colToModify);
    printf("Enter the new value: ");
    scanf("%d", &newValue);

    if (rowToModify >= 0 && rowToModify < rows && colToModify >= 0 && colToModify < cols) {
        array[rowToModify][colToModify] = newValue;
    } else {
        printf("Invalid indices. No modification made.\n");
    }

    printf("\nThe modified array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
