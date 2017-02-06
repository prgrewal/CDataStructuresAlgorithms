#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
	char* name;
	int* numVotes;
} candidate;

void insertionSortAlpha(candidate* person[], int lo, int hi) { 
	candidate* insertItem;

	int i;
	for(i=lo+1; i<=hi; i++) { 
		insertItem = person[i];
		int k = i - 1;
		while (k > 0 && strcmp(insertItem->name, person[k]->name) < 0) { 
			person[k + 1] = person[k];
			--k;
		}
		person[k + 1] = insertItem;
	}
}

void insertionSortNum(candidate* person[], int lo, int hi) { 
	candidate* insertItem;
	int i;
	for (i = lo + 1; i<=hi; i++) { 
		insertItem = person[i];
		int k = i -1;
		while (k>=lo && *insertItem->numVotes > *person[k]->numVotes) { 
			person[k+1] = person[k];
			--k;
		}
		person[k+1] = insertItem;
	}
}
#endif
