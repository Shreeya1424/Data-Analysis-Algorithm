#include <stdio.h>

#define V 5           
#define NUM_EDGES 7   


struct Edge {
    int source;
    int dest;
    int weight;
};

int parent[V];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unionSet(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    parent[xset] = yset;
}

void sortEdges(struct Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int numEdges) {
    struct Edge result[V];  
    int e = 0;              
    int i = 0;              

    for (int v = 0; v < V; v++)
        parent[v] = v;

    // Sort all edges
    sortEdges(edges, numEdges);

    printf("Edges in Minimum Spanning Tree:\n");
    while (e < V - 1 && i < numEdges) {
        struct Edge next = edges[i++];

        int x = find(next.source);
        int y = find(next.dest);

        // If it doesn't cause a cycle
        if (x != y) {
            result[e++] = next;
            unionSet(x, y);
        }
    }

    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].source, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    struct Edge edges[NUM_EDGES] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 2, 25},
        {3, 4, 2}
    };

    kruskal(edges, NUM_EDGES);

    return 0;
}
