#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"

struct List initList() {
    struct List list;
    list.first = NULL;
    list.numOfNodes = 0;
    return list;
}

void addFirst(struct List *list, int data) {
    if (list != NULL) {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->next = list->first;
            list->first = newNode;
            list->numOfNodes++;
        }
        else printf("Memory allocation failed\n");
    }
    else printf("List uninitialized\n");
}

void addLast(struct List *list, int data) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) addFirst(list, data);
    else {
        struct Node *node = list->first;
        while (node->next != NULL) {
            node = node->next;
        }
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = data;
            node->next = newNode;
            newNode->next = NULL;
            list->numOfNodes++;
        }
        else printf("Memory allocation failed\n");
    }
}

void removeFirst(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else {
        struct Node *node = list->first;
        list->first = node->next;
        free(node);
        list->numOfNodes--;
    }
}

void removeLast(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else if (list->numOfNodes == 1) removeFirst(list);
    else {
        struct Node *node = list->first;
        while (node->next->next != NULL) {
            node = node->next;
        }
        struct Node *pNode = node;
        free(node->next);
        pNode->next = NULL;
        list->numOfNodes--;
    }
}

int getFirst(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else return list->first->data;
}

int getLast(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else {
        struct Node *node = list->first;
        while (node->next != NULL) {
            node = node->next;
        }
        return node->data;
    }
}

int contains(struct List *list, int value) {
    struct Node *node = list->first;
    while (node != NULL) {
        if (node->data == value) return 1;
        node = node->next;
    }
    return 0;
}

void sortList(struct List *list) {
    if (list == NULL) printf("List uninitialized\n");
    else if (list->first == NULL) printf("List empty\n");
    else {
        struct Node *node;
        int temp;
        for (int i = 0; i < list->numOfNodes-1; i++) {
            node = list->first;
            while (node->next != NULL) {
                if (node->data > node->next->data) {
                    temp = node->data;
                    node->data = node->next->data;
                    node->next->data = temp;
                }
                node = node->next;
            }
        }
    }
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