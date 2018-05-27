#include "functions.h"

int main() {
    int n;
    node* np;
    node* top;
    node* last;
    printf("Enter integers to add to list\n");
    do {
        if (scanf("%d", &n) != 1) {
            n = 0;
        }
        if (n != 0) {
            np = makeNode(n);
            if (top == NULL) {
                top = np;
            } else {
                last->next = np;
                np->prev = last;
            }
            last = np;
        }
    } while (n != 0);
    printf("\n\n");
    printf("You entered:\n");
    printList(top);
    printf("\n\n");
    printf("In reverse:\n");
    printListReverse(last);
    printf("\n\n");
    printf("Enter a position to delete:");
    scanf("%d", &n);
    
    top = deleteByPos(top, &last, n);
    printf("\n\n");
    printf("In reverse after delete:\n");
    printListReverse(last);
    
    insertionSort(&last);
    
    printf("From top after sort:\n");
    printList(top);
    printf("In reverse after Sort:\n");
    printListReverse(last);
    
    freeLinkedList(top);
    return 0;
    
}
