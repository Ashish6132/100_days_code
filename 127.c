/*erform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Graph structure
struct graph {
    int numVertices;
    struct node** adjLists;
};

// Create node
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct graph* createGraph(int vertices) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->numVertices = vertices;

    g->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

    for (int i = 0; i < vertices; i++)
        g->adjLists[i] = NULL;

    return g;
}

// Add edge (undirected)
void addEdge(struct graph* g, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// DFS function
void dfs(struct graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct node* temp = g->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(g, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct graph* g = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal:\n");
    dfs(g, s, visited);

    return 0;
}