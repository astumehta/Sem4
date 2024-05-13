#include <stdio.h>

void bubbleSort(float AT[], int process[], float BT[], int n)
{
    int i, j, temp_process;
    float temp_AT, temp_BT;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {
                temp_AT = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp_AT;

                temp_process = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp_process;

                temp_BT = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp_BT;
            }
        }
    }
}

void fcfs(float AT[], int process[], float BT[], int n)
{
    float awt = 0, atat = 0;
    float gantt[2 * n + 1];
    float CT[n], WT[n], TAT[n];
    float idleTime = 0;

    gantt[0] = 0;
    gantt[1] = AT[0];

    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];
    awt += WT[0];
    atat += TAT[0];

    gantt[2] = CT[0];

    for (int i = 1; i < n; i++)
    {
        if (AT[i] > CT[i - 1])
        {
            idleTime += AT[i] - CT[i - 1];
            gantt[2 * i + 1] = CT[i - 1];
            gantt[2 * i + 2] = AT[i];
            CT[i] = AT[i] + BT[i];
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];
        }
        else
        {
            CT[i] = CT[i - 1] + BT[i];
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];
        }
        awt += WT[i];
        atat += TAT[i];

        gantt[2 * i + 1] = CT[i - 1];
        gantt[2 * i + 2] = CT[i];
    }

    printf("Gantt Chart:\n");
    for (int i = 0; i < 2 * n; i++)
    {
        if (i % 2 == 0)
        {
            printf("%.2f -> ", gantt[i]);
        }
        else
        {
            printf("P%d -> ", process[i / 2]);
        }
    }
    printf("%.2f\n", gantt[2 * n]);

    printf("\nPno\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", process[i], AT[i], BT[i], CT[i], WT[i], TAT[i]);
    }

    printf("\nAverage Waiting Time (AWT): %.2f\n", awt / n);
    printf("Average Turnaround Time (ATAT): %.2f\n", atat / n);
    printf("Total Idle Time: %.2f\n", idleTime);
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n];
    float AT[n], BT[n];

    printf("Enter arrival time (AT) and burst time (BT) for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%f %f", &AT[i], &BT[i]);
        process[i] = i + 1;
    }

    bubbleSort(AT, process, BT, n);
    fcfs(AT, process, BT, n);

    return 0;
}
