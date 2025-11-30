#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char words[5][21];
    int i;

    printf("Enter 5 words (max 20 characters each):\n");
    for (i = 0; i < 5; i++) {
        scanf("%20s", words[i]);
    }

    printf("\nPalindrome Check Results:\n");
    for (i = 0; i < 5; i++) {
        if (isPalindrome(words[i]))
            printf("%s: Palindrome\n", words[i]);
        else
            printf("%s: Not Palindrome\n", words[i]);
    }

    return 0;
}

