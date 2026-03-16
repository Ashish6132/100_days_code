// Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}
int isEmpty(Queue* q) {
    return q->front == -1;
}
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = item;
    }
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; 
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) {
            initQueue(q); 
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return item;
    }
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q)); 
    return 0;
}