#include <iostream>
#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < 100; i++)
    {
        table[i] = &lists[i];
    }
}

int HashTable::hash(char* string)
{
    int sum = 0;
    int counter = 0;
    while(string[counter] != '\0')
    {
        sum += (int) string[counter];
        counter += 1;
    }
    return sum;
}
void HashTable::add(char* key, char* value)
{
    int hashed_key = hash(key);
    int index = hashed_key % 100;
    cout << "Hashed index: " << index << endl;
    (*table[index]).add(key, value);
}

int main(void)
{
    HashTable hashTable;
    hashTable.add("name", "moazin");
    hashTable.add("bro", "zubair");
    hashTable.add("amen", "lolcollision");
    for(int i = 0; i < 100; i++)
    {
        cout << "Printing the " << i << "index's list" << endl;
        (*(hashTable.table[i])).print();
    }
    return 0;
}