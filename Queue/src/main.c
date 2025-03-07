#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main() {
    struct Queue queue;
    int size;
    printf("Size of queue: ");
    scanf("%d", &size);
    initQueue(&queue, size);
    queue.data = (int*) malloc(size * sizeof(int));
    int choice;
    int value;
    printf("\n");
    do {
        printf("quit 0\nenqueue 1\ndequeue 2\npeek 3\nisEmpty 4\nisFull 5\ngetSize 6\n\nchoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n");
                printf("Value: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                printf("\n");
                printQueue(&queue);
                break;
            case 2:
                printf("\n");
                value = dequeue(&queue);
                if (value != INT_MIN) printf("Removed %d\n\n", value);
                printQueue(&queue);
                break;
            case 3:
                printf("\n");
                value = peek(&queue);
                if (value != INT_MIN) printf("Next to be removed is %d\n", value);
                break;
            case 4:
                printf("\n");
                value = isEmpty(&queue);
                if (value) printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 5:
                printf("\n");
                value = isFull(&queue);
                if (value) printf("Queue is full\n");
                else printf("Queue is not full\n");
                break;
            case 6:
                printf("\n");
                value = getSize(&queue);
                if (value != INT_MIN) printf("Queue has %d elements\n", value);
                break;
            default:
                choice = 0;
        }
        printf("\n");
    } while (choice != 0);
    free(queue.data);
    return 0;
}