#include "SymtabEntry.h"


SymtabEntry::SymtabEntry(const string name, const Kind kind, Symtab *symtab): name(name), kind(kind), typespec(nullptr), symtab(symtab) 
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
virtual SymtabEntry::~SymtabEntry(){};

string SymtabEntry::getName()
{
    return name;
};                               //get the name of the entry
Kind SymtabEntry::getKind()
{
    return kind;
};                                 //get the kind of entry
void SymtabEntry::setKind(Kind kind)
{
    this->kind = kind;
};                        //set the kind of entry
Symtab *SymtabEntry::getSymtab(){
    return symtab;
};                            //get the symbol table

Typespec *SymtabEntry::getType() const { return typespec; }; //get the type

void SymtabEntry::setType(Typespec *typespec) { this->typespec = typespec; };


vector<int>* SymtabEntry::getLineNumebers()
{
    return &lineNumbers;
};                 //get the array of line numbers
void SymtabEntry::appendLineNumber(const int number)
{
    lineNumbers.push_back(number);
};        //Append a source line number to the entry.
Object SymtabEntry::getValue(const SymtabKey key)
{
    return (contents.find(key) != contents.end()) ? contents[key] : Object();
};                              //Get the data value stored with this entry.
void SymtabEntry::setValue(const SymtabKey key, Object value)
{
    contents[key] = value;
};                    //Set the data value into this entry.
