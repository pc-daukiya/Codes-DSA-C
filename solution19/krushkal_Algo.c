#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

// Function to create a graph
struct Graph* createGraph(int vertices, int edges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->numEdges = edges;
    return graph;
}

// Function to find the parent of a node using path compression
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

// Function to compare two edges (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm
void kruskal(struct Graph* graph) {
    int parent[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = -1; // Initialize parent array
    }

    // Sort edges based on their weights
    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        int src = graph->edges[i].src;
        int dest = graph->edges[i].dest;
        int weight = graph->edges[i].weight;

        // Check if the selected edge forms a cycle
        if (find(parent, src) != find(parent, dest)) {
            printf("%d -- %d == %d\n", src, dest, weight);
            unionSets(parent, src, dest);
        }
    }
}

// Main function
int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices, edges);

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    kruskal(graph);

    free(graph);
    return 0;
}