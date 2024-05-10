#include <stdio.h>

int process[4] = {1, 2, 3, 4};

int incoming[4] = {80,170,202,350};
int memory[5] = {100,200,300,400,500};

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
    
printf("Processes\tIncoming\tMemory\n");

    for (int i = 0; i < 4; i++)
    {
        printf("P%d\t\t%d\t\t", allocated[i], incoming[allocated[i]-1]);
        if (allocated[i] != 0)
        {
            printf("%d\n", memory[i]);
        }
        else
        {
            printf("-\n");
        }
    }
    return 0;
}
