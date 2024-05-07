#include <stdio.h>
#define SIZE 4

int frames[14] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

int main() {
    int hits = 0;
    int miss = 0;

    printf("Frames:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("F%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < 14; i++) {
        int found = 0;
        for (int j = 0; j < SIZE; j++) {
            if (frames[i] == frames[j]) {
                found = 1;
                hits++;
                break;
            }
        }
        if (!found) {
            miss++;
            int replaceIndex = -1;
            for (int j = i + 1; j < 14; j++) {
                int k;
                for (k = 0; k < SIZE; k++) {
                    if (frames[k] == frames[j]) {
                        break;
                    }
                }
                if (k == SIZE) {
                    replaceIndex = j;
                    break;
                }
            }
            if (replaceIndex == -1) {
                replaceIndex = 0;
            }
            frames[replaceIndex] = frames[i];
        }
        for (int j = 0; j < SIZE; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Number of hits: %d\n", hits);
    printf("Number of misses: %d\n", miss);

    return 0;
}
