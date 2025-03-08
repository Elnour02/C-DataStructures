#ifndef STACK_H_
#define STACK_H_

struct Stack {
    int* data;
    int size;
    int numOfElements;
};

void initStack(struct Stack* stack, int size);

void push(struct Stack* stack, int data);

int pop(struct Stack* stack);

int peek(struct Stack* stack);

int isEmpty(struct Stack* stack);

int isFull(struct Stack* stack);

int getSize(struct Stack* stack);

void printStack(struct Stack* stack);

#endif