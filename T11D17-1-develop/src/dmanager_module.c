#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

void initialize_doors(struct door *doors);
void sort(struct door *doors);
void swap(int *a, int *b);
void close(struct door *doors);
void output(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    close(doors);
    output(doors);
    return 0;
}

void sort(struct door *doors) {
    for (int j = 0; j < DOORS_COUNT - 1; j++)
        for (int i = 0; i < DOORS_COUNT - j - 1; i++)
            if (doors[i].id > doors[i + 1].id) swap(&doors[i].id, &doors[i + 1].id);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void close(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) doors[i].status = 0;
}

void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        if (i == DOORS_COUNT - 1)
            printf("%d, %d", doors[i].id, doors[i].status);
        else
            printf("%d, %d\n", doors[i].id, doors[i].status);
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
