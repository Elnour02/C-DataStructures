#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

void initStack(struct Stack* stack, int size) {
    if (stack != NULL) {
        stack->size = size;
        stack->numOfElements = 0;
    }
    else printf("Stack is NULL\n");
}

void push(struct Stack* stack, int data) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == stack->size) printf("Stack is full\n");
    else {
        *(stack->data + stack->numOfElements) = data;
        stack->numOfElements++;
    }
}

int pop(struct Stack* stack) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == 0) printf("Stack is empty\n");
    else {
        int value = *(stack->data + (stack->numOfElements - 1));
        stack->numOfElements--;
        return value;
    }
    return INT_MIN;
}

int peek(struct Stack* stack) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == 0) printf("Stack is empty\n");
    else return *(stack->data + (stack->numOfElements- 1));
    return INT_MIN;
}

int isEmpty(struct Stack* stack) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == 0) return 1;
    return 0; 
}

int isFull(struct Stack* stack) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == stack->size) return 1;
    return 0; 
}

int getSize(struct Stack* stack) {
    if (stack != NULL) return stack->numOfElements;
    printf("Stack is NULL\n");
    return INT_MIN;
}

void printStack(struct Stack* stack) {
    if (stack == NULL) printf("Stack is NULL\n");
    else if (stack->numOfElements == 0) printf("Stack is empty\n");
    else {
        for (int i = 0; i < stack->numOfElements - 1; i++) {
            printf("%d - ", *(stack->data + i));
        }
        printf("%d\n", *(stack->data + stack->numOfElements - 1));
    }
}