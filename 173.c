/*Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n
*/
#include <stdio.h>

int intSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 1, high = n / 2;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow
        if (mid <= n / mid) {
            ans = mid;        // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", intSqrt(n));
    return 0;
}