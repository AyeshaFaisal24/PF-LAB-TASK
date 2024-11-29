#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPoints;
    float *fees, totalProfit = 0.0;

    printf("Enter the total number of points in the faculty: ");
    scanf("%d", &numPoints);

    if (numPoints <= 0) {
        printf("Invalid number of points. Must be greater than 0.\n");
        return 1;
    }

    fees = (float *)malloc(numPoints * sizeof(float));
    if (fees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numPoints; i++) {
        printf("Enter fee for point %d: ", i + 1);
        scanf("%f", &fees[i]);

        while (fees[i] < 0) {
            printf("Fee cannot be negative. Re-enter fee for point %d: ", i + 1);
            scanf("%f", &fees[i]);
        }

        totalProfit += fees[i];
    }

    printf("\nTotal profit for faculty : %.2f\n", totalProfit);

    free(fees);

    return 0;
}
