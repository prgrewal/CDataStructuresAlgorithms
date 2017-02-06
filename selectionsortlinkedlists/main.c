#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
  int n;
  node* top; 
  node* np; 
  node* last;
  top = NULL;
  printf("Enter integers to add to linked list\n");
  if (scanf("%d", &n) != 1) n = 0;
  while (n != 0) {
    np = makeNode(n);   //create a new node containing n
    if (top == NULL) top = np;   //set top if first node
    else last -> next = np;   //set last -> next for other nodes
    last = np;   //update last to  new node
    if (scanf("%d", &n) != 1) n = 0;
  }
  printf("You entered:\n");
  printList(top);
 
  printf("Checking if sorted:\n");
  bool sort = isSorted(top);
  if (sort==false) { 
    printf("Not sorted\n");
    printf("Sorting...\n");
    selectionSort(top);
  printList(top);
  } else { 
    printf("Sorted\n");
  }

 freeLinkedList(top); 

}
