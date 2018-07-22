#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int isPalindrome(char* string);

int main(void)
{
    char* string = "tactcoa";
    cout << isPalindrome(string) << endl;
    return 0;
}

int isPalindrome(char* string)
{
    int charset[255];
    for(int i = 0; i < 255; i++)
    {
        charset[i] = 0;
    }
    int counter = 0;
    while(string[counter] != '\0')
    {
        charset[(int)string[counter]] += 1;
        counter += 1;
    }
    int exceptions = 0;
    for(int i = 0; i < 255; i++)
    {
        if(charset[i] % 2 != 0)
        {
            exceptions++;
        }
    }
    if((counter%2==0) && (exceptions > 0))
    {
        return 0;
    }
    else if((counter%2!=0) && (exceptions <= 1))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}