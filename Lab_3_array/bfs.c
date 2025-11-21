#include <stdio.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[SIZE];
int queue[SIZE];
int front = 0, rear = 0;

// Enqueue
void enqueue(int vertex) {
    queue[rear++] = vertex;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isQueueEmpty() {
    return front == rear;
}

void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < SIZE; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        visited[i] = 0;

    printf("BFS Traversal starting from vertex 0: ");
    BFS(0);

    return 0;
}
