#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}};

// color=3{R,G,B}
int m = 3;

int x[V];

void printSolution()
{
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, x[i]);
}

void mColouring(int k)
{
    do
    {
        nextValue(k);
        if (x[k] == 0)
            return;
        if (k == V - 1)
        {
            printSolution();
            return;
        }
        else
            mColouring(k + 1);
    } while (1);
}

void nextValue(int k)
{
    do
    {
        // k is 0, we start comparing from node 0
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (int j = 0; j < V; j++)
        {
            if (graph[k][j] != 0 && x[k] == x[j])
                break;
            if (j == V - 1)
                return;
        }
    } while (1);
}

int main()
{
    for (int i = 0; i < V; i++)
        x[i] = 0;

    printf("Coloring of graph vertices:\n");
    mColouring(0);

    return 0;
}
