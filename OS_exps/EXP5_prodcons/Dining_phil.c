#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

void think(int id)
{
    printf("Philosopher %d is thinking.\n", id);
    sleep(rand() % 5 + 1); 
}

void eat(int id)
{
    printf("Philosopher %d is eating.\n", id);
    sleep(rand() % 5 + 1); 
}

void philosopher(int id)
{
    while (1)
    {
        think(id);
        eat(id);
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        { // Child process
            philosopher(i);
            exit(0);
        }
        else if (pid < 0)
        { // Fork failed
            perror("Fork failed");
            exit(1);
        }
    }

    // Wait for all philosopher processes to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        wait(NULL);
    }

    return 0;
}
