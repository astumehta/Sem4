#include <stdio.h>

int allocation[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2},
};

int max[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3},
};

int visited[5] = {0};
int need[5][3];
int available[3] = {3, 3, 2};
int safeSequence[5];

void calculateNeed()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void bankers()
{
    calculateNeed();

    int work[3]; 
    for (int i = 0; i < 3; i++)
    {
        work[i] = available[i];
    }

   
    int count = 0;
    while (count < 5)
    {
        int found = 0;
        for (int i = 0; i < 5; i++)
        {
            if (!visited[i])
            {
                int canfinish = 1;

                for (int j = 0; j < 3; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canfinish = 0;
                        break;
                    }
                }
                if (canfinish)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    visited[i] = 1;
                    safeSequence[count++] = i;
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
        {
            printf("No safe sequence\n");
            return;
        }
    }

    printf("Safe sequence found: ");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d ", safeSequence[i] + 1);
    }
    printf("\n");
}

int main()
{
    bankers();
    return 0;
}
