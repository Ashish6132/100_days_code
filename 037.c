//Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#define MAX_SIZE 100
void findClosestToZero(int arr[], int n) {
    int closestSum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }
    
    printf("Two elements whose sum is closest to zero: %d and %d\n", num1, num2);
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
    
    findClosestToZero(arr, n);
    
    return 0;
}