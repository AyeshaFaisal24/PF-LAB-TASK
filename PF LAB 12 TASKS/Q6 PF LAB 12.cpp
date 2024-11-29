#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *array, largest;

    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1;
    }

    array = (float *)malloc(n * sizeof(float));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    largest = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    printf("The largest element is: %.2f\n", largest);

    free(array);

    return 0;
}
