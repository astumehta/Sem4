#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

int isInFrame(int frame[], int pageNumber, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (frame[i] == pageNumber)
        {
            return i;
        }
    }
    return -1; 
}

void printFrames(int frame[], int count)
{
    printf("Frame: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", frame[i]);
    }
    printf("\n");
}

int lru(int pages[], int numPages)
{
    int frame[SIZE] = {0};
    int usageInfo[SIZE] = {0}; 
    int count = 0;              
    int pageFaults = 0;              

    for (int i = 0; i < numPages; i++)
    {
        int pagePosition = isInFrame(frame, pages[i], count);
        if (pagePosition == -1)
        {
            pageFaults++;
            if (count < SIZE)
            {
                frame[count] = pages[i];
                usageInfo[count] = i;
                count++;
            }
            else
            { 
                int lruIndex = 0;
                for (int j = 1; j < SIZE; j++)
                {
                    if (usageInfo[j] < usageInfo[lruIndex])
                    {
                        lruIndex = j;
                    }
                }
                frame[lruIndex] = pages[i];
                usageInfo[lruIndex] = i;
            }
        }
        else
        { 
            usageInfo[pagePosition] = i;
        }
        printFrames(frame, count);
    }
    return pageFaults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    printf("Reference String: ");
    for (int i = 0; i < numPages; i++)
    {
        printf("%d ", pages[i]);
    }
    printf("\n");

    int pageFaults = lru(pages, numPages);
    printf("Total page faults using LRU: %d\n", pageFaults);

    return 0;
}
