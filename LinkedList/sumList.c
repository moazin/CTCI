#include "LinkedList.h"

int main(void)
{
    int list1[] = {1, 2, 3, 4, 5, 6};
    int list2[3] = {1, 2, 3};
    struct Node* List1 = createListFromArray(list1, 6);
    struct Node* List2 = createListFromArray(list2, 3);
    struct Node* sum = (struct Node*) malloc(sizeof(struct Node));
    struct Node* head = sum;
    sum->next = NULL;
    int carry = 0;
    int flag = 0;
    while(1)
    {
       sum->data = List1->data + List2->data + carry;
       carry = 0;
       if(sum->data > 9)
       {
            carry = sum->data / 10;
            sum->data = sum->data % 10; 
       }
       if(List1->next == NULL)
           List1->data = 0;
       else
           List1 = List1->next;
       if(List2->next == NULL)
           List2->data = 0;
       else
           List2 = List2->next;
       if((List1->next == NULL) && (List2->next == NULL)){
           if(flag == 0)
                flag = 1;
           else
               break;
           if(carry != 0)
           {
                sum->data = carry;
           }
           
       }
       sum->next = (struct Node*) malloc(sizeof(struct Node));
       sum = sum->next;
    }
    printList(head);
    return 0;
}
