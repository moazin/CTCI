#include <stdio.h>
#include <cstdlib>
#include "ResizableArray.h"

DynamicArray::DynamicArray()
{
    numbers = (int*) malloc(size*sizeof(int));
}
int DynamicArray::append(int value)
{
    // checks if we can add a value or not. If yes we add it .. if no we double the array size. copy over the old stuff and then add.
    if((size) > pointer)
    {
        // we are okay then.. we can add a new value
        numbers[pointer] = value;
        pointer += 1;
    }
    else 
    {
        int newSize = size * 2;
        // new allocation
        int *numbers2 = (int*) malloc(newSize * sizeof(int));
        // copying old stuff
        for(int i = 0; i < size; i++)
        {
            numbers2[i] = numbers[i];
        }
        //setting this one as the storage and freeing the old memory so that it can be used by other programs.
        size = newSize;
        free(numbers);
        numbers = numbers2;
        // now adding the value 
        numbers[pointer] = value;
        pointer += 1;
    }
}
void DynamicArray::print()
{
    for(int i = 0; i < pointer; i++)
    {
        printf("%c", numbers[i]);
    }
}

int DynamicArray::getSize()
{
    return pointer;
}

void DynamicArray::appendFromCString(char *base)
{
    int counter = 0;
    while(base[counter] != '\0')
    {
        append(base[counter]);
        counter += 1;
    }
}