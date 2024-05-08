
// EASY SAME AS ALGO EXACT 

#include <stdio.h>
#define max 100
int n, m;
int w[max];
int x[max];
void sumOfSubsets(int s, int k, int r)
{
    int i;
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }
    if (s + w[k + 1] <= m && s + r - w[k] >= m)
    {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}
int main()
{
    int i;
    int total = 0;
    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter element %d: ", i + 1);
    for (i = 0; i < n; i++)
    {

        printf("Enter element %d: ", i + 1);
        scanf("%d", &w[i]);
        total = total + w[i];
        x[i] = 0;
    }
    printf("Sum : ");
    scanf("%d", &m);
    sumOfSubsets(0, 0, total);
}