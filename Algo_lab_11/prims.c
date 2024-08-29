#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int first;
    int second;
} PairOfInt;

typedef struct {
    PairOfInt* array;
    int size;
    int capacity;
} VectorPairOfInt;

void initVector(VectorPairOfInt* vector, int capacity) {
    vector->array = (PairOfInt*)malloc(capacity * sizeof(PairOfInt));
    vector->size = 0;
    vector->capacity = capacity;
}

void pushBack(VectorPairOfInt* vector, PairOfInt element) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->array = (PairOfInt*)realloc(vector->array, vector->capacity * sizeof(PairOfInt));
    }
    vector->array[vector->size++] = element;
}

void sortVector(VectorPairOfInt* vector) {
    for (int i = 0; i < vector->size - 1; i++) {
        for (int j = 0; j < vector->size - i - 1; j++) {
            if (vector->array[j].first > vector->array[j + 1].first) {
                PairOfInt temp = vector->array[j];
                vector->array[j] = vector->array[j + 1];
                vector->array[j + 1] = temp;
            }
        }
    }
}

void addEdge(VectorPairOfInt* adj, int u, int v, int w) {
    PairOfInt pair1 = {v, w};
    pushBack(&adj[u], pair1);
    PairOfInt pair2 = {u, w};
    pushBack(&adj[v], pair2);
}

void primMST(VectorPairOfInt* adj, int V) {
    int* key = (int*)malloc(V * sizeof(int));
    int* cuts = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        cuts[i] = -1;
    }
    int* inMST = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        inMST[i] = 0;
    }

    key[0] = 0;
    cuts[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        for (int v = 0; v < V; v++) {
            if (inMST[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = 1;

        for (int i = 0; i < adj[u].size; i++) {
            int v = adj[u].array[i].first;
            int weight = adj[u].array[i].second;

            if (inMST[v] == 0 && key[v] > weight) {
                key[v] = weight;
                cuts[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i) {
        printf("%d <==> %d\n", cuts[i], i);
    }

    free(key);
    free(cuts);
    free(inMST);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    VectorPairOfInt adj[v];
    for (int i = 0; i < v; i++) {
        initVector(&adj[i], 1);
    }

    printf("Enter the number of edges: ");
    int e;
    scanf("%d", &e);

    VectorPairOfInt edges;
    initVector(&edges, e);

    for (int i = 0; i < e; i++) {
        printf("Enter the source, destination, and weight of edge %d: ", i + 1);
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        PairOfInt edge = {w, (s << 16) | d}; // Combine source and destination into one integer
        pushBack(&edges, edge);
    }

    sortVector(&edges);

    for (int i = 0; i < edges.size; i++) {
        int s = edges.array[i].second >> 16; // Extract source
        int d = edges.array[i].second & 0xFFFF; // Extract destination
        addEdge(adj, s, d, edges.array[i].first);
    }

    printf("\n");
    primMST(adj, v);

    for (int i = 0; i < v; i++) {
        free(adj[i].array);
    }
    free(edges.array);

    return 0;
}
