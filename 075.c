#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return (front == -1);
}


int size() {
    if (front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int value) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}


void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}


void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}


void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}


int get_front() {
    if (empty()) {
        printf("Deque empty\n");
        return -1;
    }
    return deque[front];
}


int get_back() {
    if (empty()) {
        printf("Deque empty\n");
        return -1;
    }
    return deque[rear];
}

/* Display deque */
void display() {
    if (empty()) {
        printf("Deque empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());

    printf("Size: %d\n", size());

    return 0;
}