//Implement a Priority Queue using an array. An element with smaller value has higher priority.

//Supported Operations:
//- insert x
//- delete
//- peek
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = -1;


void insert(int value) {
    if (size == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    size++;
    pq[size] = value;
}


int findMin() {
    int min = 0;

    for (int i = 1; i <= size; i++) {
        if (pq[i] < pq[min]) {
            min = i;
        }
    }
    return min;
}


void delete() {
    if (size == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int minIndex = findMin();
    printf("Deleted element: %d\n", pq[minIndex]);

    for (int i = minIndex; i < size; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}


void peek() {
    if (size == -1) {
        printf("Queue is empty\n");
        return;
    }

    int minIndex = findMin();
    printf("Highest priority element: %d\n", pq[minIndex]);
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);

    peek();     
    delete();   
    peek();

    return 0;
}