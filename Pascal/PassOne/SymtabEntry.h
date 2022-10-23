#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <vector>
//#include "Symtab.h"
#include "../Object.h"

using namespace std;

//class Symtab;

enum class Kind
{
    CONSTANT, ENUMERATION_CONSTANT, TYPE, VARIABLE, RECORD_FIELD,
    VALUE_PARAMETER, REFERENCE_PARAMETER, PROGRAM_PARAMETER,
    PROGRAM, PROCEDURE, FUNCTION,
    UNDEFINED
};

static const string KIND_STRINGS[] =
{
    "constant", "enumeration constant", "type", "variable", "record field",
    "value parameter", "reference parameter", "program parameter",
    "PROGRAM", "PROCEDURE", "FUNCTION",
    "undefined"
};

class SymtabEntry
{
    public:
    SymtabEntry(const string name, const Kind kind): name(name), kind(kind)
    {
        switch(kind)
        {
            case Kind::CONSTANT:
            case Kind::ENUMERATION_CONSTANT:
            case Kind::VARIABLE:
            case Kind::RECORD_FIELD:
            case Kind::VALUE_PARAMETER:
                info = nullptr;
                break;
            default: break;
        }
    };
    virtual ~SymtabEntry(){};

    string getName()
    {
        return name;
    };                               //get the name of the entry
    Kind getKind()
    {
        return kind;
    };                                 //get the kind of entry
    void setKind(Kind kind)
    {
        this->kind = kind;
    };                        //set the kind of entry
    //Symtab *getSymtab();                            //get the symbol table
    vector<int>* getLineNumebers()
    {
        return &lineNumbers;
    };                 //get the array of line numbers
    void appendLineNumber(const int number)
    {
        lineNumbers.push_back(number);
    };        //Append a source line number to the entry.
    Object getValue()
    {
        return *(info);
    };                              //Get the data value stored with this entry.
    void setValue(Object value)
    {
        info = new Object(value);
    };                    //Set the data value into this entry.

    private:

    string name;
    //Symtab *symtab;
    Kind kind;
    vector<int> lineNumbers; //an array of linenumbers
    Object *info;
};

#endif