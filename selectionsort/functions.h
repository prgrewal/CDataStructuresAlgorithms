#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int assignments = 0;
int comparisons = 0;

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

int getSmallest(int list[], int lo, int hi) {
  //return location of smallest from list[lo..hi]
  int small = lo;
  int h;
  for (h=lo+1; h<=hi; h++) {
    comparisons++;
    if (list[h] < list[small]) {
      small = h;
    }
  }
  return small;
}

void swap(int list[], int i, int j) {
  //swap elements list[i] and list[j]
  assignments++;
  int hold = list[i];
  assignments++;
  list[i] = list[j];
  assignments++;
  list[j] = hold;
}

void selectionSort(int list[], int lo, int hi) {
  //sort list[lo] to list[hi] in ascending order
  int h;
  for (h=lo; h<hi; h++) {
    int s = getSmallest(list, h, hi);
    swap(list,h,s);
  }
}
#endif
