/*For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

// Merge function that counts smaller elements
void merge(int arr[], int temp[], int left, int mid, int right, int count[]) {
    int i = left;      // left subarray
    int j = mid + 1;   // right subarray
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            count[i] += rightCount; // key line
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            rightCount++; // count smaller on right
        }
    }

    while (i <= mid) {
        count[i] += rightCount; // remaining left elements
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

// Merge Sort that counts smaller elements
void mergeSort(int arr[], int temp[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);
        merge(arr, temp, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n], count[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[i] = 0; // initialize count
    }

    mergeSort(arr, temp, 0, n - 1, count);

    // Print counts
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}