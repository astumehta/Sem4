#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define OG 999

int w[MAX][MAX];
int d[MAX];
int parent[MAX];

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = OG;
        parent[i] = -1;
    }
    d[0] = 0;
}

void relax(int u, int v)
{
    if (d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        parent[v] = u;
    }
}

void bellmanFord(int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (w[u][v] != 0)
                {
                    relax(u, v);
                }
            }
        }
    }
}

int main()
{
    int n;

    printf("Number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }

    initialize(n);
    bellmanFord(n);

    printf("Shortest distances from source node:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d, Parent: %d\n", i, d[i], parent[i] + 1);
    }

    return 0;
}
