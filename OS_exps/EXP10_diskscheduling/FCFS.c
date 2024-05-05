#include<stdio.h>
#include<stdlib.h>
#define n 7
int head=50;
int a[n]={82,170,43,140,24,16,190};

void fcfs()
{
    int totalheadmov=0;
    int prev=head;
    for(int i=0;i<n;i++)
    {
        totalheadmov+=abs(a[i]-prev);
        prev=a[i];
    }
    printf("%d",totalheadmov);
}
void main()
{
    fcfs();
}