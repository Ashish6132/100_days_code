//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Distance array
int dist[MAX];

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct Heap {
    int size;
    struct HeapNode arr[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct Heap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->arr[left].dist < h->arr[smallest].dist)
        smallest = left;

    if (right < h->size && h->arr[right].dist < h->arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

// Extract minimum
struct HeapNode extractMin(struct Heap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Insert into heap
void insertHeap(struct Heap* h, int v, int d) {
    int i = h->size++;
    h->arr[i].vertex = v;
    h->arr[i].dist = d;

    while (i && h->arr[(i - 1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Dijkstra Algorithm
void dijkstra(int n, int src) {
    struct Heap h;
    h.size = 0;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Main
int main() {
    int n = 5;

    // Initialize graph
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(2, 3, 4);
    addEdge(3, 2, 6);

    int source = 0;

    dijkstra(n, source);

    return 0;
}