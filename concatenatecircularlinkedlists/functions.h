#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct node { 
  int num;
  struct node* next;
} node;


typedef struct { 
  node* top;
  node* last;
  int count;
} circPtr;

node* makeNode(int n) { 
  node* np = malloc(sizeof(node));

  np->num=n;
  np->next =NULL;

  return np;
}

void printList(node* np) { 
  while (np!=NULL) { 
    printf("%d\n", np->num);
    np=np->next;
  } 
}


void printCircList(node* list) { 
  node* curr=list;
  if (curr != NULL) { 
    do { 
      printf("%d\n",curr->num);
      curr=curr->next;
    } while (curr!=list);
  }
}

circPtr* createCircList() {  
  int n;
  int count=0;
  node* np;
  circPtr* npc = malloc(sizeof(npc));

  npc->top=NULL;

  printf("Initialize list with integers\n");
  if (scanf("%d", &n) != 1) { 
    n =0;
  }
  while(n!=0) { 
    np = makeNode(n); //create new node containing n
    if (npc->top == NULL) { 
      npc->top = np; //set top if first node
      count++;
    } else { 
      npc->last->next=np; //set last->next for other nodes
      count++;
    }
    npc->last = np;
    if (scanf("%d", &n) !=1) { 
      n=0;
    }
  }
  npc->last->next=npc->top;
  npc->count=count;
  return npc;
}

node* concatCircLists(circPtr* cp, circPtr* npc) { 
  cp->last->next = npc->top;
  npc->last->next = cp->top;
  return cp->top;
}

void freeCircList(node* top, circPtr* cp, circPtr* npc)  { 
  node* curr = top;
  node* next;
  if (curr != NULL) {
    do {
      next = curr->next;
      free(curr);
      curr = next;
    } while (curr!=top);
    free(npc);
    free(cp);
  }
}
#endif
