// Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}
int main() {
    char codeName[100];
    printf("Enter the code name: ");
    scanf("%s", codeName);
    
    if (isPalindrome(codeName)) {
        printf("%s is a palindrome.\n", codeName);
    } else {
        printf("%s is not a palindrome.\n", codeName);
    }
    
    return 0;
}