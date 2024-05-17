// EASY EKDUM

#include <stdio.h>
#define v 5
int parent[v][v];
void floyd_warshall(int a[v][v], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0 && a[i][j]!=1000){
                parent[i][j]=i;
            }
            else{
                parent[i][j]=-1;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    parent[i][j]=k;
                }
            }
        }
    }
    printf("All Pairs Shortest Path is :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Parents :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", parent[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[v][v]={
        {0,4,7,9,8},
        {4,0,1,1000,1000},
        {7,1,0,2,1000},
        {9,1000,2,0,6},
        {8,1000,1000,6,0},
};
    floyd_warshall(a, n);
}