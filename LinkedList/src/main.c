#include <stdio.h>
#include "../include/linkedList.h"

int main() {
    struct List list = initList();
    addFirst(&list, 5);
    addLast(&list, 7);
    printList(&list);
    freeList(&list);
    return 0;
}