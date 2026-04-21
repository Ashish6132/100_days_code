/* Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

Input:
- First line: integer n representing the number of vertices
- Next n lines: n space-separated integers representing the adjacency matrix of the graph
  (use -1 to indicate no direct edge between two vertices)

Output:
- Print the shortest distance matrix where the value at row i and column j represents the shortest distance from vertex i to vertex j
*/
#include <stdio.h>

#define INF 1000000000
#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);

            if (x == -1 && i != j)
                dist[i][j] = INF;   // no edge
            else
                dist[i][j] = x;     // edge weight or 0
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}