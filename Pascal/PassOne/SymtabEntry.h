#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <vector>
#include "Symtab.h"
#include "Typespec.h"
#include "../Object.h"

namespace PassOne { namespace type { 
    class Typespec;
}}

namespace PassOne { namespace symtab {
    using namespace std;
    using PassOne::type::Typespec;
    class Symtab;
    class SymtabEntry;



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

enum class SymtabKey
{
    // Constant.
    CONSTANT_VALUE,

    // Procedure or function.
    ROUTINE_CODE, ROUTINE_SYMTAB, ROUTINE_ICODE,
    ROUTINE_PARMS, ROUTINE_ROUTINES,

    // Variable or record field value.
    DATA_VALUE
};


class SymtabEntry
{
    public:
    SymtabEntry(const string name, const Kind kind, Symtab *symtab): name(name), kind(kind), typespec(nullptr), symtab(symtab) 
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
    Symtab *getSymtab(){
        return symtab;
    };                            //get the symbol table

    Typespec *getType() const { return typespec; }; //get the type

    void setType(Typespec *typespec) { this->typespec = typespec; };


    vector<int>* getLineNumebers()
    {
        return &lineNumbers;
    };                 //get the array of line numbers
    void appendLineNumber(const int number)
    {
        lineNumbers.push_back(number);
    };        //Append a source line number to the entry.
    Object getValue(const SymtabKey key)
    {
        return (contents.find(key) != contents.end()) ? contents[key] : Object();
    };                              //Get the data value stored with this entry.
    void setValue(const SymtabKey key, Object value)
    {
        contents[key] = value;
    };                    //Set the data value into this entry.

    private:
    string name;
    Symtab *symtab;
    Kind kind;
    Typespec *typespec;
    vector<int> lineNumbers; //an array of linenumbers
    map<SymtabKey, Object> contents;
    Object *info;
};

}} //part of namespace symtab
#endif