#include<stdio.h>

int process[5]={1,2,3,4,5};
int AT[] = {2, 5, 1, 0, 4};
int BT[] = {6, 2, 8, 3, 4};
int remaining[5] = {6, 2, 8, 3, 4};
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

                temp=remaining[j];
                remaining[j]=remaining[j+1];
                remaining[j+1]=temp;
            }
        }
    }
}
void srtf()
{
    int tat[5];
    int awt[5];
    int time = 0;
    int CT[5];
    int i;
    int complete=0;
    time+=AT[0];
    while (complete < 5)
    {
        int min_burst = 1000;
        int min_index = -1;
        for (int i = 0; i < 5; i++)
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

            CT[min_index] = time;
            tat[min_index] = CT[min_index] - AT[min_index];
            awt[min_index] = tat[min_index] - BT[min_index];

            visited[min_index] = 1;
            complete++;
        }
    }
    printf("Process\tat\tBT\tCT\tTAT\tWT\t\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", process[i], AT[i], BT[i], CT[i], tat[i], awt[i]);
    }
    
}

void main()
{
    bubblesort();
    srtf();
}