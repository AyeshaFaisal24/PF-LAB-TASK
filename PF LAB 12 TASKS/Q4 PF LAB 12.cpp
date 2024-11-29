#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("\nEnter the number of elements in the sequence: ");
        scanf("%d", &N);

        int *A = (int *)malloc(N * sizeof(int));
        if (A == NULL) {
            printf("No memory allocation.\n");
            return 1;
        }

        int frequency[10001] = {0};

        printf("Enter the elements of the sequence:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            frequency[A[i]]++;
        }

        int maxFrequency = 0, result = 10001;
        for (int i = 1; i < 10001; i++) {
            if (frequency[i] > maxFrequency || 
                (frequency[i] == maxFrequency && i < result)) {
                maxFrequency = frequency[i];
                result = i;
            }
        }

        printf("The number with the highest frequency is: %d\n", result);

        free(A);
    }

    return 0;
}
