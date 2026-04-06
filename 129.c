/*Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// check empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp;

    temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = createNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

// BFS function
void bfs(int V, struct Node* adj[], int source) {
    int visited[MAX] = {0};

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }

            temp = temp->next;
        }
    }
}

// main function
int main() {
    int V = 5;

    struct Node* adj[MAX];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    int source = 0;

    bfs(V, adj, source);

    return 0;
}