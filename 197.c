/* Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdlib.h>

// Comparator
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // Allocate result arrays
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    // Initialize first interval
    res[0] = (int*)malloc(2 * sizeof(int));
    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        // If overlap
        if (intervals[i][0] <= res[idx][1]) {
            if (intervals[i][1] > res[idx][1]) {
                res[idx][1] = intervals[i][1];
            }
        } else {
            // New interval
            idx++;
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return res;
}