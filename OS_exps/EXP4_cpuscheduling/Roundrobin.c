#include <stdio.h>
// GETTING WRONG OUTPUT DO NOT FOLLOW
int process[] = {1, 2, 3, 4, 5};
int AT[] = {0, 5, 1, 6, 8};
int BT[] = {8, 2, 7, 3, 5};
int timequant = 3;
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

void roundrobin()
{
    int totaltime = 0;
    int n = 5;
    int remainingBT[5];
    for (int i = 0; i < n; i++)
    {
        remainingBT[i] = BT[i];
    }

    printf("Time\tProcess\n");
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (remainingBT[i] > 0 && AT[i] <= totaltime)
            {
                done = 0;
                if (remainingBT[i] > timequant)
                {
                    totaltime += timequant;
                    printf("%d\tP%d\n", totaltime, process[i]);
                    remainingBT[i] -= timequant;
                }
                else
                {
                    totaltime += remainingBT[i];
                    printf("%d\tP%d\n", totaltime, process[i]);
                    remainingBT[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

int main()
{
    roundrobin();
    return 0;
}
