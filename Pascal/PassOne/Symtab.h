#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <string>
#include <map>

#include "SymtabEntry.h"

using namespace std;



class Symtab{

    public:
    Symtab(const int nestingLevel): owner(nullptr), nestingLevel(nestingLevel){};

    virtual ~Symtab(){};

    int getNestingLevel(){
        return nestingLevel;
    };
    
    SymtabEntry* getOwner(){
        return owner;
    };

    void setOwner(SymtabEntry *newOwner)
    {
        owner = newOwner;
    };
    SymtabEntry *enter(const string name, const Kind kind)
    {
        SymtabEntry *entry = new SymtabEntry(name, kind); //make a new entry with the name, the kind of node, and this symbol tabke
        content[name] = entry;
        return entry;
    }; //Create and enter a new entry into the symbol table.

    SymtabEntry *lookup(const string name)
    {
        return (content.find(name) != content.end()) ? content[name] : nullptr;
    };                 //Look up an existing symbol table entry.
    vector<SymtabEntry*> sortEntries()
    {
        vector<SymtabEntry *> list;
        map<string, SymtabEntry *>::iterator it;

        // Iterate over the sorted entries and append them to the list.
        for (it = content.begin(); it != content.end(); it++)
        {
            list.push_back(it->second);
        }

        return list;
    };                     //Return a vector of entries sorted by name.
    void resetVariables(Kind kind)
    {
        vector<SymtabEntry *> list;
        map<string, SymtabEntry *>::iterator it;

        // Iterate over the entries and reset their kind.
        for (it = content.begin(); it != content.end(); it++)
        {
            SymtabEntry *entry = it->second;
            if (entry->getKind() == Kind::VARIABLE) entry->setKind(kind);
        }
    };                         //Reset all the variable entries to a kind.
    void printSymtab()
    {
        cout << "PRINTING SYMBOL TABLE" << endl;
        for(auto const& x : content)
        {
            cout << "Symtab entry: " << x.first << endl; 
        }
    };
    void printSymtabToFile(string filename)
    {
        ofstream file;
        file.open(filename, std::ios_base::app);
        if(file.fail())
        {
            cout << " COULD NOT OPEN THE FILE " << filename << endl;
            exit(1);
        }
        for(auto const& x : content)
        {
            file << "Symtab entry: " << x.first << endl; 
        }
        file.close();
    }

    private:
    SymtabEntry *owner;
    map<string, SymtabEntry*> content;
    int nestingLevel;
};


#endif