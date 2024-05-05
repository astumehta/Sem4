#include <stdio.h>
#include <stdlib.h>

#define n 7

int head = 50;
int a[n] = {82, 170, 43, 140, 24, 16, 190};
// 16,24,43,82,140,170,190
// 34,26,7,
int mindist[7];
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

void sstf()
{
    int i=0;
    int left=0;
    int right=0;
    int sum=0;
    while(a[i]<=head)
    {
        i++;
    }
    i-=1;
    if(abs(a[i]-head)<abs(a[i+1]-head))
    {
        left=1;
    }
    else
    {
        right=1;
    }
    if(left==1)
    {
        sum=head-a[i];
        for(int k=i;k>0;k--)
        {
            sum+=(a[k]-a[k-1]);
        }
        sum+=a[i+1]-a[0];
        for(int k=i+1;k<n-1;k++)
        {
            sum+=abs(a[k]-a[k+1]);
        }
    }
    else
    {
        sum=a[i+1]-head;
        for(int k=i+1;k<n-1;k++)
        {
            sum+=abs(a[k]-a[k+1]);
        }
        sum+=a[n-1]-a[i];
        for(int k=i;k>0;k--)
        {
            sum+=(a[k]-a[k-1]);
        }

    }
    printf("%d",sum);

}

void main()
{
    bubblesort();
    sstf();
}
