#include "SymtabEntry.h"


SymtabEntry::SymtabEntry(const string name, const Kind kind) : name(name), kind(kind)
{
    switch(kind)
    {
        case Kind::CONSTANT:
        case Kind::ENUMERATION_CONSTANT:
        case Kind::VARIABLE:
        case Kind::RECORD_FIELD:
        case Kind::VALUE_PARAMETER:
            info.data.value = nullptr;
            break;
        default: break;
    }
}

string SymtabEntry::getName()
{
    return name;
}

Kind SymtabEntry::getKind()
{
    return kind;
}

void SymtabEntry::setKind(Kind kind)
{
    this->kind = kind;
}

// Symtab* SymtabEntry::getSymtab()
// {
//     return symtab;
// }
vector<int>* SymtabEntry::getLineNumebers()
{
    return &lineNumbers;
}

void SymtabEntry::appendLineNumber(const int number)
{
    lineNumbers.push_back(number);
}

Object SymtabEntry::getValue()
{
    return *(info);
}

void SymtabEntry::setValue(Object value)
{
    info = new Object(value);
}