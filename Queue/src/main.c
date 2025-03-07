#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main() {
    struct Queue queue;
    int size;
    printf("How many elements: ");
    scanf("%d", &size);
    int choice;
    queue.data = (int*) malloc(size*sizeof(int));
    int choice;
    int value;
    do {
        printf("quit 0\nenqueue 1\ndequeue 2\npeek 3\nisEmpty 4\nisFull 5\ngetSize 6\n\nchoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                choice = 0;
        }
    } while (choice != 0);
    free(queue.data);
    return 0;
}