#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <map>
#include <iostream>
#include <fstream>
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
            return newEntry;
        }
        void outputSymbolTable()
        {
            for(auto const& x : Table)
            {
                cout << "Symtab entry: " << x.first << endl; 
            }
        }
        void outputSymbolTableToFile(string fileName)
        {
            ofstream printFile;
            printFile.open(fileName, std::ios_base::app);
            if (printFile.fail())
            {
                cout << " COULD NOT OPEN THE FILE " << fileName << endl;
                exit(1);
            }
            for(auto const& x : Table)
            {
                printFile << "Symtab entry: " << x.first << endl; 
            }
            printFile.close();

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