#include <stdio.h>
#define MAX_SIZE 100
void deleteAtPosition(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n, pos;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter position to delete from (1 to %d): ", n);
    scanf("%d", &pos);
    
    deleteAtPosition(arr, &n, pos);
    
    printf("Array after deletion:\n");
    printArray(arr, n);
    
    return 0;
}