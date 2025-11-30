#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    fclose(file);
    printf("All contents of data.txt have been deleted.\n");

    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    if (fgetc(file) == EOF)
        printf("File is empty.\n");
    else
        printf("File is not empty.\n");

    fclose(file);
    return 0;
}

