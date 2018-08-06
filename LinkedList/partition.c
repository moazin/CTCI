#include "LinkedList.h"

int main(void)
{
    int array[10] = {1, 2, 10, 9, 6, 3, 4, 5, 1, 2}; 
    int size = 10;
    struct Node* head = createListFromArray(array, size);
    // first let's move a pointer till it finds the end;
    struct Node* end = head;
    while(1)
    {
        if(end->next != NULL)
            end = end->next;
        else
            break;
    }
    // by now end holds the pointer to the last node
    int pivot = 5;
    struct Node* current = head;
    struct Node* lastPlaceToReach = end;
    while(1)
    {
        if(current == lastPlaceToReach)
            break;
        if(current->data >= 5){
            // you create another node at the end
            struct Node* new = (struct Node*) malloc(sizeof(struct Node));
            new->data = current->data;
            new->next == NULL;
            end->next = new;
            end = new;
            // now we delete the current node
            // we copy the next node's data to current node
            current->data = current->next->data;
            // we delete the next node
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    printList(head);
    return 0;
}
