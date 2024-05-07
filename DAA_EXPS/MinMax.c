#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int a[n], min, max;

void minmax(int low,int high)
{
    int mid,min1,max1;
    if(low==high)
    {
        min=max=a[low];
    }
    else if(low==high-1)
    {
        if(a[low]<a[high])
        {
            min=a[low];
            max=a[high];
        }
        else
        {
            min=a[high];
            max=a[low];
        }
    }
    else
    {
        mid=(low+high)/2;
        minmax(low,mid);
        min1=min;
        max1=max;
        minmax(mid+1,high);
        if(max1>max)
        {
            max=max1;
        }
        if(min1<min)
        {
            min=min1;
        }  
    }
}
void main()
{
    int i;
    for (i = 0; i <n; i++)
    {
        printf("Enter data: ");
        scanf("%d",&a[i]);
    }
    minmax(0,n-1);
    printf("%d is min",min);
    printf("\n%d is max",max);

    
}