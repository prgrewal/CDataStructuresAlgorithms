#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "functions.h"

int main (int argc, char** argv) {
  
  if (argc < 2) {
    printf("This program requires 1 argument -> Maximum Names\n");
    return 1;
  }

  int i;
  int numNames = getMaxNames(argv[1]);
  int* findPhone = malloc(sizeof(int));
  int* phoneArray = malloc(numNames * sizeof(int));
  char* findName = malloc(25 * sizeof(char));
  char** nameArray =  malloc(numNames * sizeof(char *)); //Allocate row pointers
  for(i =0; i< numNames; i++) { 
    nameArray[i] = malloc(25 * sizeof(char)); //Allocate each row separately
  }
  
  printf("Input names\n");
  for (i = 0; i< numNames; i++) { 
    scanf("%24s", nameArray[i]);
  }

  printf ("Input phone numbers for each name\n");
  for (i=0; i<numNames; i++) {
    printf("%s: ", nameArray[i]);
    scanf("%d", &phoneArray[i]);
  }

  parallelSortAlpha(0, (numNames-1), nameArray, phoneArray);
  printf("Search by name: ");
  scanf("%24s", findName);
  int namePosition = binarySearchAlpha(0, (numNames-1), findName, nameArray);
  printf("Name: %s, Phone: %d\n", nameArray[namePosition], phoneArray[namePosition]);


  parallelSortNum(0, (numNames-1), nameArray, phoneArray);
  printf("Search by phone number: ");
  scanf("%d", findPhone);
  int phonePosition = binarySearchNum(0, (numNames - 1), findPhone, phoneArray);
  printf("Name: %s, Phone: %d\n", nameArray[phonePosition], phoneArray[phonePosition]);

  for (i =0; i<numNames; i++) { 
    free(nameArray[i]);
  }
  free(nameArray);
  free(phoneArray);
  free(findName);
  free(findPhone);
 return 0; 
}
