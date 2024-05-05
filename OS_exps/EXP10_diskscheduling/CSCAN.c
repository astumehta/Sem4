#include<stdio.h>
#include<stdlib.h>
#define n 7
int head=50;
int min=0;
int max=199;
int a[n]={82,170,43,140,24,16,190};

void bubblesort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//right
void cscan()
{
    int sum=0;
    int i=0;
    while(a[i]<=head)
    {
        i++;
    }
    sum=max-head;
    sum+=max-min;
    sum+=a[i-1]-min;
    printf("%d",sum);
    

}

void main()
{
    bubblesort();
    cscan();
}