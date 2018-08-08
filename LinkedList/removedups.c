#include "HashTable.h"


int main(void)
{
    // initializing hashtable
    void *hashtable[100];
    for(int i = 0; i < 100; i++)
    {
        hashtable[i] = NULL;
    }
    // create a linked list from an array first for data
    int numbers[] = {1, 1, 2, 2, 3, 4, 5, 4, 2, 10, 9, 8, 1};
    int size = 13;
    struct Node* list = createListFromArray(numbers, size); 
    printList(list);
    // we need to hunt for duplicates
    struct Node* pointer = list;
    struct Node* prev = list;
    int firstRun = 1;
    while(1)
    {
       if(find(hashtable, pointer->data) == 1)
       {
            // delete that node
            if(pointer->next == NULL)
                prev->next = NULL;
            else
            {
                prev->next = pointer->next;
                pointer = prev; // this is important. So that if two consequent elements are duplicates such as 3, 4 -> NULL. This will make sure the pointer stays at 4 after removing 3. 
            }
       }
       else
       {
            insert(hashtable, pointer->data);
       }
       if(pointer->next != NULL)
       {
           if(firstRun == 1)
                firstRun = 0;
           else
               prev = pointer;
           pointer = pointer->next;
       }
       else
           break;
    }
    printList(list);
    return 0;
}
