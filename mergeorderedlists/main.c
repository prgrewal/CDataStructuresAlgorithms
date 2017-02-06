#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "functions.h"

int main (int argc, char** argv) { 
  
  FILE* fp;
  fp = fopen("integerArray.txt","r"); 
  
  int numLines = countLines(fp);
  rewind(fp);

  char** charIntArray = malloc(numLines * sizeof(char*));

  int i;
  for (i = 0; i < numLines; i++) { 
    charIntArray[i] = malloc(10 * sizeof(char));
  }
  
  for(i = 0; i < numLines; i++) { 
    fgets(charIntArray[i], 5, (FILE*)fp);
    int len = strcspn(charIntArray[i], "\r\n");
    charIntArray[i][len] = '\0';
  }

  int* numArray = malloc(numLines * sizeof(int));
  for (i = 0; i < numLines; i++) { 
    numArray[i] = convertChartoNum(charIntArray[i]);
  }

  int* maxArrayNum = malloc(sizeof(int));
  *maxArrayNum = findMaximum(numArray,0,(numLines-1));
  int maxPosition = binarySearchNum(0, (numLines-1), maxArrayNum, numArray);

  int* firstHalf = malloc(maxPosition * sizeof(int));
  int* secondHalf = malloc((numLines - maxPosition) * sizeof(int));

  memcpy(firstHalf, numArray, maxPosition * sizeof(int));
  memcpy(secondHalf, numArray+maxPosition,((numLines -  maxPosition) * sizeof(int)));
  
  insertionSort(firstHalf, 0, maxPosition-1);
  insertionSort(secondHalf, 0, (numLines - maxPosition)-1);  
  
  int* mergeArray = malloc(numLines * sizeof(int));
  merge(firstHalf, maxPosition, secondHalf, (numLines - maxPosition), mergeArray);

  for (i = 0; i<numLines; i++) { 
    printf("Array index %d: %d\n", i, mergeArray[i]);
  }

  for (i = 0; i<numLines; i++) { 
    free(charIntArray[i]);
  }
  free(charIntArray);
  free(numArray);
  free(maxArrayNum);
  free(firstHalf);
  free(secondHalf);
  free(mergeArray);
  fclose(fp);
  return 0;
}
