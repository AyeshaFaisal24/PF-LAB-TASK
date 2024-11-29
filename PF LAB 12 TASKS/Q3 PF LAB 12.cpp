#include <stdio.h>
#include <stdlib.h>

void addNumber(float **array, int *size, int *capacity, float number) {
    if (*size == *capacity) {
        *capacity *= 2;
        *array = (float *)realloc(*array, (*capacity) * sizeof(float));
        if (*array == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    (*array)[(*size)++] = number;
}

void displayNumbers(float *array, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void removeLastNumber(float **array, int *size, int *capacity) {
    if (*size > 0) {
        (*size)--;
        if (*size < *capacity / 4) {
            *capacity /= 2;
            *array = (float *)realloc(*array, (*capacity) * sizeof(float));
            if (*array == NULL) {
                printf("No memory reallocation.\n");
                exit(1);
            }
        }
    } else {
        printf("Array is empty , cannot remove any number.\n");
    }
}

int main() {
    int capacity = 4, size = 0, choice;
    float *array = (float *)malloc(capacity * sizeof(float));
    if (array == NULL) {
        printf("No memory allocation.\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Add a number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            float number;
            printf("Enter a floating-point number: ");
            scanf("%f", &number);
            addNumber(&array, &size, &capacity, number);
        } else if (choice == 2) {
            displayNumbers(array, size);
        } else if (choice == 3) {
            removeLastNumber(&array, &size, &capacity);
        }
    } while (choice != 4);

    free(array);
    return 0;
}
