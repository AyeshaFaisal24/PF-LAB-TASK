#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents, *numGrades;
    float **grades;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    numGrades = (int *)malloc(numStudents * sizeof(int));
    if (numGrades == NULL) {
        printf("No Memory Allocation.\n");
        return 1;
    }

    grades = (float **)malloc(numStudents * sizeof(float *));
    if (grades == NULL) {
        printf("No Memory Allocation.\n");
        free(numGrades);
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter the number of grades for student %d: ", i + 1);
        scanf("%d", &numGrades[i]);

        grades[i] = (float *)malloc(numGrades[i] * sizeof(float));
        if (grades[i] == NULL) {
            printf("No Memory Allocation.\n");
            for (int j = 0; j < i; j++) {
                free(grades[j]);
            }
            free(grades);
            free(numGrades);
            return 1;
        }

        for (int j = 0; j < numGrades[i]; j++) {
            printf("Grade %d: ", j + 1, i + 1);
            scanf("%f", &grades[i][j]);
        }
    }

    printf("\nGrades entered:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < numGrades[i]; j++) {
            printf("%.2f ", grades[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);
    free(numGrades);

    return 0;
}
