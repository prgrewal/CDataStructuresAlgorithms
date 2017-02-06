#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int findMaximum(int* arr, int lo, int hi) { 
  int max = arr[lo];
  
  int i;
  for (i = lo; i <= hi; i++) { 
    if (arr[i] > max) { 
      max = arr[i];
    }
  }
  return max;
}

int binarySearchNum(int lo, int hi, int* key, int* arr) { 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (*key == arr[mid]) { 
      return mid; //found
    } else if (*key < arr[mid]) { 
      hi = mid - 1; //value is less than mid, move mid down
    } else { 
      lo = mid + 1; //value is greater than mid, move mid up
    }
  }
  return 1;
}

int convertChartoNum(const char* numbersChar) {
  int numberInt;
  
  char* p;
  
  int errno = 0;
  
  long conv = strtol(numbersChar, &p, 10);

  if (errno != 0 || *p != '\0' || conv > INT_MAX) {
    printf("Invalid number\n");
    return 1;
  } else {
    numberInt = conv;
  }

  return numberInt;

}

int countLines(FILE* filename) { 
  int ch = 0;
  int lines = 0;

  if (filename == NULL) { 
    return 0;
  }
  
  while(!feof(filename)) { 
    ch = fgetc(filename);
    if(ch == '\n') { 
      lines++;
    }
  }
  return lines;
}

int merge(int* a, int m, int* b, int n, int* c) {
    int i = 0;  //i points to the first (smallest) number in a
    int j = 0;  //j points to the first (smallest) number in b
    int k = -1; //k will be incremented before storing a number in c[k]
    while (i < m || j < n) {
      if (i == m) { 
        c[++k] = b[j++];
      } else if (j == n) { 
        c[++k] = a[i++];
      } else if (a[i] < b[j]) { 
        c[++k] = a[i++];
      } else { 
        c[++k] = b[j++];
      }
    }
    return m + n; 
}


void insertInPlace(int newItem, int* list, int m, int n) { 
//list[m] to list[n] are sorted
//insert newItem so that list[m] to list[n+1] are sorted
  int k = n;
  while (k >= m && newItem <list[k]) {
    list[k+1] = list[k];
    --k;
  }
  list[k+1] = newItem;
}

void insertionSort(int* list, int lo, int hi) { 
//sort list[0] to list[n-1] in ascending order
  int h;
  for (h=lo+1; h<=hi; h++) {
    insertInPlace(list[h], list, lo, h-1);
  } 
}
#endif
