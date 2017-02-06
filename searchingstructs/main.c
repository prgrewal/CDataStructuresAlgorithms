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

	person* Person[numNames];
	for (i =0; i<numNames; i++) { 
		Person[i] = malloc(sizeof(person));
		Person[i]->name = malloc(25 * sizeof(char));
		Person[i]->phone = malloc(sizeof(int));
		memset(Person[i]->phone, 0, sizeof(int));
	}

  int* findPhone = malloc(sizeof(int));
  char* findName = malloc(25 * sizeof(char));
  
  printf("Input names\n");
  for (i = 0; i< numNames; i++) { 
    scanf("%24s", Person[i]->name);
  }

  printf ("Input phone numbers for each name\n");
  for (i=0; i<numNames; i++) {
    printf("%s: ", Person[i]->name);
    scanf("%d", Person[i]->phone);
  }

  for (i =0; i<numNames; i++) { 
  	printf("%s: %d\n", Person[i]->name, *Person[i]->phone);
  }

  insertionSortAlpha(Person ,0, (numNames-1));
  printf("Search by name: ");
  scanf("%24s", findName);
  int namePosition = binarySearchAlpha(0, numNames, findName, Person);
  printf("Name: %s, Phone: %d\n", Person[namePosition]->name, *Person[namePosition]->phone);

  insertionSortNum(Person , 0, (numNames-1));
  printf("Search by phone number: ");
  scanf("%d", findPhone);
  int phonePosition = binarySearchNum(0, numNames, findPhone, Person);
  printf("Name: %s, Phone: %d\n", Person[namePosition]->name, *Person[namePosition]->phone);

  for (i =0; i<numNames; i++) { 
    free(Person[i]->name);
    free(Person[i]->phone);
    free(Person[i]);
  }
  free(findName);
  free(findPhone);
 return 0; 
}
