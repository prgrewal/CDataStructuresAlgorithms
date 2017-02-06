#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main () {
  int n;
  node* top;
  node* np;

  top = NULL;
  printf("Enter integers for linked list followed by 0:\n");
  if (scanf("%d",&n) !=1) { 
    n = 0;
  }
  while (n!=0) { 
    np = makeNode(n); //create a new node containing n
    np -> next = top; //set link of new node to first node
    top = np; //set top to point to new node
    if (scanf("%d",&n) != 1) { 
      n = 0;
    }
  }
  printf("\n\nLinked list:\n");
  printList(top);

  printf("\n\nEnter data then position to add:\n");
  int data;
  int position;
  scanf("%d", &data);
  scanf("%d", &position);
  printf("\n\nNew Linked List:\n");
  top=insert(top, data, position); 
  printList(top);
  printf("\n\nEnter position of data to be deleted:\n");
  scanf("%d",&position);
  top=deleteByPos(top, position);
  printf("\n\nNew Linked List:\n");
  printList(top);
  freeLinkedList(top);
}
