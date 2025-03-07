#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"

int main() {
    struct List list;
    initList(&list);
    int choice;
    int value;
    int first;
    int last;
    int contain;
    do {
        printf("quit 0\naddFirst 1\naddLast 2\nremoveFirst 3\nremoveLast 4\ngetFirst 5\ngetLast 6\ncontains 7\nsortList 8\n\nchoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                printf("\n");
                addFirst(&list, value);
                printList(&list);
                break;
            case 2:
                printf("Value: ");
                scanf("%d", &value);
                printf("\n");
                addLast(&list, value);
                printList(&list);
                break;
            case 3:
                printf("\n");
                removeFirst(&list);
                printList(&list);
                break;
            case 4:
                printf("\n");
                removeLast(&list);
                printList(&list);
                break;
            case 5:
                printf("\n");
                first = getFirst(&list);
                if (first != INT_MIN) printf("First value is %d\n", first);
                else printf("List is empty\n");
                break;
            case 6:
                printf("\n");
                last = getLast(&list);
                if (last != INT_MIN) printf("Last value is %d\n", last);
                else printf("List is empty\n");
                break;
            case 7:
                printf("\n");
                printf("Value: ");
                scanf("%d", &value);
                contain = contains(&list, value);
                if (contain) printf("The list contains %d", value);
                else printf("The list does not contain %d\n", value);
                break;
            case 8:
                printf("\n");
                sortList(&list);
                printList(&list);
                break;
            default:
                choice = 0;
        }
        printf("\n");
    } while (choice != 0);
    freeList(&list);
    return 0;
}