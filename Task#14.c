#include <stdio.h>
#include <time.h>

int main() {
    FILE *file;
    time_t t;
    struct tm *tm_info;

    t = time(NULL);
    tm_info = localtime(&t);

    file = fopen("log.txt", "a");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fprintf(file, "Program executed on: %s", asctime(tm_info));

    fclose(file);

    printf("Execution time logged in log.txt\n");

    return 0;
}

