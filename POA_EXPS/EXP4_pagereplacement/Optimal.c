#include <stdio.h>

void optimal(int arr[], int size, int capacity) {
    int miss = 0;
    int hit = 0;
    int sol_arr[capacity];
    int index[capacity];

    for (int i = 0; i < size; i++) {
        if (i < capacity) {
            sol_arr[i] = arr[i];
            index[i] = i + 1;
            miss++;
            printf("Step %d: Element %d inserted into memory at index %d (Miss)\n", (i + 1), arr[i], i);
        } else {
            int found = 0;
            for (int j = 0; j < capacity; j++) {
                // Check if the page is already in memory
                if (sol_arr[j] == arr[i]) {
                    hit++;
                    index[j] = i + 1; // Update index of current reference
                    found = 1;
                    printf("Step %d: Element %d found in memory at index %d (Hit)\n", (i + 1), arr[i], j);
                    break;
                }
            }
            if (!found) {
                // Find the page to replace using Optimal Page Replacement Algorithm
                int farthestIndex = -1;
                int pageToReplace = -1;
                for (int j = 0; j < capacity; j++) {
                    int foundFutureReference = 0;
                    for (int k = i + 1; k < size; k++) {
                        if (sol_arr[j] == arr[k]) {
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
                sol_arr[pageToReplace] = arr[i];
                index[pageToReplace] = i + 1;
                miss++;
                printf("Step %d: Element %d inserted into memory at index %d (Miss)\n", (i + 1), arr[i], pageToReplace);
            }
        }
    }

    printf("Total Misses: %d\n", miss);
    printf("Total Hits: %d\n", hit);
}

int main() {
    int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int capacity = 4;

    optimal(arr, size, capacity);

    return 0;
}
