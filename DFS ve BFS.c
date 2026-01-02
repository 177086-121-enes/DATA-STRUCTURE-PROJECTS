#include <stdio.h>

#define N 5

void dfs(int graph[N][N], int visited[], int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < N; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(graph, visited, i);
    }
}

void bfs(int graph[N][N], int start) {
    int queue[N], front = 0, rear = 0;
    int visited[N] = {0};
    int i, v;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < N; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[N][N] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };

    int visited[N] = {0};
    int choice, start, i;

    do {
        printf("\n--- DFS & BFS ---\n");
        printf("1. DFS\n");
        printf("2. BFS\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Baslangic dugumu (0-%d): ", N-1);
            scanf("%d", &start);

            for (i = 0; i < N; i++)
                visited[i] = 0;

            printf("DFS: ");
            dfs(graph, visited, start);
            printf("\n");
        }
        else if (choice == 2) {
            printf("Baslangic dugumu (0-%d): ", N-1);
            scanf("%d", &start);

            printf("BFS: ");
            bfs(graph, start);
            printf("\n");
        }

    } while (choice != 0);

    return 0;
}

