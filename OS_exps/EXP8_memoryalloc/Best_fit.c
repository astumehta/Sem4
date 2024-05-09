#include <stdio.h>


int process[4] = {1, 2, 3, 4};

int incoming[4] = {80, 170, 150, 90};
int memory[4] = {100, 200, 300, 400};

int visited[4] = {0};
int allocated[4] = {0};

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bestfit()
{
    bubbleSort(memory, 4);

    for (int i = 0; i < 4; i++)
    {
        int j;
        for (j = 0; j < 4; j++)
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
    bestfit();

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
