#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

void initQueue(struct Queue* queue, int size) {
    if (queue != NULL) {
        queue->size = size;
        queue->numOfElements = 0;
    }
    else printf("Queue is NULL\n");
}

void enqueue(struct Queue* queue, int data) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == queue->size) printf("Queue is full\n");
    else {
        *(queue->data + queue->numOfElements) = data;
        queue->numOfElements++;
    }
}

int dequeue(struct Queue* queue) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == 0) printf("Queue is empty\n");
    else {
        int value = *(queue->data + 0);
        queue->numOfElements--;
        for (int i = 0; i < queue->numOfElements; i++) {
            int temp = *(queue->data + i);
            *(queue->data + i) = *(queue->data + (i + 1));
            *(queue->data + (i + 1)) = temp;
        }
        return value;
    }
    return INT_MIN;
}

int peek(struct Queue* queue) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == 0) printf("Queue is empty\n");
    else return *(queue->data);
    return INT_MIN;
}

int isEmpty(struct Queue* queue) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == 0) return 1;
    return 0; 
}

int isFull(struct Queue* queue) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == queue->size) return 1;
    return 0; 
}

int getSize(struct Queue* queue) {
    if (queue != NULL) return queue->numOfElements;
    printf("Queue is NULL\n");
    return INT_MIN;
}

void printQueue(struct Queue* queue) {
    if (queue == NULL) printf("Queue is NULL\n");
    else if (queue->numOfElements == 0) printf("Queue is empty\n");
    else {
        for (int i = queue->numOfElements - 1; i > 0; i--) {
            printf("%d - ", *(queue->data + i));
        }
        printf("%d\n", *(queue->data));
    }
}