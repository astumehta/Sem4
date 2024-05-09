#include <stdio.h>
#define SIZE 4
// for if for
int frames[14] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

int main()
{
    int recent[SIZE] = {-1};
    int hits = 0;
    int miss = 0;

    printf("Frames:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("F%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < 14; i++)
    {
        int flag = 1;

        for (int j = 0; j < SIZE; j++)
        {
            if (frames[i] == frames[j])
            {
                recent[j] = i;
                flag = 0;
                hits++;
                break;
            }
        }

        if (flag)
        {
            miss++;
            int min_index = 0;
            for (int j = 1; j < SIZE; j++)
            {
                if (recent[j] < recent[min_index])
                {
                    min_index = j;
                }
            }
            frames[min_index] = frames[i];
            recent[min_index] = i;
        }

        for (int j = 0; j < SIZE; j++)
        {
            if (frames[j] == -1)
            {
                printf("-\t");
            }
            else
            {
                printf("%d\t", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of hits: %d\n", hits);
    printf("Number of misses: %d\n", miss);

    return 0;
}
