#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void printString(char* string)
{
    int counter = 0;
    while(string[counter] != '\0')
    {
        printf("%c", string[counter]);
        counter += 1;
    }
    printf("\n");
}

struct node {
    char* key;
    char* value;
    node* next_node;
};

class LinkedList
{
    public:
    node* start_node;
    LinkedList()
    {
        // cout << "Initializing Linked List" << endl;
        start_node = (node*) malloc(sizeof(node));
        // cout << "Memory address of first node allocation: " << start_node << endl;
        (*start_node).key = "end";
        (*start_node).value = "end";
    }
    void add(char* key, char* value)
    {
        // first find the end node
        // cout << "Starting the node addition process" << endl;
        node* target = start_node;
        // cout << "Target points to: " << target << endl;
        void* prev_node = &start_node;
        // cout << "Prev Node points to: " << prev_node << endl;
        while(strcmp((*target).key, "end") != 0)
        {
            prev_node = &((*target).next_node);
            target = (*target).next_node;
        }
        // create a new node
        // go to prev_node and modify its value to make it point to the new node
        // cout << "Found the end" << endl;
        // cout << "End node located at: " << target << endl;
        // cout << "Second last node's (next_node) value located at: " << prev_node << endl;
        node* newNode = (node*) malloc(sizeof(node));
        // cout << "Newly created node located at: " << &newNode << endl;
        (*newNode).key = key;
        (*newNode).value = value;
        (*newNode).next_node = target;
        *((node**)prev_node) = newNode;
        // cout << "At the end of the process... " << endl;
        // cout << "Start_node pointing to: " << start_node << endl;
        // cout << "New node's next code pointing to: " << (*newNode).next_node << endl;
    }
};

void printList(LinkedList* list)
{
    node* target = (*list).start_node;
    while(strcmp((*target).key, "end") != 0)
    {
        printString((*target).key);
        printString((*target).value);
        target = (*target).next_node;
    }
    cout << endl << endl;
}
int main(void)
{
    LinkedList list;
    cout << "Address of first node: " << list.start_node << endl;
    list.add("firstName", "moazin");
    printList(&list);
    list.add("lastname", "khatri");
    printList(&list);
    list.add("brother", "zubair");
    printList(&list);
    list.add("sister", "hafsa");
    printList(&list);
    list.add("father", "mehtab");
    printList(&list);
    return 0;
}
