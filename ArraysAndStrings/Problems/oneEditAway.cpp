#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "oneEditAway.h"

using namespace std;

int isOneEditAway(char* stringBase, char* stringNew)
{
    int lenBase = strlen(stringBase);
    int lenNew = strlen(stringNew);
    int exceptions = 0;
    if(lenBase==lenNew)
    {
        // we might have the replace case
        for(int i = 0; i < lenBase; i++)
        {
            if(stringBase[i]!=stringNew[i])
            {
                if(exceptions == 0)
                {
                    exceptions += 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else if(lenBase == (lenNew-1))
    {
        // we might have the addition case
        int cB=0, cN = 0;
        int exceptions = 0;
        // for(cB=0; cB < lenBase; cB++)
        while(cB < lenBase)
        {
            if(stringBase[cB] != stringNew[cN])
            {
                if(exceptions == 0)
                {
                    exceptions += 1;
                    cN += 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                cN += 1;
                cB += 1;
            }
        }
        return 1;
    }
    else if(lenNew == (lenBase-1))
    {
        // we might have the deletion case
        int cB=0, cN = 0;
        int exceptions = 0;
        // for(cN=0; cN < lenNew; cN++)
        while(cN < lenNew)
        {
            if(stringBase[cB] != stringNew[cN])
            {
                if(exceptions == 0)
                {
                    exceptions += 1;
                    cB += 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                cN += 1;
                cB += 1;
            }
        }
        return 1;
    }
    else 
    {
        // if its none of the above cases then simply its not one or zero edit away!
        return 0;
    }
}