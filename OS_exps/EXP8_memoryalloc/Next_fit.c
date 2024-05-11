#include <stdio.h>


int process[5] = {1, 2, 3, 4, 5};
int incoming[5] = {450, 417, 112, 290, 90};
int memory[5] = {125, 500, 200, 300, 600};

int visited[5] = {0};
int allocated[5] = {0};

void nextfit() {
    int previous = -1;
    for (int i = 0; i < 5; i++) {
        int j;
        for (j = previous + 1; j < 5; j++) {
            if (incoming[i] <= memory[j] && !visited[j]) {
                allocated[j] = process[i];
                visited[j] = 1;
                previous = j;
                break;
            }
        }
        if (j == 5) {
            printf("Process P%d cannot be allocated.\n", process[i]);
        }
    }
}

int main() {
    nextfit();
    
    printf("Processes\tIncoming\tMemory\n");
    for (int i = 0; i < 5; i++) {
        if (allocated[i] != 0) {
            printf("P%d\t\t%d\t\t%d\n", allocated[i], incoming[allocated[i] - 1], memory[i]);
        }
    }
    return 0;
}

