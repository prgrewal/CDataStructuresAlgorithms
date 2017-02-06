#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void parallelSortAlpha(int lo, int hi, char** names, int* votes) {
  int i;
  char name[25];
  for (i = lo + 1; i <= hi; i++) {
    strcpy(name, names[i]);
    int m = votes[i]; //extract the vote
    int k = i - 1; //start comparing with previous item
    while (k >= 0 && strcmp(name, names[k]) < 0) { 
      strcpy(names[k+1], names[k]);
      votes[k+1] = votes[k]; //move up vote when we move a name
      --k;
    }
    strcpy(names[k+1],name); //store the vote in the same position as the name
    votes[k+1]=m;
  }
}

void parallelSortNum(int lo, int hi, char** names, int* votes) {
  char name[25];
  int i;
  for (i=lo + 1; i<=hi; i++) {
    int vote = votes[i];
    strcpy(name, names[i]); //extract the name
    int k = i -1; //start comparing with previous item
    while (k >= 0 && vote < votes[k]) { 
      votes[k+1] = votes[k];
      strcpy(names[k+1], names[k]);//move up the name when we move a vote
      --k;
    }
    votes[k+1] = vote;
    strcpy(names[k+1], name); //store the name in the same position as the vote
  }
}

#endif
