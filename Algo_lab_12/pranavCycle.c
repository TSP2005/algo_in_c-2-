#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int wt;
    struct node* next;
};

struct queue {
    int a[500];
    int front;
    int rear;
};

int isEmpty(struct queue* q) {
    return q->front == -1;
}

void enqueue(struct queue* q, int data) {
    if (q->rear == 499) {
        printf("QUEUE is Full\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->a[q->rear] = data;
    }
}

int dequeue(struct queue* q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("QUEUE is Empty\n");
    } else {
        a = q->a[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
    return a;
}

struct graph {
    int v;
    struct node** ad;
};

struct node* createNode(int v,int w) {
    struct node* p;
    p = malloc(sizeof(struct node));
    p->data = v;
    p->wt=w;
    p->next = NULL;
    return p;
}

struct graph* createGraph(int m) {
    struct graph* Graph;
    Graph = malloc(sizeof(struct graph));
    Graph->v = m;
    Graph->ad = (struct node*)malloc(m * sizeof(struct node));
    for (int i = 0; i < m; ++i) {
        Graph->ad[i] = NULL;
    }
    return Graph;
}

void addGraph(struct graph* G, int root, int chi,int wt) {
    struct node* new_node = createNode(chi,wt);
    new_node->next = G->ad[root];
    G->ad[root] = new_node;
}

void bfs(struct graph* G, int s) {
    int n = G->v;
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    vis[s] = 1;

    printf("BFS starting from vertex %d:\n", s);
    struct queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, s);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        struct node* p = G->ad[node];

        while (p != NULL) {
            int child = p->data;
            if (vis[child] == 0) {
                vis[child] = 1;
                enqueue(&q, child);

            }
            printf("%d -> %d --wt-(%d)\n", node, child,p->wt);
            p = p->next;
        }
    }
}

int cycle(struct graph* g, int s) {
    int n = g->v;
    int vis[n];
    int dis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = -1;
        dis[i] = -1;
    }
    vis[s] = 0;
    dis[s] = 0;
    struct queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, s);

    while (!isEmpty(&q)) {

        int p = dequeue(&q);
        vis[p] = 1;
        struct node* newnode = g->ad[p];



        while (newnode != NULL) {

                if(vis[newnode->data] == 1){
                        return (dis[p]+newnode->wt) ;
                }

                if (vis[newnode->data] == -1) {
                    int k = newnode->data;
                    vis[k] = 0;

                    dis[k]=newnode->wt;
                    dis[k]=dis[k]+dis[p];
                    enqueue(&q, k);
                } else if (vis[newnode->data] == 0) {

                            return (dis[p]+newnode->wt) ;

                }


            newnode = newnode->next;
        }
    }
    return 0;
}

int hascycle_s(struct graph *g,int s){
int n = g->v;
    int vis[n];
    int dis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = -1;
        dis[i] = -1;
    }
    vis[s] = 0;
    dis[s] = 0;
    struct queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, s);

    while (!isEmpty(&q)) {

        int p = dequeue(&q);
        vis[p] = 1;
        struct node* newnode = g->ad[p];



        while (newnode != NULL) {

                if(vis[newnode->data] == 1){
                        if((dis[p]+newnode->wt)<0){
                            return (dis[p]+newnode->wt) ;
                        }

                }

                if (vis[newnode->data] == -1) {
                    int k = newnode->data;
                    vis[k] = 0;

                    dis[k]=newnode->wt;
                    dis[k]=dis[k]+dis[p];
                    enqueue(&q, k);
                } else if (vis[newnode->data] == 0) {
                    if((dis[p]+newnode->wt)<0){
                            return (dis[p]+newnode->wt) ;
                        }
                }


            newnode = newnode->next;
        }
    }
    return 0;
}



int main() {
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    struct graph* G;
    G = createGraph(n);

    // Add directed edges to the graph
    addGraph(G, 0, 1,2);
    addGraph(G, 1, 2,1);
    addGraph(G, 2, 0,1);
    addGraph(G,1,3,1);
    addGraph(G,3,2,-5);

    bfs(G, 0);

    int cycleLength = hascycle_s(G, 0);

    if (cycleLength!=0) {
        printf("Cycle is present, Cycle length: %d\n", cycleLength);
    } else {
        printf("No cycle\n");
    }

    return 0;
}