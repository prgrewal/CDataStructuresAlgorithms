#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("This program requires 1 argument -> Maximum Numbers\n");
    return 1;
  }
  int MaxNumbers = getMaxNumbers(argv[1]);
  int num[MaxNumbers];
  printf("Type up to %d numbers followed by 0\n", MaxNumbers);
  int n =0;
  int v;
  scanf("%d",&v);

  while (v != 0 && n<MaxNumbers) { 
    num[n++] = v;
    scanf("%d",&v);
  }
  if (v!=0) {
    printf("More than %d numbers entered\n", MaxNumbers);
    printf("First %d used\n", MaxNumbers);
  }
  //n numbers are stored from num[0] to num[n-1]
  insertionSort(num,0, n-1);
  printf("\nThe sorted numbers are\n");
  int h;
  for (h=0; h<n; h++) {
    printf("%d ", num[h]);
  }
  printf("\n");
  printf("Total comparisons: %d\n",comparisons);
  printf("Total assignments: %d\n",assignments);
}
