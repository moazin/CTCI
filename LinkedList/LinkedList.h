#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int data;
};

struct Node* createListFromArray(int* array, int size);
void printList(struct Node *head);
