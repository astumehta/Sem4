#include <stdio.h>

int main()
{
    int n = 5;
    int AT[] = {1, 3, 6, 7, 9};
    int BT[] = {7, 3, 2, 10, 8};
    int process[n];
    int final[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        visited[i] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (AT[i] > AT[j])
            {

                int temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    int time = 0;
    int completed = 0;

    int CT[n];
    int TAT[n];
    int WT[n];

    time += AT[0];

    while (completed < n)
    {
        int min_burst = 1000;
        int min_index = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && AT[i] <= time && BT[i] < min_burst)
            {
                min_burst = BT[i];
                min_index = i;
            }
        }
        
        CT[min_index] = time + BT[min_index];
        TAT[min_index] = CT[min_index] - AT[min_index];
        WT[min_index] = TAT[min_index] - BT[min_index];

        printf("%d\n", process[min_index]);
        visited[min_index] = 1;

        time += BT[min_index];
        completed++;
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], AT[i], BT[i], CT[i],
               TAT[i], WT[i]);
    }
    printf("\n");

    return 0;
}