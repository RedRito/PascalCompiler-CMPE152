#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <map>
#include "SymtabEntry.h"
using namespace std;

class Symtab
{
    private:
        map<string, SymtabEntry*> Table;
    public:

        //Entry to Table
        SymtabEntry *entry(string name)
        {
            SymtabEntry *newEntry = new SymtabEntry(name);  //making new entry class, with name initialized.
            Table[name] = newEntry;                         //add to Table.
            //return newEntry;
        }

        //Lookup an Entry:
        SymtabEntry *lookup(string name)
        {
            if(Table.find(name) != Table.end()) //find until end of map
            {
                return Table[name];             //if in map, return
            }
            else
            {
                return nullptr;                 //else return null
            }
        }
};

#endif