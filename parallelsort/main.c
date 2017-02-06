#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char** argv) {
  FILE* fp;

  fp = fopen("votes.txt","r");

  char** nameArray =  malloc(10 * sizeof(char *)); //Allocate row pointers

  int i;
  for(i =0; i< 10; i++) { 
    nameArray[i] = malloc(25 * sizeof(char)); //Allocate each row separately
  }
  for(i=0;i<10;i++) {
    fgets(nameArray[i], 25, (FILE*)fp);
    int len = strcspn(nameArray[i], "\r\n");
    nameArray[i][len] = 0; 
  }

  for (i=0; i<10; i++) { 
    printf("Candidate [%d] = %s\n",(i+1),nameArray[i]);
  }

  int* votesArray = malloc(10 * sizeof(int)); 
  
  printf("Submit your vote for candidates 1 through 10 with the appropiate number\t" 
      "followed by enter, type 0 to terminate. All other numbers will be a spoiled vote.\n");
  
  int v;
  scanf("%d",&v);
  while (v != 0) {
    switch (v) { 
      case 1 : 
        votesArray[0]++;
        break;
      case 2 : 
        votesArray[1]++;
        break;
      case 3 : 
        votesArray[2]++;
        break;
      case 4 : 
        votesArray[3]++;
        break;
      case 5 : 
        votesArray[4]++;
        break;
      case 6 : 
        votesArray[5]++;
        break;
      case 7 : 
        votesArray[6]++;
        break;
      case 8 : 
        votesArray[7]++;
        break;
      case 9 : 
        votesArray[8]++;
        break;
      case 10 : 
        votesArray[9]++;
        break;
      default :
        printf("Spoiled vote\n");
        break;
      
    }
    scanf("%d",&v);
  }
  
  printf("Unsorted list\n");
  for (i=0; i<10; i++) { 
    printf("Candidate [%d], %s =  %d votes \n", (i+1), nameArray[i], votesArray[i]);
  }


  parallelSortAlpha(0, 9, nameArray, votesArray); 
  fp = fopen("results.txt", "w+");
  fprintf(fp, "Sorted Alphabetically\n");
  for (i =0; i<10; i++) {
    fprintf(fp, "%s = %d votes \n", nameArray[i], votesArray[i]);
  }

  printf("\n\n");
  printf("Sorted Alphabetically\n");
  for (i=0; i<10;i++) {
    printf("%s =  %d votes \n", nameArray[i], votesArray[i]);}
  
  parallelSortNum(0, 9, nameArray, votesArray);  
  fprintf(fp, "\n\nSorted Numerically\n");
  for (i =0; i<10; i++) {
    fprintf(fp, "%s = %d votes \n", nameArray[i], votesArray[i]);
  }
  printf("\n\n");
  printf("Sorted Numerically\n");
  for (i=0; i<10;i++) {
    printf("%s =  %d votes \n", nameArray[i], votesArray[i]);}
 
  for (i =0; i<10; i++) { 
    free(nameArray[i]);
  }
  free(nameArray);
  free(votesArray);

  close(fp);

  return 0;
}
