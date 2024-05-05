#include <stdlib.h>
#include <stdio.h>

int a[50];
int n;



void binarySearch(int low,int high,int num)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==num)
        {
            printf("Num found at position %d\n",mid+1);
        }
        else if(a[mid]>num)
        {
            binarySearch(low,mid-1,num);
        }
        else if(a[mid]<num)
        {
            binarySearch(mid+1,high,num);
        }
        else
        {
            printf("Num not found\n");
        }
    }
    else
    {
        printf("Enter valid limits\n");
    }
}

void main()
{
    int data,val;
    printf("Enter number of data items in the array: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        a[i]=data;
    }

    // BINARY SEARCH
    printf("Data to search? : \n");
    scanf("%d",&val);
    binarySearch(0,n-1,val);

}
