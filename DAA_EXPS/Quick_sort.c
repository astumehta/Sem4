
#include <stdlib.h>
#include <stdio.h>

int a[100];
int n;

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quick_Sort(int low,int high)
{
    if(low<high)
    {
        int loc=partition(low,high);
        quick_Sort(low,loc-1);
        quick_Sort(loc+1,high);
    }
}
int partition(int low,int high)
{
    int pivot=a[low];

    int start=low;
    int end=high;
    
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}


int main()
{
    int data, val;
    printf("Enter number of data items in the array: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        a[i] = data;
    }
    quick_Sort(0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}