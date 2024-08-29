#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int minkey (int V, int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST (int V, int parent[], int graph[V][V])
{
    printf ("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int V, int graph[V][V])
{
    int parent[V];
    //Array to store constructed MST

    int key[V];
    //Array to pick minimum weighted edges
    
    bool mstSet[V];
    //Array to represent the vertices included in the MST

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minkey(V, key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    } 

    printMST (V, parent, graph);
}

int main ()
{
    printf("Enter the number of vertices: ");
    int V;
    scanf("%d", &V);
    
    int graph[V][V];

    printf("Enter the adjacency matrix (Weights between respective vertices): ");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("The given adjacency matrix is: ");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }

    primMST(V, graph);

    return 0;
}