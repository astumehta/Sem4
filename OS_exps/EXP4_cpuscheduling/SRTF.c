#include <stdio.h>
#define n 5
int main()
{
    int AT[] = {2, 5, 1, 0, 4};
    int BT[] = {6, 2, 8, 3, 4};
    int visited[n];
    int time = 0;
    int complete = 0;
    int process[n];
    int remaining[n];
    // int priority[]={4,5,7,2,1,6};
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        visited[i] = 0;
        remaining[i] = BT[i];
    }
    for (int i = 0; i < n; i++)
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

                temp = remaining[i];
                remaining[i] = remaining[j];
                remaining[j] = temp;
            }
        }
    }
    int CT[n];
    int TAT[n];
    int WT[n];

    time += AT[0];
    while (complete < n)
    {
        int min_burst = 1000;
        int min_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && AT[i] <= time && min_burst > remaining[i])
            {
                min_burst = remaining[i];
                min_index = i;
            }
        }
        printf("P%d\t", process[min_index]);
        printf("%d\n", time);
        time++;
        remaining[min_index]--;

        if (remaining[min_index] == 0)
        {

            CT[min_index] = time; //NO ADDING BT
            TAT[min_index] = CT[min_index] - AT[min_index];
            WT[min_index] = TAT[min_index] - BT[min_index];

            visited[min_index] = 1;
            complete++;
        }
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", process[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
}