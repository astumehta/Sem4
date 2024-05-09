#include <stdio.h>
#include <stdlib.h>

#define size 5

int buffer[size];
int in = 0;
int out = 0;

void producer()
{

    if (((in + 1) % size) != out)
    {
        int item = rand() % 100; 
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % size;
    }
    else
    {
        printf("Buffer is full!\n");
    }
}

void consumer()
{
    if (in != out)
    {                          
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % size;
    }
    else
    {
        printf("Buffer is empty!\n");
    }
}

void displayBuffer()
{
    printf("Current Buffer: ");
    if (in == out)
    {
        printf("Empty\n");
        return;
    }
    int i;
    for (i = out; i != in; i = (i + 1) % size)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    while (1)
    {
        printf("\nEnter your choice from the menu below:\n 1 - Produce\n 2 - Consume\n 3 - Display Buffer\n 4 - Exit\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            displayBuffer();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }
    return 0;
}
