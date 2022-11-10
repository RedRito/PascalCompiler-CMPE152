#include "Symtab.h"

Symtab::Symtab(const int nestingLevel): owner(nullptr), nestingLevel(nestingLevel){};

virtual Symtab::~Symtab(){};

int Symtab::getNestingLevel(){
    return nestingLevel;
};

SymtabEntry* Symtab::getOwner(){
    return owner;
};

void Symtab::setOwner(SymtabEntry *newOwner)
{
    owner = newOwner;
};
SymtabEntry *Symtab::enter(const string name, const Kind kind)
{
    SymtabEntry *entry = new SymtabEntry(name, kind, this); //make a new entry with the name, the kind of node, and this symbol tabke
    content[name] = entry;
    return entry;
}; //Create and enter a new entry into the symbol table.

SymtabEntry *Symtab::lookup(const string name)
{
    return (content.find(name) != content.end()) ? content[name] : nullptr;
};                 //Look up an existing symbol table entry.
vector<SymtabEntry*> Symtab::sortEntries()
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
void Symtab::resetVariables(Kind kind)
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
void Symtab::printSymtab()
{
    cout << "PRINTING SYMBOL TABLE" << endl;
    for(auto const& x : content)
    {
        cout << "Symtab entry: " << x.first << endl; 
    }
};
void Symtab::printSymtabToFile(string filename)
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