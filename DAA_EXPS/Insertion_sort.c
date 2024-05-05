#include <stdlib.h>
#include <stdio.h>

int a[100];
int n;

void insertionSort()
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
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
    insertionSort();
    for (int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}