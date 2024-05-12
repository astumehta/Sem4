#include <stdio.h>
int AT[] = {0, 1, 2, 3, 4, 5};
int BT[] = {4, 5, 1, 2, 3, 6};
int process[6]={1,2,3,4,5,6};
int final[6];
int visited[6];
int priority[] = {4, 5, 7, 2, 1, 6};
int CT[6];
int tat[6];
int awt[6];
int visited[6];
int time = 0;
int complete = 0;

void bubblesort()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (AT[j] < AT[i])
            {
                int temp = AT[j];
                AT[j] = AT[i];
                AT[i] = temp;

                temp = BT[j];
                BT[j] = BT[i];
                BT[i] = temp;

                temp = priority[j];
                priority[j] = priority[i];
                priority[i] = temp;

                temp = process[j];
                process[j] = process[i];
                process[i] = temp;
            }
        }
    }
}

void priorityNp()
{
    // int AT[] = {0, 1, 2, 3, 4, 5};
    // int BT[] = {4, 5, 1, 2, 3, 6};
    // int process[6];
    // int final[6];
    // int visited[6];
    // int priority[] = {4, 5, 7, 2, 1, 6};
    // int CT[6];
    // int tat[6];
    // int awt[6];
    // int visited[6];
    // int time = 0;
    // int complete = 0;
    time=0;
    while(complete<6)
    {
        int max_burst=-1;
        int max_index=-1;
        for(int i=0;i<6;i++)
        {
            if(AT[i]<=time && visited[i]==0 && priority[i]>max_burst)
            {
                max_burst=priority[i];
                max_index=i;
            }
        }
        CT[max_index]=time+BT[max_index];
        tat[max_index]=CT[max_index]-AT[max_index];
        awt[max_index]=tat[max_index]-BT[max_index];

        printf("%d\n",process[max_index]);
        visited[max_index]=1;

        time=time+BT[max_index];
        complete++;
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<6;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t",process[i],AT[i],BT[i],CT[i],tat[i],awt[i]);
        printf("\n");
    }
}

void main()
{
    bubblesort();
    priorityNp();
}
