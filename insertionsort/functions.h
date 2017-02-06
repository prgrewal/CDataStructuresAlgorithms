#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int comparisons;
int assignments;

int getMaxNumbers(const char* maxNumbersChar) {
  int maxNumber;
  
  char* p;
  
  int errno = 0;
  
  long conv = strtol(maxNumbersChar, &p, 10);

  if (errno != 0 || *p != '\0' || conv > INT_MAX) {
    printf("Invalid number\n");
    return 1;
  } else {
    maxNumber = conv;
  }

  return maxNumber;

}

void insertInPlace(int newItem, int list[], int m, int n) { 
//list[m] to list[n] are sorted
//insert newItem so that list[m] to list[n+1] are sorted
  int k = n;
  while (k >= m && newItem <list[k]) {
    comparisons++;
    assignments++;
    list[k+1] = list[k];
    --k;
  }
  list[k+1] = newItem;
}

void insertionSort(int list[], int lo, int hi) { 
//sort list[0] to list[n-1] in ascending order
  int h;
  for (h=lo+1; h<=hi; h++) {
    insertInPlace(list[h], list, lo, h-1);
  } 
}
#endif
