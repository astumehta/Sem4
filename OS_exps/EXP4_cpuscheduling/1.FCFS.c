#include <stdio.h>
int process[] = {1, 2, 3, 4};
    float AT[] = {0,2,3,5};
    float BT[] = {4,3,2,1};
void bubbleSort(float AT[], int process[], float BT[], int n) {
    int i, j, temp_process, temp_AT, temp_BT;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {
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

void fcfs()
{
    float awt=0;
    float atat=0;
    float gantt[5];
    gantt[0]=AT[0];
    for(int i=1;i<5;i++)
    {
        gantt[i]=BT[i-1]+gantt[i-1];
    }
    for(int i=0;i<5;i++)
    {
        printf("%f->",gantt[i]);
    }
    for(int i=0;i<4;i++)
    {
        awt=awt+gantt[i]-AT[i];
    }
    printf("\nAWT IS %f",awt/4);


    for(int i=0;i<4;i++)
    {
        atat=atat+(gantt[i+1]-AT[i]);
    }
    printf("\nATAT IS %f",atat/4);
}

int main() {
    
    int n = sizeof(process) / sizeof(process[0]);

    bubbleSort(AT, process, BT, n);
    fcfs();
    return 0;
}
