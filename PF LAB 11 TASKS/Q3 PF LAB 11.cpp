#include <stdio.h>
#include <ctype.h> // for toupper

int main() {
    FILE *srcFile, *destFile;
    char ch;

    srcFile = fopen("source.txt", "r");
    if (!srcFile) {
        printf("Error: Could not open source file.\n");
        return 1;
    }

    destFile = fopen("destination.txt", "w");
    if (!destFile) {
        printf("Error: Could not open destination file.\n");
        fclose(srcFile);
        return 1;
    }
    
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(toupper(ch), destFile);
    }

    printf("Source file copied with uppercase conversion to Destination file.\n");

    fclose(srcFile);
    fclose(destFile);

    return 0;
}
