

// EASY JUST MEMORISE 3 FUNCTIONS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 20

int board[N][N];
int count = 0;

void printSolution(int n)
{
    int i, j;
    printf("\n\nSolution : %d\n\n", ++count);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int row, int col, int n)
{
    int i, j;
    // Check this row on left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQueensUtil(int col, int n)
{
    if (col == n)
    {
        printSolution(n);
        return true;
    }
    bool result = false;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n))
        {
            board[i][col] = 1;
            result = solveNQueensUtil(col + 1, n) || result;
            board[i][col] = 0;
        }
    }
    return result;
}

bool solveNQueens(int n)
{
    if (n <= 0 || n > N)
    {
        printf("Invalid input.\n");
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    return solveNQueensUtil(0, n);
}
int main()
{
    int n;
    printf("Enter number of Queens : ");
    scanf("%d", &n);
    if (solveNQueens(n))
        printf("\nTotal solutions: %d\n", count);
    else
        printf("\nNo solution exists for %d queens.\n", n);
    return 0;
}
