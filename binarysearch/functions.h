#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int getMaxNames(const char* maxNumbersChar) {
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

void parallelSortAlpha(int lo, int hi, char** names, int* phone) {
  int i;
  char name[25];
  for (i = lo + 1; i <= hi; i++) {
    strcpy(name, names[i]);
    int m = phone[i]; //extract the phone number
    int k = i - 1; //start comparing with previous item
    while (k >= 0 && strcmp(name, names[k]) < 0) { 
      strcpy(names[k+1], names[k]);
      phone[k+1] = phone[k]; //move up phone number when we move a name
      --k;
    }
    strcpy(names[k+1],name); //store the phone number in the same position as the name
    phone[k+1]=m;
  }
}

void parallelSortNum(int lo, int hi, char** names, int* phone) {
  char name[25];
  int i;
  for (i=lo + 1; i<=hi; i++) {
    int phoneNumber = phone[i];
    strcpy(name, names[i]); //extract the name
    int k = i -1; //start comparing with previous item
    while (k >= 0 && phoneNumber < phone[k]) { 
      phone[k+1] = phone[k];
      strcpy(names[k+1], names[k]);//move up the name when we move a phone number
      --k;
    }
    phone[k+1] = phoneNumber;
    strcpy(names[k+1], name); //store the name in the same position as the phone number
  }
}

int binarySearchAlpha(int lo, int hi, char* key, char** names) {
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int cmp = strcmp(key, names[mid]);
    if (cmp == 0) { 
      return mid; //found
    } else if (cmp < 0) { 
      hi = mid - 1; //value is less than mid, move mid down
    } else { 
      lo = mid + 1; //value is greater than mid, move mid up
    }
  }
  return 1;
}

int binarySearchNum(int lo, int hi, int* key, int* phone) { 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (*key == phone[mid]) { 
      return mid; //found
    } else if (*key < phone[mid]) { 
      hi = mid - 1; //value is less than mid, move mid down
    } else { 
      lo = mid + 1; //value is greater than mid, move mid up
    }
  }
  return 1;
}
#endif
