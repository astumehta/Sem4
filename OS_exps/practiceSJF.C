#include <stdio.h>
int AT[] = {1, 3, 6, 7, 9};
int BT[] = {7, 3, 2, 10, 8};
int CT[5];
int tat[5];
int awt[5];
int visited[5];
int time = 0;
int complete = 0;
int process[5]={1,2,3,4,5};
int remaining[5]={6, 2, 8, 3, 4};
void bubblesort()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
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
}
void sjf()
{
    bubblesort(AT,process,BT); 
    time=time+AT[0]; 
    while(complete<5)
    {
        int min_burst=1000;
        int min_index=-1;
        for(int j=0;j<5;j++)
        {
            if(visited[j]==0 && AT[j]<=time && BT[j]<min_burst)
            {
                min_burst=BT[j];
                min_index=j;
            }
        }
        CT[min_index]=time+BT[min_index];
        tat[min_index]=CT[min_index]-AT[min_index];
        awt[min_index]=tat[min_index]-BT[min_index];

        printf("%d\n",process[min_index]);
        visited[min_index]=1;

        time=time+BT[min_index];
        complete++;
    } 
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t",process[i],AT[i],BT[i],CT[i],tat[i],awt[i]);
        printf("\n");
    }
}
void main()
{
    sjf();
}