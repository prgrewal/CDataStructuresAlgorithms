#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef enum {false,true } bool;

typedef struct node {
  int num;
  struct node* next;
} node;

node* makeNode(int n) {
  node* np =  malloc(sizeof (node));
  np -> num = n;
  np -> next = NULL;
  return np;
}

void printList(node* np) {
  while (np != NULL) {  // as long as there's a node
    printf("%d\n", np -> num);
    np = np -> next;  // go on to the next node
  }
}

bool isSorted(node* top) { 
  int num;
  if (!top) return true; //empty list

  num = top->num; //save value of current node

  top = top->next;

  while(top!=NULL) { 
    if (num > top->num) { 
      return false; //not sorted
    }
    num = top->num; //save value of current node
    top=top->next;
  }

  return true; //sorted
}

void freeLinkedList(node* top) { 
  node* curr;
  while((curr=top)!=NULL) {//set curr to head, stop if list empty 
    top = top->next; //advance head to next element
    free(curr); //free saved pointer
  }
}
void swap(node* nodeOne, node* nodeTwo) { 
  int temp=nodeOne->num;
  nodeOne->num=nodeTwo->num;
  nodeTwo->num=temp;
}

void selectionSort(node* top) { 
  node* start=top;
  node* np;
  node* min;

  while(start->next) { 
    min=start;
    np=start->next;

    while(np) { 
      /*Find minimum element from array */
      if (min->num > np->num) {
        min=np;
      }
      np=np->next;
    }
    swap(start,min); //Put minimum element on starting location
    start = start->next;  
  } 
}
#endif
