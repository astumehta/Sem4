#include <stdio.h>
#define INT_MAX 999
int process[] = {1, 2, 3, 4};
float AT[] = {0, 2, 3, 5};
float BT[] = {4, 3, 2, 1};
int completed[4] = {0};
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

void sjf()
{
    float awt = 0;
    float atat = 0;
    float gantt[4];
    int remainingBT[4];

    for (int i = 0; i < 4; i++)
    {
        remainingBT[i] = BT[i];
    }

    // Sort processes based on arrival time
    bubbleSort(AT, process, BT, 4);

    // Initialize gantt chart
    gantt[0] = AT[0];
    gantt[1] = gantt[0] + BT[0];
    completed[0] = 1;

    for (int i = 1; i < 4; i++)
    {
        int min_index = -1;
        int min_BT = INT_MAX;
        
        // Find the process with the minimum remaining burst time
        for (int j = 0; j < 4; j++)
        {
            if (!completed[j] && AT[j] <= gantt[i] && remainingBT[j] < min_BT)
            {
                min_index = j;
                min_BT = remainingBT[j];
            }
        }

        // Update gantt chart and remaining burst time
        if (min_index != -1)
        {
            gantt[i + 1] = gantt[i] + remainingBT[min_index];
            remainingBT[min_index] = 0;
            completed[min_index] = 1;
        }
        else
        {
            // No process is available, move to the next arrival time
            gantt[i + 1] = AT[i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        awt += gantt[i + 1] - AT[i] - BT[i];
        atat += gantt[i + 1] - AT[i];
    }

    printf("Gantt Chart:\n");
    printf("%.2f ", gantt[0]);
    for (int i = 0; i < 4; i++)
    {
        printf("P%d %.2f ", process[i], gantt[i + 1]);
    }
    printf("\n");

    printf("AWT: %.2f\n", awt / 4);
    printf("ATAT: %.2f\n", atat / 4);
}

int main()
{
    int n = sizeof(process) / sizeof(process[0]);

    bubbleSort(AT, process, BT, n);
    sjf();
    return 0;
}
