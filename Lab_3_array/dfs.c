#include <stdio.h>

#define SIZE 5

// Predefined graph as adjacency matrix
int graph[SIZE][SIZE] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[SIZE];

// Depth First Search function
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < SIZE; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from vertex 0: ");
    DFS(0);

    return 0;
}
