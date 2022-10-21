#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <functional>

#include "antlr4-runtime.h"

typedef antlrcpp::Any Object;

using namespace std;

inline string toUpperCase(const string str)
{
    string upperCase(str);
    transform(upperCase.begin(), upperCase.end(), upperCase.begin(), ::toupper);
    return upperCase;
}

inline string toLowerCase(const string str)
{
    string lowerCase(str);
    transform(lowerCase.begin(), lowerCase.end(),
              lowerCase.begin(), ::tolower);
    return lowerCase;
}

inline string convertString(const string pascalString, bool needBackslash)
{
    string unquoted = pascalString.substr(1, pascalString.length()-2);
    size_t pos = 0;

    while ((pos = unquoted.find("''", pos)) != string::npos)
    {
        unquoted.replace(pos, 2, "'");
        pos++;
    }

    pos = 0;
    while ((pos = unquoted.find("\"", pos)) != string::npos)
    {
        if (needBackslash) unquoted.replace(pos, 1, "\\\"");
        else               unquoted.replace(pos, 1, "\"");

        pos+=2;
    }

    return unquoted;
}


#endif