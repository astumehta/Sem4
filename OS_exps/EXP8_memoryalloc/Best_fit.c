#include <stdio.h>

int process[4] = {1, 2, 3, 4};
int incoming[4] = {80, 20, 20, 30};
int memory[5] = {100, 200, 300, 400, 500};
int remaining[5] = {100, 200, 300, 400, 500};
int visited[5] = {0};
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
    printf("P\tIncoming\tMemory Block\n");
    for (int i = 0; i < 4; i++)
    {
        int allocated = 0;
        printf("P%d\t%d\t", process[i], incoming[i]);
        for (int j = 0; j < 5; j++)
        {
            if (incoming[i] <= remaining[j] && visited[j] != 1)
            {
                printf("%d\n", memory[j]);
                remaining[j] -= incoming[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated)
        {
            
            for (int j = 0; j < 5; j++)
            {
                if (incoming[i] <= remaining[j])
                {
                    printf("%d\n", memory[j]);
                    remaining[j] -= incoming[i];
                    allocated = 1;
                    break;
                }
            }
        }
        if (!allocated)
        {
            printf("Not enough memory\n");
        }
    }
}

int main()
{
    bubbleSort(memory,5);
    bestfit();
    return 0;
}
