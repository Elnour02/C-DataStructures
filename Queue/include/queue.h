#ifndef QUEUE_H_
#define QUEUE_H_

struct Queue {
    int* data;
    int size;
    int numOfElements;
};

void initQueue(struct Queue* queue, int size);

void enqueue(struct Queue* queue, int data);

int dequeue(struct Queue* queue);

int peek(struct Queue* queue);

int isEmpty(struct Queue* queue);

int isFull(struct Queue* queue);

int getSize(struct Queue* queue);

void printQueue(struct Queue* queue);

#endif