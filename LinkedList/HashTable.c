#include "HashTable.h"

int hash(int number)
{
    return number%100;
}

void insert(void **hashtable, int number)
{
    int hsh = hash(number);
    if(hashtable[hsh%100] == NULL)
    {
        struct Node* newList = (struct Node*) malloc(sizeof(struct Node));
        hashtable[hsh%100] = newList;
        newList->data = number;
        newList->next == NULL;
    }
    else
    {
        struct Node* pointer = hashtable[hsh%100];
        while(pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        pointer->next = newNode;
        newNode->data = number;
        newNode->next = NULL;
    }
}

void printHashtable(void** hashtable)
{
    for(int i = 0; i < 100; i++)
    {
        if(hashtable[i] != NULL)
        {
            printf("[%d] -> ", i);
            printList(hashtable[i]);
        }
    }
}

int find(void** hashtable, int number)
{
    int hsh = hash(number);
    if(hashtable[hsh%100] == NULL)
    {
        return 0;
    }
    else
    {
        struct Node* pointer = hashtable[hsh%100];
        while(1)
        {
            if(pointer->data == number)
                return 1;
            else if(pointer->next != NULL)
                pointer = pointer->next;
            else
                return 0;
        }
    }
}
