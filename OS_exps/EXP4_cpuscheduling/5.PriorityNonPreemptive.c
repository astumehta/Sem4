#include <stdio.h>
#define n 6
int main()
{

    int AT[] = {0, 1, 2, 3, 4, 5};
    int BT[] = {4, 5, 1, 2, 3, 6};
    int process[n];
    int final[n];
    int visited[n];
    int priority[] = {4, 5, 7, 2, 1, 6};

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

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
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
        int max_burst = -1;
        int max_index = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && AT[i] <= time && priority[i] > max_burst)
            {
                max_burst = priority[i];
                max_index = i;
            }
        }
        CT[max_index] = time + BT[max_index];
        TAT[max_index] = CT[max_index] - AT[max_index];
        WT[max_index] = TAT[max_index] - BT[max_index];

        final[completed] = process[max_index];
        printf("%d\n", final[completed]);
        visited[max_index] = 1;

        time += BT[max_index];
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