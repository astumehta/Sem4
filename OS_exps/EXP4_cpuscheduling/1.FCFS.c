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
    float gantt[n];
    float CT[n], WT[n], TAT[n];

    gantt[0] = AT[0];
    for (int i = 1; i < n; i++)
    {
        gantt[i] = BT[i - 1] + gantt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        CT[i] = gantt[i];
        WT[i] = CT[i] - AT[i];
        TAT[i] = WT[i] + BT[i];
        awt += WT[i];
        atat += TAT[i];
    }

    printf("Pno\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", process[i], AT[i], BT[i], CT[i], WT[i], TAT[i]);
    }

    printf("\nAverage Waiting Time (AWT): %.2f", awt / n);
    printf("\nAverage Turnaround Time (ATAT): %.2f", atat / n);
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