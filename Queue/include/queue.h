#ifndef QUEUE_H_
# define QUEUE_H_

struct Queue {
    int *data;
    int numOfElements;
};

void initQueue(struct Queue *queue);

void enqueue(struct Queue *queue);

int dequeue(struct Queue *queue);

int peek(struct Queue *queue);

int isEmpty(struct Queue *queue);

int isFull(struct Queue *queue);

int getSize(struct Queue *queue);

void printQueue(struct Queue *queue);

#endif