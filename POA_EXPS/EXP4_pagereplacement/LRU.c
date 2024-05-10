#include <stdio.h>


// Function to check if a page is present in the frame
int isInFrame(int frame[], int pageNumber)
{
    for (int i = 0; i < 3; i++)
    {
        if (frame[i] == pageNumber)
        {
            return i; // Return the index of the page if found in frame
        }
    }
    return -1; // Return -1 if page not found in frame
}

// Function to print the frames
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
    int frame[3] = {0};     // Represents the frame
    int usageInfo[3] = {0}; // Keeps track of the usage information for each page
    int count = 0;              // Number of pages currently in the frame
    int pageFaults = 0;              // Number of page faults

    for (int i = 0; i < numPages; i++)
    {
        // If page is not present in frame, add it to the frame
        int pagePosition = isInFrame(frame, pages[i]);
        if (pagePosition == -1)
        {
            // If frame is not full, just add the page to the end
            if (count < 3)
            {
                frame[count] = pages[i];
                usageInfo[count] = i; // Store the usage information
                count++;
            }
            else
            { // If frame is full, find the least recently used page (LRU) and replace it
                int lruIndex = 0;
                for (int j = 1; j < 3; j++)
                {
                    if (usageInfo[j] < usageInfo[lruIndex])
                    {
                        lruIndex = j;
                    }
                }
                frame[lruIndex] = pages[i];
                usageInfo[lruIndex] = i; // Update the usage information
                pageFaults++;
            }
        }
        else
        { // If page is already present, update its usage information
            usageInfo[pagePosition] = i;
        }
        printFrames(frame, count); // Print frames at each step
    }
    return pageFaults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3}; // Reference string
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
