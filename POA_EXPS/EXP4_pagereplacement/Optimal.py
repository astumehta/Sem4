#include <stdio.h>

void optimal(int pages[], int size) {
    int miss = 0;
    int hit = 0;
    int solution_pages[14];
    int index[14];

    for (int i = 0; i < size; i++) {
        if (i < 14) {
            solution_pages[i] = pages[i];
            index[i] = i + 1;
            miss++;
            printf("Step %d: Element %d inserted into memory at index %d (Miss)\n", (i + 1), pages[i], i);
        } else {
            int found = 0;
            for (int j = 0; j < 14; j++) {
                if (solution_pages[j] == pages[i]) {
                    hit++;
                    index[j] = i + 1; // Update index of current reference
                    found = 1;
                    printf("Step %d: Element %d found in memory at index %d (Hit)\n", (i + 1), pages[i], j);
                    break;
                }
            }
            if (!found) {
                // Find the page to replace using Optimal Page Replacement Algorithm
                int farthestIndex = -1;
                int pageToReplace = -1;
                for (int j = 0; j < 14; j++) {
                    int foundFutureReference = 0;
                    for (int k = i + 1; k < size; k++) {
                        if (solution_pages[j] == pages[k]) {
                            index[j] = k + 1; // Update index of future reference
                            foundFutureReference = 1;
                            break;
                        }
                    }
                    if (!foundFutureReference) {
                        pageToReplace = j;
                        break;
                    } else {
                        if (index[j] > farthestIndex) {
                            farthestIndex = index[j];
                            pageToReplace = j;
                        }
                    }
                }

                // Replace the page
                solution_pages[pageToReplace] = pages[i];
                index[pageToReplace] = i + 1;
                miss++;
                printf("Step %d: Element %d inserted into memory at index %d (Miss)\n", (i + 1), pages[i], pageToReplace);
            }
        }
    }

    printf("Total Misses: %d\n", miss);
    printf("Total Hits: %d\n", hit);
}

int main() {
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int size = sizeof(pages) / sizeof(pages[0]);

    optimal(pages, size);

    return 0;
}
