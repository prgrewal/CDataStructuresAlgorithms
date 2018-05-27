#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct nodePtrs nodePtrs;

struct node {
    node* next;
    node* prev;
    int data;
};



node* deleteByPos(node* list, node** last, int position) {
    int c = 0;
    node* temp;
    node* prev;
    
    temp=list;
    if (temp==NULL) {
        printf("No nodes available to delete\n\n");
        return list;
    } else {
        while(temp!=NULL && c != position) {
            prev=temp;
            temp=temp->next;
            c++;
        }
        if (temp==NULL) {
            printf("Reached end of list, position not available\n\n");
            return list;
        } else if (temp->next == NULL) {
            prev->next=temp->next;
            *last = prev;
            free(temp);
            return list;
        } else {
            prev->next=temp->next;
            temp->next->prev = prev;
            free(temp);
            return list;
        }
    }
}

node* makeNode(int n) {
    node* np = malloc(sizeof (node));
    np->data = n;
    np->prev = NULL;
    np->next = NULL;
    return np;
}

void printList(node* np) {
    while (np != NULL) {
        printf("%d\n", np->data);
        np = np->next;
    }
}

void printListReverse(node* np) {
    while (np != NULL) {
        printf("%d\n", np->data);
        np = np->prev;
    }
}

void insertionSort(node** list) {
    node* i = *list;
    node* current;
    node* next;
    while(i) {
        next = i;
        current = next->next;
        while(current && current->data < next->data) {
            /* Swap. */
            int temp = current->data;
            current->data = next->data;
            next->data = temp;
            /* increment. */
            next = current;
            current = current->next;
        }
        i = i->prev;
    }
}
void freeLinkedList(node* top) {
    node* curr;
    while((curr=top)!=NULL) {//set curr to head, stop if list empty
        top = top->next; //advance head to next element
        free(curr); //free saved pointer
    }
}
#endif

