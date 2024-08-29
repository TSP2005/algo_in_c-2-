#include <stdio.h>
#include <stdlib.h>

struct Node {
    int parent;
    int rank;
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* m[10001];  // Assuming the maximum number of vertices is 10000

void makeSet(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->parent = data;
    node->rank = 0;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    m[data] = node;
}

int findSet(int data) {
    struct Node* node = m[data];
    if (node->parent == data) {
        return data;
    }
    node->parent = findSet(node->parent);
    return node->parent;
}

void unionSet(int data1, int data2) {
    struct Node* node1 = m[data1];
    struct Node* node2 = m[data2];

    int parent1 = findSet(data1);
    int parent2 = findSet(data2);

    if (parent1 == parent2) return;

    if (node1->rank >= node2->rank) {
        node2->parent = parent1;
        if (node1->rank == node2->rank) {
            node1->rank++;
        }
        struct Node* tail = node1;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = node2;
        node2->prev = tail;
    } else {
        node1->parent = parent2;
        struct Node* tail = node2;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = node1;
        node1->prev = tail;
    }
}

struct Edge {
    int src, dest, weight;
};

struct Edge edges[10001];  // Assuming the maximum number of edges is 10000
int V;

void addEdge(int src, int dest, int weight) {
    struct Edge edge = {src, dest, weight};
    edges[V++] = edge;
}

struct Edge result[10001];

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST() {
    qsort(edges, V, sizeof(struct Edge), compareEdges);

    for (int i = 0; i < V; i++) {
        makeSet(i);
    }

    int e = 0;

    for (int i = 0; i < V; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        int parent1 = findSet(src);
        int parent2 = findSet(dest);

        if (parent1 != parent2) {
            result[e++] = edges[i];
            unionSet(parent1, parent2);
        }
    }

    printf("\n\nMST Edges\n");
    int minimumCost = 0;
    for (int i = 0; i < e; i++) {
        printf("%d<==>%d Weight : %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("\nMinimum Cost Spanning Tree: %d\n", minimumCost);
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(src, dest, weight);
    }

    kruskalMST();

    return 0;
}
