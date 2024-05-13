#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 1000

int requests = 0, tracks[MAX_TRACKS], head, disk, start, end, total, visited[MAX_TRACKS] = {0};

void sstf()
{
    int temp = head;
    int path[MAX_TRACKS];
    int path_index = 0;

    for (int j = 0; j < requests; j++)
    {
        int min = 999;
        int tempmin = 0;
        int tempi;
        for (int i = 0; i < requests; i++)
        {
            if (abs(temp - tracks[i]) < min && visited[i] != 1)
            {
                min = abs(temp - tracks[i]);
                tempmin = tracks[i];
                tempi = i;
            }
        }
        visited[tempi] = 1;
        temp = tempmin;
        total += min;
        path[path_index++] = tempmin;
    }
    printf("Total track movement: %d\n", total);
    printf("Path taken by the track: ");
    for (int i = 0; i < path_index; i++)
    {
        printf("%d ", path[i]);
    }
}

int main()
{
    printf("Enter the number of disk tracks: ");
    scanf("%d", &disk);
    printf("Enter the start and end of the disk tracks: ");
    scanf("%d %d", &start, &end);
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    printf("Enter the request queue and (-1) to stop:\n");
    while (1)
    {
        printf("Request %d: ", requests + 1);
        scanf("%d", &tracks[requests]);
        if (tracks[requests] == -1 || requests == MAX_TRACKS - 1)
        {
            break;
        }
        requests++;
    }
    sstf();
    return 0;
}