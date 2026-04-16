/*Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.
*/
#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;

    // Hash map using arrays (simple approach)
    int hash[20001];  // To handle negative sums
    for (int i = 0; i < 20001; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = 10000; // shift for negative index

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLength = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            int length = i - prevIndex;
            if (length > maxLength)
                maxLength = length;
        } else {
            // store first occurrence
            hash[sum + offset] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));

    return 0;
}