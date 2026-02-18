//Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>
#define MAX_SIZE 100
void rotateRight(int arr[], int n, int k) {
    k = k % n;
    int temp[MAX_SIZE];
    
 
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    

    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
   
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}
int main() {
    int arr[MAX_SIZE];
    int n, k;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);
    
    rotateRight(arr, n, k);
    
    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
