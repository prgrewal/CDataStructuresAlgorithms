#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef struct node {
  int num;
  struct node* next;
} node;

node* makeNode(int n) { 
  node* np = malloc(sizeof(node));

  np -> num = n;
  np -> next = NULL;
  return np;
}

void printList(node* np) { 
  while(np!=NULL) { 
    printf("%d\n", np->num);
    np = np->next;
  }
}

node* insert(node* list,int data, int position) {
  int c = 0;

  node* temp; 
  node* prev; 
  node* curr;

  curr = list;

  temp = malloc(sizeof(node));
  temp->num=data;

  if (curr==NULL || position == 0) { 
    curr=temp;
    curr->next=list;
    return curr;
  } else { 
    while (curr!=NULL && c != position) { 
      prev = curr;
      curr=curr->next;
      c++;
    }
    if (curr==NULL) { 
      prev->next=temp;
      return list;
    } else { 
      prev->next=temp;
      temp->next=curr;
      return list;
    }
  }
}

node* deleteByPos(node* list, int position) { 
  int c=0;
  node* temp;
  node* prev;
  
  temp=list;
  if (temp==NULL) { 
    printf("No nodes available to delete\n\n");
    return list;
  } else {
    while(temp!=NULL && c!=position) {
      prev=temp; 
      temp=temp->next;
      c++;
    }
    if (temp==NULL) { 
      printf("Reached end of list, position not available\n\n");
      return list;
    } else { 
      prev->next=temp->next;
      free(temp);
      return list;
    }
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
