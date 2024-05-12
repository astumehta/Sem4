#include<stdio.h>

int process[5]={1,2,3,4,5};
int AT[] = {1, 3, 6, 7, 9};
int BT[] = {7, 3, 2, 10, 8};
int visited[5]={0};
int completed=0;
int final[5];

void bubblesort()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(AT[j]>AT[j+1])
            {
                int temp=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=temp;

                temp=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp;

                temp=process[j];
                process[j]=process[j+1];
                process[j+1]=temp;
            }
        }
    }
}
void sjf()
{
    int tat[5];
    int awt[5];
    int time = 0;
    int CT[5];
    int i;

    while (completed < 5)
    {
        int min_burst = 1000;
        int min_index = -1;
        for (i = 0; i < 5; i++)
        {
            if (visited[i] == 0 && AT[i] <= time && BT[i] < min_burst)
            {
                min_burst = BT[i];
                min_index = i;
            }
        }

        if (min_index == -1)
        {
            time++;
            continue;
        }

        CT[min_index] = time + BT[min_index];
        tat[min_index] = CT[min_index] - AT[min_index];
        awt[min_index] = tat[min_index] - BT[min_index];

        final[completed] = process[min_index];
        visited[min_index] = 1;

        time += BT[min_index];
        completed++;
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], AT[i], BT[i], CT[i],
               tat[i], awt[i]);
    }
}

void main()
{
    bubblesort();
    sjf();
}