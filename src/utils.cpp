#include "../includes/utils.h"
#include <cctype>

using namespace std;

string toLowerCase(string str)
{
    string lowerStr = str;
    for (char &c : lowerStr)
    {
        c = tolower(c);
    }
    return lowerStr;
}