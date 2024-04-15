#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int num = x; // Store the original number for comparison later
    int digit_num = 0;
    
    // Calculate the number of digits
    while (num != 0) {
        num /= 10;
        digit_num++;
    }

    // Allocate memory for the array dynamically
    int *arr = (int *)malloc(digit_num * sizeof(int));
    if (arr == NULL) {
        // Error handling if memory allocation fails
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    num = x; // Reset num to the original number
    // Store the digits in an array
    for (int i = 0; i < digit_num; i++) {
        arr[i] = num % 10;
        num /= 10;
    }

    // Check for palindrome
    for (int i = 0; i < digit_num / 2; i++) {
        if (arr[i] != arr[digit_num - i - 1]) {
            free(arr); // Free dynamically allocated memory
            return false; // If any pair of digits doesn't match, it's not a palindrome
        }
    }

    free(arr); // Free dynamically allocated memory
    return true; // If all pairs match, it's a palindrome
}
int main() {
    bool check = isPalindrome(0);
    if (check)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    
    return 0;
}
