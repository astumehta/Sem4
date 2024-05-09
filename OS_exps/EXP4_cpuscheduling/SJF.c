#include <stdio.h>
#define INT_MAX 999

int process[] = {1, 2, 3, 4, 5};
int AT[] = {1, 3, 6, 7, 9};
int BT[] = {7, 3, 2, 10, 8};
int visited[5] = {0};

void bubbleSort(int AT[], int process[], int BT[], int n)
{
    int i, j, temp_process, temp_AT, temp_BT;
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

void bubbleSortBT(int BT[], int process[], int AT[], int n)
{
    int i, j, temp_process, temp_AT, temp_BT;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (BT[j] > BT[j + 1])
            {
                temp_BT = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp_BT;

                temp_AT = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp_AT;

                temp_process = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp_process;
            }
        }
    }
}

void sjf()
{
    bubbleSort(AT, process, BT, 5);

    int gantt[100];
    for (int i = 0; i < 100; i++)
    {
        gantt[i] = 0;
    }

    int total = AT[0];
    for (int i = 0; i < 5; i++)
    {
        total += BT[i];
    }

    printf("Gantt Chart:\n");

    int index = 0;
    for (int i = 0; i < total;)
    {
        int shortest = -1;
        int shortestBT = INT_MAX;

        for (int j = 0; j < 5; j++)
        {
            if (!visited[j] && AT[j] <= i && BT[j] < shortestBT)
            {
                shortest = j;
                shortestBT = BT[j];
            }
        }

        if (shortest != -1)
        {
            gantt[index++] = process[shortest];
            i += BT[shortest];
            visited[shortest] = 1;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < 100 && gantt[i] != 0; i++)
    {
        printf("P%d ", gantt[i]);
    }
    printf("\n");

    int WT[5], TAT[5];
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < 5; i++)
    {
        WT[i] = gantt[i] - AT[i];
        totalWT += WT[i];
        TAT[i] = gantt[i] + BT[i] - AT[i];
        totalTAT += TAT[i];
    }

    printf("\nProcess\tWT\tTAT\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d\t%d\t%d\n", process[i], WT[i], TAT[i]);
    }

    float AWT = totalWT / 5;
    float ATAT = totalTAT / 5;

    printf("\nAverage Waiting Time: %.2f\n", AWT);
    printf("Average Turnaround Time: %.2f\n", ATAT);
}

void main()
{
    sjf();
}
