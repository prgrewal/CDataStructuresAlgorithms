#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct { 
	char* name;
	int* phone;
} person;

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

void insertionSortAlpha(person* Person[], int lo, int hi) { 
	person* insertItem;

	int i;
	for(i=lo+1; i<=hi; i++) { 
		insertItem = Person[i];
		int k = i - 1;
		while (k > 0 && strcmp(insertItem->name, Person[k]->name) < 0) { 
			Person[k + 1] = Person[k];
			--k;
		}
		Person[k + 1] = insertItem;
	}
}

void insertionSortNum(person* Person[], int lo, int hi) { 
	person* insertItem;
	int i;
	for (i = lo + 1; i<=hi; i++) { 
		insertItem = Person[i];
		int k = i -1;
		while (k>=lo && *insertItem->phone > *Person[k]->phone) { 
			Person[k+1] = Person[k];
			--k;
		}
		Person[k+1] = insertItem;
	}
}
int binarySearchAlpha(int lo, int hi, char* key, person* Person[]) {
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int cmp = strcmp(key, Person[mid]->name);
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

int binarySearchNum(int lo, int hi, int* key, person* Person[]) { 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (key == Person[mid]->phone) { 
      return mid; //found
    } else if (key < Person[mid]->phone) { 
      hi = mid - 1; //value is less than mid, move mid down
    } else { 
      lo = mid + 1; //value is greater than mid, move mid up
    }
  }
  return 1;
}
#endif
