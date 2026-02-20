// Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
#define MAX_SIZE 100
int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }
    
    return count;
}
int main() {
    int arr[MAX_SIZE];
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = countZeroSumSubarrays(arr, n);
    printf("Number of subarrays with sum equal to zero: %d\n", result);
    
    return 0;
}