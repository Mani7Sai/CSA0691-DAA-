#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(const char str[]) {
    int length = strlen(str);
    
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}
