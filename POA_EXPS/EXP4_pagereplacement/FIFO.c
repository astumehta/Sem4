#include <stdio.h>
#define size 3

int frames[7] = {1,3,0,3,5,6,3};

void fifo()
{
    int memory[size] = {-1};
    int hits = 0;

    for (int i = 0; i < 7; i++)
    {
        int page = frames[i];
        int pageExists = 0;
        //page exists?
        for (int j = 0; j < size; j++)
        {
            if (memory[j] == page)
            {
                pageExists = 1;
                hits++;
                break;
            }
        }
        //page not existing , remove last page and make space for new page on top to give memory[0] to new page
        if (!pageExists)
        {
            for (int j = size - 1; j >= 1; j--)
            {
                memory[j] = memory[j - 1];
            }
            memory[0] = page;
        }

        for (int j = 0; j < size; j++)
        {
            printf("%d ", memory[j]);
        }
        printf("\n");
    }

    float hit_percentage = ((float)hits / 7) * 100;
    printf("\nHit Percentage: %.2f%%\n", hit_percentage);
}

int main()
{
    fifo();
    return 0;
}
