#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"

struct List initList() {
    struct List list;
    list.first = NULL;
    return list;
}

void addFirst(struct List *list, int data) {
    if (list != NULL) {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->next = list->first;
            list->first = newNode;
        }
        else printf("Memory allocation failed\n");
    }
    else printf("List uninitialized\n");
}

void addLast(struct List *list, int data) {
    if (list != NULL) {
        struct Node *node = list->first;
        while (node->next != NULL) {
            node = node->next;
        }
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = data;
            node->next = newNode;
            newNode->next = NULL;
        }
        else printf("Memory allocation failed\n");
    }
    else printf("List uninitialized\n");
}

void removeFirst(struct List *list) {

}

void removeLast(struct List *list) {

}

int getFirst(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else return list->first->data;
}

int getLast(struct List *list) {

}

int contains(struct List *list, int value) {

}

void sortList(struct List *list) {

}

void printList(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else {
        struct Node *node = list->first;
        while (node->next != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("%d\n", node->data);
    }    
}

void freeList(struct List *list) {
    if (list != NULL) {
        struct Node *pNode = list->first;
        struct Node *node;
        while (pNode != NULL) {
            node = pNode;
            pNode = node->next;
            free(node);
        }
        list->first = NULL;
    }
    else printf("List uninitialized\n");
}