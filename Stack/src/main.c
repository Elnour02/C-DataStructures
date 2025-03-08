#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main() {
    struct Stack stack;
    int size;
    printf("Size of stack: ");
    scanf("%d", &size);
    initStack(&stack, size);
    stack.data = (int*) malloc(size * sizeof(int));
    int choice;
    int value;
    printf("\n");
    do {
        printf("quit 0\npush 1\npop 2\npeek 3\nisEmpty 4\nisFull 5\ngetSize 6\n\nchoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n");
                printf("Value: ");
                scanf("%d", &value);
                push(&stack, value);
                printf("\n");
                printStack(&stack);
                break;
            case 2:
                printf("\n");
                value = pop(&stack);
                if (value != INT_MIN) printf("Removed %d\n\n", value);
                printStack(&stack);
                break;
            case 3:
                printf("\n");
                value = peek(&stack);
                if (value != INT_MIN) printf("Next to be removed is %d\n", value);
                break;
            case 4:
                printf("\n");
                value = isEmpty(&stack);
                if (value) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;
            case 5:
                printf("\n");
                value = isFull(&stack);
                if (value) printf("Stack is full\n");
                else printf("Stack is not full\n");
                break;
            case 6:
                printf("\n");
                value = getSize(&stack);
                if (value != INT_MIN) printf("Stack has %d elements\n", value);
                break;
            default:
                choice = 0;
        }
        printf("\n");
    } while (choice != 0);
    free(stack.data);
    return 0;
}