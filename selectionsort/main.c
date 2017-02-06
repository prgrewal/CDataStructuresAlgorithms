#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"


int main(int argc, char** argv) {
  if (argc < 2) {
    printf("This program requires 1 argument -> Maximum Numbers\n");
    return 1;
  }
  int maxNumbers = getMaxNumbers(argv[1]);

  int num[maxNumbers];
  printf("Type up to %d numbers followed by 0\n", maxNumbers);
  int n = 0;
  int v;
  scanf("%d", &v);
  while (v!=0 && n< maxNumbers) {
    num[n++]=v;
    scanf("%d",&v);
  }
  if (v != 0) {
    printf("More than %d numbers entered\n", maxNumbers);
    printf("First %d used\n", maxNumbers);
  }
  //n numbers are stored from num[0] to num[n-1]
  selectionSort(num, 0, n-1);
  printf("\nThe sorted numbers are\n");
  int h;
  for (h=0; h<n;h++) {
    printf("%d ",num[h]);
    printf("\n");
  }
  printf("Assignments made: %d\n", assignments);
  printf("Comparisons made: %d\n", comparisons);
}
