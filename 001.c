#include <stdio.h>
#define MAX_SIZE 100
void insertAtPosition(int arr[], int *n, int x, int pos) {
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = x;
    (*n)++;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX_SIZE];
    int n, x, pos;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to insert: ");
    scanf("%d", &x);
    
    printf("Enter position to insert at (1 to %d): ", n + 1);
    scanf("%d", &pos);
    
    insertAtPosition(arr, &n, x, pos);
    
    printf("Array after insertion:\n");
    printArray(arr, n);
    
    return 0;
}