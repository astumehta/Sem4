#include <stdio.h>

int process[4] = {1, 2, 3, 4};
int incoming[4] = {212, 417, 112, 426};
int memory[5] = {100, 500, 200, 300, 600};
int visited[5] = {0};
int allocated[5] = {0};
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void worstfit()
{
    bubbleSort(memory, 5);
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
    worstfit();
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
