#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void urlify(char* string);

int main(void)
{
    char* origString = "MY name IS MO Azin ";
    char* string = (char* ) malloc(100*sizeof(char));
    strcpy(string, origString);
    cout << "String Before: " << string << endl;
    urlify(string);
    cout << "String After: " << string << endl;
    return 0;
}

void urlify(char* string)
{
    // count the size and the spaces first
    int count = 0, spaces = 0;
    while(string[count] != '\0')
    {
        if(string[count] == ' ')
        {
            spaces += 1;
        }
        count += 1;
    }
    int total_len = count + (spaces)*2;
    int orig_point = count - 1;
    int new_point = total_len - 1;
    while(orig_point >= 0)
    {
        if(string[orig_point] != ' ')
        {
            string[new_point] = string[orig_point];
            new_point -= 1;
            orig_point -= 1;
        }
        else 
        {
            string[new_point] = '0';
            new_point -= 1;
            string[new_point] = '2';
            new_point -= 1;
            string[new_point] = '%';
            new_point -= 1;
            orig_point -= 1;
        }
    }
}