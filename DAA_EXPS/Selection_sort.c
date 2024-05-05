#include <stdlib.h>
#include <stdio.h>

int a[100];
int n;


void selectionSort()
{
    int imin,i,j,temp;
    for(i=0;i<n;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                imin=j;
            }
        }
        temp=a[imin];
        a[imin]=a[i];
        a[i]=temp;
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
    selectionSort();
    for (int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}