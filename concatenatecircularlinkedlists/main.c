#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() { 
  int n;
  int concatCount;
  node* top;
  circPtr* npc;
  circPtr* cp;

  npc = createCircList();
  cp = createCircList();

  printf("You entered:\n");

  printCircList(npc->top);
  printf("\n");
  printf("Node count: %d\n\n",npc->count);
  printCircList(cp->top);
  printf("\nNode count: %d\n\n",cp->count);

  top=concatCircLists(npc, cp);
  printf("Concatenated: \n");
  printCircList(top);


  concatCount = npc->count + cp->count;

  printf("\nTotal node count: %d\n", concatCount);
  freeCircList(top, cp, npc);

}
