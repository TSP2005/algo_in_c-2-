#include <stdio.h>
#include <stdlib.h>

struct GFG {
    int* vis;
    int* is_scc;

    // dfs Function to reach destination
    int dfs(int curr, int des, int** adj) {
        // If curr node is destination return true
        if (curr == des) {
            return 1;
        }
        vis[curr] = 1;
        for (int i = 0; adj[curr][i] != -1; i++) {
            int x = adj[curr][i];
            if (!vis[x]) {
                if (dfs(x, des, adj)) {
                    return 1;
                }
            }
        }
        return 0;
    }

    // To tell whether there is a path from source to
    // destination
    int isPath(int src, int des, int** adj) {
        return dfs(src, des, adj);
    }

    // Function to return all the strongly connected
    // components of a graph.
    int** findSCC(int n, int** a, int* ans_size) {
        // Stores all the strongly connected components.
        int** ans;

        // Stores whether a vertex is a part of any Strongly
        // Connected Component
        is_scc = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++) {
            is_scc[i] = 0;
        }

        int** adj = (int**)malloc((n + 1) * sizeof(int*));
        for (int i = 1; i <= n; i++) {
            adj[i] = (int*)malloc((n + 1) * sizeof(int));
            for (int j = 0; j <= n; j++) {
                adj[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            int u = a[i][0];
            int v = a[i][1];
            int j = 0;
            while (adj[u][j] != -1) {
                j++;
            }
            adj[u][j] = v;
            adj[u][j + 1] = -1; // Mark the end of the list
        }

        // Traversing all the vertices
        ans = (int**)malloc((n + 1) * sizeof(int*));
        *ans_size = 0;
        for (int i = 1; i <= n; i++) {
            if (!is_scc[i]) {
                // If a vertex i is not a part of any SCC
                // insert it into a new SCC list and check
                // for other vertices whether they can be
                // the part of this list.
                int* scc = (int*)malloc(n * sizeof(int));
                scc[0] = i;

                for (int j = i + 1; j <= n; j++) {
                    // If there is a path from vertex i to
                    // vertex j and vice versa put vertex j
                    // into the current SCC list.
                    if (!is_scc[j] && isPath(i, j, adj) && isPath(j, i, adj)) {
                        is_scc[j] = 1;
                        int k = 0;
                        while (scc[k] != -1) {
                            k++;
                        }
                        scc[k] = j;
                        scc[k + 1] = -1; // Mark the end of the list
                    }
                }

                // Insert the SCC containing vertex i into
                // the final list.
                ans[*ans_size] = scc;
                (*ans_size)++;
            }
        }
        return ans;
    }
};

// Driver Code Starts

int main() {
    struct GFG obj;
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int** edges = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (in the format 'u v', where u and v are vertices): \n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int ans_size;
    int** ans = obj.findSCC(V, edges, &ans_size);

    printf("Strongly Connected Components are:\n");
    for (int i = 0; i < ans_size; i++) {
        for (int j = 0; ans[i][j] != -1; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
        free(ans[i]);
    }
    free(ans);

    for (int i = 0; i < V; i++) {
        free(edges[i]);
    }
    free(edges);

    return 0;
}
