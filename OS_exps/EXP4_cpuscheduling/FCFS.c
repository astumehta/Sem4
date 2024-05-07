#include <stdio.h>
int process[] = {1, 2, 3, 4, 5};
    int AT[] = {0, 3, 5, 6, 8};
    int BT[] = {10, 5, 2, 6, 4};
void bubbleSort(int AT[], int process[], int BT[], int n) {
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
    int gantt[6];
    int awt=0;
    int atat=0;
    gantt[0]=AT[0];
    for(int i=1;i<5;i++)
    {
        gantt[i]=gantt[i-1]+BT[i-1];
        awt+=gantt[i]-AT[i];
    }
    for(int i=0;i<5;i++)
    {
        atat+=BT[i];
    }

    float avgawt=(float)awt/5;
    float avgatat=(float)atat/5;
    printf("%f",avgawt);
    printf("%f",avgatat);
}

int main() {
    
    int n = sizeof(process) / sizeof(process[0]);

    bubbleSort(AT, process, BT, n);
    fcfs();
    return 0;
}
