#include <stdio.h>

#define N 6

void dfs(int graph[N][N], int visited[], int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < N; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i);
        }
    }
}

int main() {
    int graph[N][N] = {
        {0,1,0,0,0,0},
        {1,0,1,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,1},
        {0,0,0,1,0,0},
        {0,0,0,1,0,0}
    };

    int visited[N] = {0};
    int i, cluster = 0;

    printf("--- CLUSTERS ---\n");

    for (i = 0; i < N; i++) {
        if (visited[i] == 0) {
            cluster++;
            printf("Cluster %d: ", cluster);
            dfs(graph, visited, i);
            printf("\n");
        }
    }

    printf("Toplam Cluster Sayisi: %d\n", cluster);

    return 0;
}

