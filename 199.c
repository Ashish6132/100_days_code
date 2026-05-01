/*Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting cars by position
int cmp(const void* a, const void* b) {
    double* carA = (double*)a;
    double* carB = (double*)b;
    return (carB[0] - carA[0]) > 0 ? 1 : -1; // sort in descending order
}

int carFleet(int target, int* position, int* speed, int n) {
    double cars[n][2]; // [position, time to target]

    for (int i = 0; i < n; i++) {
        cars[i][0] = position[i];
        cars[i][1] = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(cars[0]), cmp);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i][1] > lastTime) {
            fleets++;
            lastTime = cars[i][1]; // new fleet time
        }
    }

    return fleets;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}
