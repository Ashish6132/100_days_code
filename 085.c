/*Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
*/
#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int main() {
    int n, x;

    // Input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

    // 🔥 Reset queue
    front = -1;
    rear = -1;

    // Step 2: Stack → Queue (Reversed)
    while (top != -1) {
        enqueue(pop());
    }

    // Output
    printf("Reversed Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}