//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculating primary diagonal sum
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}
