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
void clook()
{
    int sum=0;
    int i=0;
    int j=0;
    while(a[i]<=head)
    {
        i++;
    }
    
    sum=a[n-1]-head;
    sum+=a[n-1]-a[0];

    for(int k=j;k<i-1;k++)
    {
        sum+=a[k+1]-a[k];
    }

    printf("%d",sum);
    

}

void main()
{
    bubblesort();
    clook();
}