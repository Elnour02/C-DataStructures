#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct Node {
    struct Node *next;
    int data;
};

struct List {
    struct Node *first;
    int numOfNodes;
};

struct List initList();

void addFirst(struct List *list, int data);

void addLast(struct List *list, int data);

void removeFirst(struct List *list);

void removeLast(struct List *list);

int getFirst(struct List *list);

int getLast(struct List *list);

int contains(struct List *list, int value);

void sortList(struct List *list);

void printList(struct List* list);

void freeList(struct List *list);

#endif 