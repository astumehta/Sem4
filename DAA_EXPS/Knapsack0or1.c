#include <stdio.h>
#define MAX 100

int n, maxWeight, stateCount;
int profit[MAX], weight[MAX];
struct State
{
    int profit, weight;
    int objects[MAX];
} states[MAX];

void knapsack()
{
    int i, j;
    states[0].profit = 0;
    states[0].weight = 0;
    for (i = 0; i < n; i++)
        states[0].objects[i] = 0;

    stateCount = 1;
    int tempCount;

    for (i = 0; i < n; i++)
    {
        struct State tempStates[MAX];
        tempCount = 0;

        for (j = 0; j < stateCount; j++)
        {
            tempStates[j].profit = states[j].profit + profit[i];
            tempStates[j].weight = states[j].weight + weight[i];
            for (int k = 0; k < n; k++)
            {
                tempStates[j].objects[k] = states[j].objects[k];
            }
            tempStates[j].objects[i] = 1;
            tempCount++;
        }

        for (j = 0; j < tempCount; j++)
        {
            if (tempStates[j].weight <= maxWeight)
            {
                states[stateCount] = tempStates[j];
                stateCount++;
            }
        }
    }

    int maxProfit = 0, maxProfitIndex = 0;
    for (i = 0; i < stateCount; i++)
    {
        if (states[i].profit > maxProfit && states[i].weight <= maxWeight)
        {
            maxProfit = states[i].profit;
            maxProfitIndex = i;
        }
    }

    printf("Maximum Profit: %d\n", maxProfit);
    printf("Selected objects: {");
    for (i = 0; i < n; i++)
    {
        if (states[maxProfitIndex].objects[i])
            printf("1,");
        else
            printf("0");
    }
    printf("}\n");
}

int main()
{
    int i;
    printf("Enter number of items:\n");
    scanf("%d", &n);
    printf("Enter weight and profit for each item:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &weight[i], &profit[i]);
    }
    printf("Enter maximum weight capacity of knapsack:\n");
    scanf("%d", &maxWeight);
    knapsack();
    return 0;
}