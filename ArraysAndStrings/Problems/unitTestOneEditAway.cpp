#include "oneEditAway.h"
#include <iostream>

using namespace std;

void doTest(char* stringBase, char* stringNew)
{
    cout << stringBase << ", " << stringNew << " => ";
    if(isOneEditAway(stringBase, stringNew)==0)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
}

int main(void)
{
    doTest("cake", "bake");
    doTest("cake", "cakes");
    doTest("cake", "cakbs");
    doTest("cake", "caake");
    doTest("dope", "dopess");
    doTest("dizzy", "sizzy");
    doTest("beautiful", "beautful");
    doTest("beautiful", "baeutiful");
    return 0;
}