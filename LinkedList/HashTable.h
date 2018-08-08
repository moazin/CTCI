#include "LinkedList.h"
#include <string.h>

int hash(int number);
void insert(void **hashtable, int number);
void printHashtable(void** hashtable);
int find(void** hashtable, int number);
