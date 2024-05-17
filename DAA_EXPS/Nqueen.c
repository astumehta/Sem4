#include <stdio.h>
#include <stdlib.h>

int n, x[10];

int place(int k, int j)
{
    for (int i = 0; i < k; i++)
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    return 1;
}

void NQueens(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", x[i] + 1);
        }
        printf("\n");
        return;
    }
    for (int j = 0; j < n; j++)
        if (place(k, j))
        {
            x[k] = j;
            NQueens(k + 1);
        }
}

int main()
{
    printf("Enter the chessboard size: ");
    scanf("%d", &n);
    NQueens(0);
    return 0;
}
