#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int main(int argc, char** argv) {
  FILE* fp;

  fp = fopen("votes.txt","r");

  candidate* Person[10]; 
  int i;
  for (i = 0; i<10; i++) { 
  	Person[i] = malloc(sizeof(candidate));
  	Person[i]->name = malloc(25*sizeof(char));
	Person[i]->numVotes=malloc(sizeof(int));
	memset(Person[i]->numVotes , 0, sizeof(int));

    fgets(Person[i]->name, 25, (FILE*)fp);
    int len = strcspn(Person[i]->name, "\r\n");
    Person[i]->name[len] = '\0'; 

    printf("Candidate [%d] = %s\n",(i+1),Person[i]->name);
  }

  
  printf("Submit your vote for candidates 1 through 10 with the appropiate number\t" 
      "followed by enter, type 0 to terminate. All other numbers will be a spoiled vote.\n");
  
  int v;
  while(1) {
	scanf("%d",&v);
	if (v==0) break;
	v--;
	if ( (v>=0) && (v < 10)) {
		(*Person[v]->numVotes)++;
	} else {
	    printf("spoiled vote\n");
	}
  }
  printf("Unsorted list\n");
  for (i=0; i<10; i++) { 
    printf("Candidate [%d], %s =  %d votes \n", (i+1), Person[i]->name, *Person[i]->numVotes);
  }

  insertionSortAlpha(Person, 0, 9);
  printf("\n\n");
  printf("Sorted Alphabetically\n");
  fp = fopen("results.txt", "w+");
  fprintf(fp, "Sorted Alphabetically\n");
  for (i=0; i<10;i++) {
    printf("%s =  %d votes \n", Person[i]->name, *Person[i]->numVotes);
    fprintf(fp, "%s = %d votes \n", Person[i]->name, *Person[i]->numVotes);
  }

  insertionSortNum(Person, 0 , 9);
  printf("\n\n");
  printf("Sorted Numerically\n");
  fprintf(fp, "\n\nSorted Numerically\n");
  for (i=0; i<10;i++) {
    printf("%s =  %d votes \n", Person[i]->name, *Person[i]->numVotes);
    fprintf(fp, "%s = %d votes \n", Person[i]->name, *Person[i]->numVotes);
  }

  for (i =0; i<10; i++) { 
    free(Person[i]->numVotes);
    free(Person[i]->name);
	free(Person[i]);
  }

  close(fp);

  return 0;
}
