#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ResizableArray.h"
#include <math.h>

using namespace std;

DynamicArray* compressString(char* string);

int main(void)
{
    char* string = "abbbcdeffghhhhho";
    cout << string << endl;
    compressString(string);
    return 0;
}

DynamicArray* compressString(char* string)
{
    DynamicArray newString;
    char prev = string[0];
    int cnt = 0; // holds the repeation count
    for(int i = 0; i < strlen(string); i++)
    {
        if(i==0)
        {
            // loop running for the first time
            newString.append(string[i]);
            prev = string[i];
        }
        else
        {
            if(prev==string[i])
                cnt += 1;
            else
            {
                if(cnt > 0)
                {
                    double no;
                    no = log(cnt+1);
                    char* tmp = (char*) malloc(((int)no + 2)*sizeof(char));
                    itoa(cnt+1, tmp, 10);
                    newString.appendFromCString(tmp);
                    free(tmp);
                    cnt = 0;
                }                
                newString.append(string[i]);
                prev = string[i];
            }
        }
    }
    newString.print();
    return &newString;
}