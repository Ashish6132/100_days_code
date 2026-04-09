//: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // n = vertices, m = edges

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Kahn's Algorithm
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Cycle detection
    if (count != n) {
        printf("\nCycle detected (Topological sort not possible)");
    }

    return 0;
}