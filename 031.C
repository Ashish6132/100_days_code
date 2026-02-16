#include <stdio.h>
#define MAX_SIZE 100
void countFrequency(int arr[], int n) {
    int frequency[MAX_SIZE] = {0};
    
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    
    printf("Element:Count\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequency[i] > 0) {
            printf("%d:%d\n", i, frequency[i]);
        }
    }
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
    
    countFrequency(arr, n);
    
    return 0;
}
