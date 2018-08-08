#include "LinkedList.h"

void printList(struct Node *head)
{
    while(1)
    {
        printf("%d -> ", head->data);
        if(head->next == NULL)
            break;
        else
            head = head->next;
    }
    printf("NULL\n");
}

struct Node* createListFromArray(int* array, int size)
{
    if (size > 0)
    {
        struct Node* head;       
        struct Node* tmp;       
        struct Node* prev;       
        head = (struct Node*) malloc(sizeof(struct Node));
        head->data = array[0];
        head->next = NULL;
        prev = head; 
        for(int i = 1; i < size; i++)
        {
            tmp  = (struct Node*) malloc(sizeof(struct Node));
            tmp->next = NULL; 
            tmp->data = array[i];
            prev->next = tmp;
            prev = tmp;
        }
        return head;
    }
}
