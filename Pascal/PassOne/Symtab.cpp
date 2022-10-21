#include "Symtab.h"
#include "SymtabEntry.cpp"

SymtabEntry * Symtab::getOwner()
{
    return owner;
}

void Symtab::setOwner(SymtabEntry* newOwner)
{
    owner = newOwner;
}

SymtabEntry * Symtab::enter(const string name, const Kind kind)
{
    SymtabEntry *entry = new SymtabEntry(name, kind, this); //make a new entry with the name, the kind of node, and this symbol tabke
    content[name] = entry;
    return entry;
}

SymtabEntry * Symtab::lookup(const string name)
{
    return (content.find(name) != content.end()) ? content[name] : nullptr;
}

vector<SymtabEntry*> Symtab::sortEntries()
{
    vector<SymtabEntry *> list;
    map<string, SymtabEntry *>::iterator it;

    // Iterate over the sorted entries and append them to the list.
    for (it = content.begin(); it != content.end(); it++)
    {
        list.push_back(it->second);
    }

    return list;  // sorted list of entries
}

void Symtab::resetVariables(Kind kind)
{
    vector<SymtabEntry *> list;
    map<string, SymtabEntry *>::iterator it;

    // Iterate over the entries and reset their kind.
    for (it = contents.begin(); it != contents.end(); it++)
    {
        SymtabEntry *entry = it->second;
        if (entry->getKind() == Kind::VARIABLE) entry->setKind(kind);
    }
}