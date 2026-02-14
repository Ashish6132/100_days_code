//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    // Input
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isIdentity = 1; // Assume it's an identity matrix until proven otherwise

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                isIdentity = 0; // Diagonal element is not 1
                break;
            } else if (i != j && matrix[i][j] != 0) {
                isIdentity = 0; // Non-diagonal element is not 0
                break;
            }
        }
        if (!isIdentity) {
            break;
        }
    }

    if (isIdentity) {
        printf("The given matrix is an Identity Matrix.\n");
    } else {
        printf("The given matrix is not an Identity Matrix.\n");
    }

    return 0;
}