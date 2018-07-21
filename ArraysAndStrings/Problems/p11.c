#include <stdio.h>

int checkUnique1(char *string);

int main(void)
{
    char *string = "Helo, wd!.,";
    int res = checkUnique1(string);
    printf("%d", res);
    return 0;
}

int checkUnique1(char *string)
{
    // determine the size of the string by finding the null character.
    int size = 0;
    while (string[size] != '\0')
    {
       size += 1; 
    }
    for(int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(string[i] == string[j])
            {
                return 0;
            }
        }
    }
    return 1;
    
}