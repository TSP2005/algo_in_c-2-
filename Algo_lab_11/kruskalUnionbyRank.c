#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct TreeNode {
    int parent;
    int rank;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(struct TreeNode tree[], int i) {
    if (tree[i].parent != i)
        tree[i].parent = find(tree, tree[i].parent);

    return tree[i].parent;
}

void Union(struct TreeNode tree[], int left, int right) {
    int leftRoot = find(tree, left);
    int rightRoot = find(tree, right);

    if (tree[leftRoot].rank < tree[rightRoot].rank)
        tree[leftRoot].parent = rightRoot;
    else if (tree[leftRoot].rank > tree[rightRoot].rank)
        tree[rightRoot].parent = leftRoot;
    else {
        tree[rightRoot].parent = leftRoot;
        tree[leftRoot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(struct Edge), compareEdges);

    struct TreeNode tree[V];

    for (int v = 0; v < V; ++v) {
        tree[v].parent = v;
        tree[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edge[i++];

        int left = find(tree, nextEdge.src);
        int right = find(tree, nextEdge.dest);

        if (left != right) {
            result[e++] = nextEdge;
            Union(tree, left, right);
        }
    }

    printf("\n\nMST Edges\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d<==> %d Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("\nMinimum Cost Spanning Tree: %d\n", minimumCost);
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int e;
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    struct Graph* graph = createGraph(v, e);

    for (int i = 0; i < e; i++) {
        printf("Enter the source, destination and weight of edge %d: ", i + 1);
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        graph->edge[i].src = s;
        graph->edge[i].dest = d;
        graph->edge[i].weight = w;
    }

    KruskalMST(graph);

    return 0;
}
