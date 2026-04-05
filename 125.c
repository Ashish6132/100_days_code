/* Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
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

// Create a new node
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
    // Add edge src -> dest
    struct node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    // Add edge dest -> src
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// Print graph
void printGraph(struct graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        struct node* temp = g->adjLists[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
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

    printf("\nAdjacency List:\n");
    printGraph(g);

    return 0;
}