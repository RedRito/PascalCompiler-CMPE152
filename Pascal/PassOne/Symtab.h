#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>

#include "SymtabEntry.h"

using namespace std;

class SymtabEntry;
enum class Kind;

class Symtab{

    public:
    Symtab(): owner(nullptr){};

    virtual ~Symtab(){};
    
    SymtabEntry* getOwner();

    void setOwner(SymtabEntry *newOwner);
    SymtabEntry *enter(const string name, const Kind kind); //Create and enter a new entry into the symbol table.
    SymtabEntry *lookup(const string name);                 //Look up an existing symbol table entry.
    vector<SymtabEntry*> sortEntries();                     //Return a vector of entries sorted by name.
    void resetVariables(Kind kind);                         //Reset all the variable entries to a kind.

    private:
    SymtabEntry *owner;
    map<string, SymtabEntry*> content;
};


#endif