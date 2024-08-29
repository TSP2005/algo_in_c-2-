#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Graph {
    int V;
    Node** adj;
};

typedef struct Graph Graph;

void DFSUtil(Graph* g, int v, int visited[]) {
    visited[v] = 1;

    Node* temp = g->adj[v];
    while (temp != NULL) {
        int i = temp->data;
        if (!visited[i]) {
            DFSUtil(g, i, visited);
        }
        temp = temp->next;
    }
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* g, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = w;
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

Graph* getTranspose(Graph* g) {
    Graph* gr = createGraph(g->V);
    for (int v = 0; v < g->V; v++) {
        Node* temp = g->adj[v];
        while (temp != NULL) {
            addEdge(gr, temp->data, v);
            temp = temp->next;
        }
    }
    return gr;
}

int isSC(Graph* g) {
    int* visited = (int*)malloc(g->V * sizeof(int));

    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    DFSUtil(g, 0, visited);

    for (int i = 0; i < g->V; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    Graph* gr = getTranspose(g);

    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    DFSUtil(gr, 0, visited);

    for (int i = 0; i < g->V; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        Node* temp = g->adj[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(g->adj);
    free(g);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph* g = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (in the format 'u v', where u and v are vertices): \n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    isSC(g) ? printf("Yes\n") : printf("No\n");

    freeGraph(g);

    return 0;
}
