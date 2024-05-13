#include <stdio.h>
#define n 4
int main()
{

    int AT[] = {0, 1, 2, 4};
    int BT[] = {5, 4, 2, 1};
    int remaining[n];
    int process[n];
    
    int final[n];
    int visited[n];
    int priority[] = {10, 20, 30, 40};

    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        visited[i] = 0;
        remaining[i] = BT[i];
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

                temp = remaining[i];
                remaining[i] = remaining[j];
                remaining[j] = temp;

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
    int AWT[n];
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

        printf("P%d\t", process[max_index]);
        printf("%d\n", time);

        time++;
        remaining[max_index]--;

        if (remaining[max_index] == 0)
        {
            CT[max_index] = time;   //NO ADDING BT
            TAT[max_index] = CT[max_index] - AT[max_index];
            AWT[max_index] = TAT[max_index] - BT[max_index];

            visited[max_index] = 1;
            completed++;
        }
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], AT[i], BT[i], CT[i],
               TAT[i], AWT[i]);
    }
    printf("\n");

    return 0;
}