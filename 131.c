/*Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
struct Node {
    int data;
    struct Node* next;
};

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

// DFS function
int dfs(int node, int parent, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj))
                return 1;
        }
        else if (neighbor != parent) {
            return 1;  // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

// function to check cycle
int hasCycle(int V, struct Node* adj[]) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V = 5;

    struct Node* adj[MAX];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // edges
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 1);  // cycle

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}