/*Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdlib.h>

// Comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    int* start = (int*)malloc(intervalsSize * sizeof(int));
    int* end = (int*)malloc(intervalsSize * sizeof(int));

    // Fill arrays
    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    // Sort both
    qsort(start, intervalsSize, sizeof(int), cmp);
    qsort(end, intervalsSize, sizeof(int), cmp);

    int rooms = 0, endPtr = 0;

    // Traverse start times
    for (int i = 0; i < intervalsSize; i++) {
        if (start[i] < end[endPtr]) {
            rooms++; // need new room
        } else {
            endPtr++; // reuse room
        }
    }

    free(start);
    free(end);

    return rooms;
}