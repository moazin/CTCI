#include <iostream>

using namespace std;

struct node {
    char* key;
    char* value;
    node* nextNode;
};

void printString(char* startChar)
{
    int counter = 0;
    while(startChar[counter] != '\0')
    {
        printf("%c", startChar[counter]);
        counter += 1;
    }
    printf("\n");
}
int main(void)
{
    node startNode, secondNode;
    startNode.key = "FirstName";
    startNode.value = "Moazin";
    startNode.nextNode = &secondNode;
    secondNode.key = "SecondName";
    secondNode.value = "Khatri";
    node* secNode = startNode.nextNode;
    printString((*secNode).key);
    printString((*secNode).value);
    return 0;
}

