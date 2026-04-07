/*Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    
    visited[node] = true;
    recStack[node] = true;
    
    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        
        // If not visited → DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        // If already in recursion stack → cycle found
        else if (recStack[neighbor]) {
            return true;
        }
    }
    
    // Remove node from recursion stack
    recStack[node] = false;
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V, int** adj, int* adjSize) {
    
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    // Adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));
    
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }
    
    // Input edges (u -> v)
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }
    
    if (hasCycle(V, adj, adjSize))
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}