#include <stdio.h>
#include <string.h>

void reverse(char str[], int i, int j) {
    if (i >= j)
        return;

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    reverse(str, i + 1, j - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str, 0, strlen(str) - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}

