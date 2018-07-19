

void printString(char* string);

struct node {
    char* key;
    char* value;
    node* next_node;
};


class LinkedList
{
    public:
    node* start_node;
    int size = 0;
    LinkedList();
    void add(char* key, char* value);
    node getNode(int i);
    void print();
};

void printList(LinkedList* list);