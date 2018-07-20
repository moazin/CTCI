#include "LinkedList.h"

class HashTable
{
    public:
        LinkedList lists[100];
        LinkedList* table[100];
        int hash(char* string);
        HashTable();
        void add(char* key, char* value);
};