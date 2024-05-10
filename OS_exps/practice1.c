#include <stdio.h>
#define SIZE 3
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

int isinframe(int frame[], int pgno, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (frame[i] == pgno)
        {
            return i;
        }
    }
    return -1;
}
void print(int frame[])
{
    for(int i=0;i<3;i++)
    {
        printf("%d",frame[i]);
    }
    printf("\n");
}

int lru()
{
    int hit = 0;
    int miss = 0;
    int count = 0;
    int frame[SIZE] = {0};
    int usage[SIZE] = {0};
    for (int i = 0; i < 14; i++)
    {
        int pagenumber = isinframe(frame, pages[i], count);
        if (pagenumber==-1)
        {
            miss++;

            if (count < 3)
            {
                frame[count] = pages[i];
                usage[count] = i;
                count++;
            }
            else
            {
                int index = 0;
                for (int j=1;j<3;j++)
                {
                    if(usage[j]<usage[index])
                    {
                        index=j;
                    }
                }
                frame[index] = pages[i];
                usage[index] = i;
            }
        }
        else
        {
            usage[pagenumber]=i;
        }
        print(frame);
    }
    return miss;
    
}
void main()
{
    int miss=lru();
    printf("%d",miss);
}