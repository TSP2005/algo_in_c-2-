#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 1000 // Define the maximum number of vertices

// Define the graph as an adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
};

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to detect cycles using DFS
bool detectCycleDFS(struct Graph* graph, int v, bool visited[], bool recursionStack[]) {
    visited[v] = true;
    recursionStack[v] = true;

    struct Node* current = graph->adjList[v];
    while (current != NULL) {
        int neighbor = current->vertex;
        if (!visited[neighbor]) {
            if (detectCycleDFS(graph, neighbor, visited, recursionStack)) {
                return true;
            }
        } else if (recursionStack[neighbor]) {
            return true; // Cycle detected
        }
        current = current->next;
    }

    recursionStack[v] = false;
    return false;
}

// Function to detect cycles in the entire graph
bool detectCycle(struct Graph* graph, int numVertices) {
    bool visited[MAX_VERTICES] = {false};
    bool recursionStack[MAX_VERTICES] = {false};

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && detectCycleDFS(graph, i, visited, recursionStack)) {
            return true;
        }
    }

    return false;
}

int main() {
    struct Graph graph;
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    // Initialize the graph
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph.adjList[i] = NULL;
    }

    // Read edges and weights
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        printf("Enter edge (src dest weight): ");
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    if (detectCycle(&graph, numVertices)) {
        printf("Cycle detected in the graph.\n");
    } else {
        printf("No cycle found in the graph.\n");
    }

    return 0;
}
 