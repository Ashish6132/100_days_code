//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int linearSearch(int arr[], int n, int k) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Key found at index %d\n", i);
            printf("Number of comparisons: %d\n", comparisons);
            return i;
        }
    }
    printf("Key not found\n");
    printf("Number of comparisons: %d\n", comparisons);
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 30;
    linearSearch(arr, n, k);
    return 0;
}