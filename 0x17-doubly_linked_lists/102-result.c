#include <stdio.h>

int isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int largestPalindrome = 0;
    int num1, num2;
    
    for (num1 = 100; num1 < 1000; num1++) {
        for (num2 = 100; num2 < 1000; num2++) {
            int product = num1 * num2;
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }
    
    FILE *file = fopen("102-result", "w");
    fprintf(file, "%d", largestPalindrome);
    fclose(file);

    return 0;
}

