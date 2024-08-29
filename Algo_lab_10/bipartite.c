#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Graph {
    int V;
    Node** adjList;
};

typedef struct Graph Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

bool isBipartiteUtil(Graph* graph, int src, int colorArr[], int V) {
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue the source vertex for BFS traversal
    int queue[V];
    int front = -1, rear = -1;
    queue[++rear] = src;

    // Run while there are vertices in the queue (similar to BFS)
    while (front != rear) {
        int u = queue[++front];

        // Return false if there is a self-loop
        if (colorArr[u] == -1) {
            colorArr[u] = 1 - colorArr[u];
        }

        // Find all non-colored adjacent vertices
        Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->data;
            // An edge from u to v exists, and destination v is colored with the same color as u
            if (colorArr[v] == colorArr[u]) {
                return false;
            }

            // An edge from u to v exists and destination v is not colored
            if (colorArr[v] == -1) {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                queue[++rear] = v;
            }

            temp = temp->next;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with an alternate color
    return true;
}

bool isBipartite(Graph* graph) {
    int V = graph->V;

    // Create a color array to store colors assigned to all vertices.
    // Vertex/number is used as an index in this array.
    // The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'.
    // The value '1' is used to indicate the first color is assigned, and value '0' indicates the second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // This code is to handle a disconnected graph
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(graph, i, colorArr, V) == false)
                return false;

    return true;
}

int main() {
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter edges (end with -1 -1):\n");
    int v1, v2;
    while (1) {
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 || v2 == -1)
            break;

        if (v1 >= V || v2 >= V || v1 < 0 || v2 < 0) {
            printf("Invalid vertex entered. Please enter valid vertices.\n");
            continue;
        }

        addEdge(graph, v1, v2);
    }

    isBipartite(graph) ? printf("Yes, the graph is Bipartite.\n") : printf("No, the graph is not Bipartite.\n");

    return 0;
}
