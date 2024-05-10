#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

int frames[SIZE]; // Frames in memory
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Reference string
int page_count = sizeof(pages) / sizeof(pages[0]);
bool isPresent(int page) {
    for (int i = 0; i < SIZE; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

void replacePage(int page, int *page_faults, int *index) {
    int lru_index = 0;
    for (int i = 1; i < SIZE; i++) {
        if (index[i] < index[lru_index]) {
            lru_index = i;
        }
    }
    frames[lru_index] = page;
    (*page_faults)++;
}

void printFrames() {
    for (int i = 0; i < SIZE; i++) {
        if (frames[i] == -1) {
            printf("-\t");
        } else {
            printf("%d\t", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int page_faults = 0;
    int hits = 0;
    int index[SIZE]; // Index to store the latest occurrence of pages in frames
    for (int i = 0; i < SIZE; i++) {
        frames[i] = -1; // Initialize frames to -1
        index[i] = 0; // Initialize index to 0
    }

    printf("Frames:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("F%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < page_count; i++) {
        if (isPresent(pages[i])) {
            hits++;
        } else {
            replacePage(pages[i], &page_faults, index);
        }
        index[pages[i]] = i;
        printFrames();
    }

    printf("Number of hits: %d\n", hits);
    printf("Number of misses: %d\n", page_faults);

    return 0;
}
