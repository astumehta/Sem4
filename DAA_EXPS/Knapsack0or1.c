#include <stdio.h>

#define MAX_W 100
#define MAX_N 100

float knapsack_fractional(int W, int wt[], int val[], int n)
{
    float dp[MAX_W + 1][MAX_N + 1];

    // Initialize the table: 0 profit for 0 capacity or no items
    // Same like we do in LCS first two for loops
    for (int i = 0; i <= W; i++)
    {
        dp[i][0] = 0.0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0.0;
    }

    // Build the table: considering all possible capacities and items
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wt[j - 1] > i)
            {
                // If item weight exceeds capacity, inherit from previous item
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                // Choose the maximum between including or excluding the item
                float include = val[j - 1] + dp[i - wt[j - 1]][j - 1];
                float exclude = dp[i][j - 1];
                dp[i][j] = (include > exclude) ? include : exclude;
            }
        }
    }

    // Return the maximum profit for the given capacity
    return dp[W][n];
}

int main()
{
    int val[] = {1, 2, 5, 6};             
    int wt[] = {2, 3, 4, 5};              
    int W = 8;                            
    int n = sizeof(val) / sizeof(val[0]); 

    float max_profit = knapsack_fractional(W, wt, val, n);
    printf("Maximum value that can be obtained: %.2f\n", max_profit);

    return 0;
}