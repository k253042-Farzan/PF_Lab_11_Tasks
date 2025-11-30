#include <stdio.h>
#include <ctype.h>

int countVowels(char str[], int index) {
    if (str[index] == '\0') 
        return 0;

    char ch = tolower(str[index]);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1 + countVowels(str, index + 1);
    else
        return countVowels(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    int vowels = countVowels(str, 0);
    printf("Number of vowels: %d\n", vowels);

    return 0;
}

