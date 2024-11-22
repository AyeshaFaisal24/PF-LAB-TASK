#include <stdio.h>
#include <stdlib.h>

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    char line[1024]; 
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", lineNumber++, line);
    }

    fclose(file);
}

int main() {
    char filename[100];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    display_file(filename);

    return 0;
}
