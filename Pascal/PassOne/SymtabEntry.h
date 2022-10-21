#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <vector>
#include "Symtab.h"
#include "../Object.h"

using namespace std;

class Symtab;

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
    SymtabEntry(const string name, const Kind kind, Symtab *symtab);
    virtual ~SymtabEntry(){};

    string getName();                               //get the name of the entry
    Kind getKind();                                 //get the kind of entry
    void setKind(Kind kind);                        //set the kind of entry
    Symtab *getSymtab();                            //get the symbol table
    vector<int>* getLineNumebers();                  //get the array of line numbers
    void appendLineNumber(const int number);        //Append a source line number to the entry.
    Object getValue();                              //Get the data value stored with this entry.
    void setValue(Object value);                    //Set the data value into this entry.

    private:

    string name;
    Symtab *symtab;
    Kind kind;
    vector<int> lineNumbers; //an array of linenumbers
    Object *info;
};

#endif