#include <stdio.h>

int process[4] = {1, 2, 3, 4};

int incoming[4] = {44, 220, 670, 64};
int memory[5] = {100, 500, 200, 300, 600};

int visited[5] = {0};
int allocated[5] = {0};

void firstfit()
{
    int j;
    for (int i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (incoming[i] <= memory[j] && visited[j] != 1)
            {
                allocated[j] = process[i];
                visited[j] = 1;
                break;
            }
        }
    }
}

int main()
{
    firstfit();
    for (int i = 0; i < 5; i++)
    {
        if (allocated[i] != 0)
        {
            printf("P%d->", allocated[i]);
        }
        else
        {
            printf("- ->");
        }
    }
    return 0;
}
