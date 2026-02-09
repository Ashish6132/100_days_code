#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 0) return 0;

    int k = 1;  // index for unique elements

    for (int i = 1; i < n; i++) {
        if (a[i] != a[k - 1]) {
            a[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
