#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;


int main ()
{
    int n;
    int m;
    printf("Enter the number of vertices: ");
    scanf ("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int choice;
    int M[n][n];
    printf("GIVEN:\n");
    printf ("1. Adjacency Matrix\n");
    printf ("2. Adjacency List\n");
    printf ("3. Exit\n");


    printf ("%d    %d\n", sizeof(node), sizeof(node *));


    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                {
                    printf("Enter the Adjacency Matrix: ");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            scanf("%d", &M[i][j]);
                        }
                    }
                    printf("The given Adjacency Matrix is:\n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            printf("%d ", M[i][j]);
                        }
                        printf ("\n");
                    }
                    node ** adjList = (node **)malloc(n * sizeof(node));
                    for (int i = 0; i < n; i++)
                    {
                        adjList[i] = (node *)malloc(sizeof(node));
                        adjList[i] -> data = i + 1;
                        adjList[i] -> next = NULL;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        node * p = adjList[i];
                        for (int j = 0; j < n; j++)
                        {
                            if (M[i][j] == 1)
                            {
                                node * temp = (node *)malloc(sizeof(node));
                                temp -> data = j + 1;
                                temp -> next = NULL;
                                p -> next = temp;
                                p = p -> next;
                            }
                        }
                    }
                    printf ("The Adjacency List is\n");
                    for (int i = 0; i < n; i++)
                    {
                        node * temp = adjList[i];
                        while (temp -> next != NULL)
                        {
                            printf("%d -> ", temp -> data);
                            temp = temp -> next;
                        }
                        printf("%d -> NULL", temp -> data);
                        printf("\n");
                    }
                    break;
                }

            case 2:
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            M[i][j] = 0;
                        }
                    }
                    node ** adjList = (node **)malloc(n * sizeof(node));
                    for (int i = 0; i < n; i++)
                    {
                        adjList[i] = (node *)malloc(sizeof(node));
                        adjList[i] -> data = i + 1;
                        adjList[i] -> next = NULL;
                        node * p = adjList[i];
                        printf ("Enter the Adjacency List for Vertex %d\n", i + 1);
                        for (int j = 0; j < n; j++)
                        {
                            int c = 0;
                            printf ("Is there an edge from Vertex %d to Vertex %d (press 1 if YES (or) 0 for NO)", i + 1, j + 1);
                            scanf("%d", &c);
                            if (c == 1)
                            {
                                node * temp = (node *)malloc(sizeof(node));
                                temp -> data = j + 1;
                                temp -> next = NULL;
                                p -> next = temp;
                                p = p -> next;
                                M[i][j] = 1;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    printf ("The given Adjacency List is:\n");
                    for (int i = 0; i < n; i++)
                    {
                        node * temp = adjList[i];
                        while (temp -> next != NULL)
                        {
                            printf ("%d -> ", temp -> data);
                            temp = temp -> next;
                        }
                        printf ("%d -> NULL\n", temp -> data);
                    }
                    printf("The corresponding Adjacency Matrix is:\n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            printf("%d ", M[i][j]);
                        }
                        printf ("\n");
                    }
                break;
                }

            case 3:
                exit(0);

            default: 
                printf("Please enter a valid choice.");
        }
    }
}