#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on finish times
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

// Function to perform activity selection
void activitySelection(int start[], int finish[], int n, int maxFinish)
{
    // Initialize variables
    int i, count = 0, currentFinish = 0;

    // Sort activities based on finish times
    bubbleSortFinishTimes(start, finish, n);

    // Iterate through activities
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
    // Sample data
    int start[] = {1, 3, 0, 5, 8, 5, 8, 3, 2, 12, 14};
    int finish[] = {2, 4, 6, 7, 9, 9, 10, 5, 14, 16, 17};
    int n = sizeof(start) / sizeof(start[0]);

    // Call activitySelection function
    activitySelection(start, finish, n, 17); // Assuming max finish time as 17

    return 0;
}
