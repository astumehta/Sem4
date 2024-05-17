// {
//         {0,4,7,9,8},
//         {4,0,1,1000,1000},
//         {7,1,0,2,1000},
//         {9,1000,2,0,6},
//         {8,1000,1000,6,0},
// };

#include <stdio.h>

#define MAX_VERTICES 9
#define MAX 999

int cost[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];

int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    int ne = 1;
    int mincost = 0;
    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = MAX;
            }
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    
    while (ne < n)
    {
        int min = 999;
        int a, b;
        int u = -1;
        int v = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
    return 0;
}
