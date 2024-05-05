#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX INT_MAX 
#define vertices 5

int G[vertices][vertices] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    int no_edge;
    int selected[vertices];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x, y;

    printf("Edge : Weight\n");

    while (no_edge < vertices - 1)
    {
        int min = MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < vertices; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < vertices; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}
