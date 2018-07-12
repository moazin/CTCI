#include <stdio.h>
#include <cstdlib>

class DynamicArray
{
    public:
    int *numbers;
    int size = 1;
    int pointer = 0;
    // constructor for this class. It's the method called whenever a new object is made of this class.
    DynamicArray()
    {
        numbers = (int*) malloc(size*sizeof(int));
    }
    int append(int value)
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
    void print()
    {
        for(int i = 0; i < pointer; i++)
        {
            printf("%d, ", numbers[i]);
        }
        printf("\n");
    }

};

int main(void)
{
    DynamicArray mozi;
    return 0;
}
