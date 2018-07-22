#include <stdio.h>
#include <cstdlib>

class DynamicArray
{
    private:
    int *numbers;
    int size = 1;
    int pointer = 0;
    // constructor for this class. It's the method called whenever a new object is made of this class.
    public:
    DynamicArray();
    int append(int value);
    void print();
    int getSize();
    void appendFromCString(char* string);
};
