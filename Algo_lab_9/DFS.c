#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct AdjList* array;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    for (int i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[], int finishingTime[], int* time) {
    visited[vertex] = true;
    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited, finishingTime, time);
        }
        temp = temp->next;
    }
    finishingTime[(*time)++] = vertex;
}

void DFS_Transposed(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS_Transposed(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

struct Graph* transposeGraph(struct Graph* graph) {
    struct Graph* transposedGraph = createGraph(graph->vertices);
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* temp = graph->array[i].head;
        while (temp != NULL) {
            addEdge(transposedGraph, temp->vertex, i);
            temp = temp->next;
        }
    }
    return transposedGraph;
}

void printSCC(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    int* finishingTime = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
        finishingTime[i] = 0;
    }

    int time = 0;

    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, finishingTime, &time);
        }
    }

    struct Graph* transposedGraph = transposeGraph(graph);

    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    for (int i = graph->vertices - 1; i >= 0; --i) {
        int vertex = finishingTime[i];
        if (!visited[vertex]) {
            printf("Strongly Connected Component: ");
            DFS_Transposed(transposedGraph, vertex, visited);
            printf("\n");
        }
    }

    free(visited);
    free(finishingTime);
}

int main() {
    struct Graph* graph = createGraph(3);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,0);

    printf("Strongly Connected Components:\n");
    printSCC(graph);

    return 0;
}