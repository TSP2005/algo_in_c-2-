#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node
{
    int data;
    struct node * next;
}Node;

typedef struct queue
{
    int vertices[MAX_VERTICES];
    int front;
    int rear;
}Queue;

typedef struct adjList
{
    Node * head;
}AdjList;

typedef struct graph
{
    int vertices;
    AdjList * adjListArray;
}Graph;

Queue * createQueue()
{
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q -> front = -1;
    q -> rear = -1;
    return q;
}

int isEmpty (Queue * q)
{
    if (q -> front > q -> rear)
    {
        return 1;
    }
    return 0;
}

void enQueue(Queue * q, int vertex)
{
    if (q -> front == -1 && q -> rear == -1)
    {
        q -> front = 0;
    }
    q -> rear ++;
    q -> vertices[q -> rear] = vertex;
}

int deQueue (Queue * q)
{
    int curVertex;
    if (q -> front == q -> rear)
    {
        curVertex = q -> vertices[q -> front];
        q -> front = -1;
        q -> rear = -1;

        for (int i = 0; i < MAX_VERTICES; i++)
        {
            q -> vertices[i] = 0;
        }
    }
    else
    {
        curVertex = q -> vertices[q -> front];
        q -> front ++;
    }
    return curVertex;
}

Node * createNode (int data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

Graph * createGraph (int vertices)
{
    Graph * graph = (Graph *)malloc(sizeof(Graph));
    graph -> vertices = vertices;
    graph -> adjListArray = (AdjList *)malloc(vertices * sizeof(AdjList));
    for (int i = 0; i < vertices; ++i)
    {   
        graph -> adjListArray[i].head = NULL;
    }
    return graph;
}

void addEdge (Graph * graph, int src, int des)
{
    Node * newNode = createNode (des);
    newNode -> next = graph -> adjListArray[src].head;
    graph -> adjListArray[src].head = newNode; 

    newNode = createNode(src);
    newNode -> next = graph -> adjListArray[des].head;
    graph -> adjListArray[des].head = newNode;
}

void printGraph (Graph * graph)
{
    printf ("Adjacency list representation\n");
    for (int i = 0; i < graph -> vertices; i++)
    {
        Node * temp = graph -> adjListArray[i].head;
        printf("Vertex %d ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void BFS (Graph * graph, int startVertex)
{
    int * visited = (int *)malloc(graph -> vertices * sizeof(int));
    for (int i = 0; i < graph -> vertices; i++)
    {
        visited[i] = 0;
    }
    Queue * q = createQueue();
    enQueue (q, startVertex);
    visited [startVertex] = 1;

    printf("The BFS starting from vertex %d: ", startVertex);
    while (!isEmpty(q))
    {
        int curVer = deQueue(q);
        if (curVer >= graph -> vertices)
        {
            continue;
        }
        printf ("%d ", curVer);

        Node * temp = graph -> adjListArray[curVer].head;
        while (temp != NULL)
        {
            int adjVertex = temp -> data;
            if (!visited[adjVertex])
            {
                enQueue(q, adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp -> next;
        }
    }
    printf("\n");

    free (q);
    free (visited);
}

int main ()
{
    int v;
    int e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);
    Graph * graph = createGraph(v);
    printf("Enter the source and destination of each edge\n");
    for (int i = 0; i < e; i++)
    {
        int src;
        int des;
        scanf("%d %d", &src, &des);
        addEdge (graph, src, des);
    }
    printGraph (graph);
    int startVertex;
    printf("Enter the vertex to start BFS: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex);

    free (graph -> adjListArray);
    free (graph);
}