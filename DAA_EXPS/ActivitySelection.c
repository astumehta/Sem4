


// VERY EASYYY

#include <stdio.h>
#include <stdlib.h>

void bubbleSortFinishTimes(int start[], int finish[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                // Swap finish times
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                // Swap start times accordingly
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }
}

void activitySelection(int start[], int finish[], int n, int maxFinish)
{

    int i, count = 0, currentFinish = 0;
    bubbleSortFinishTimes(start, finish, n);
    printf("Activity sequence:\n");
    for (i = 0; i < n; i++)
    {
        if (start[i] >= currentFinish)
        {
            printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);
            currentFinish = finish[i];
            count++;
        }
    }

    printf("Maximum number of activities that can be scheduled: %d\n", count);
}

int main()
{

    int start[] = {1, 3, 0, 5, 3, 5, 6, 7, 8, 2, 12};
    int finish[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, finish, n, 16);

    return 0;
}
