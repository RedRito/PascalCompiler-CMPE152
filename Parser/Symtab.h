#ifndef NEWSYMTAB_H_
#define NEWSYMTAB_H_

#include <string>
#include <map>
#include "SymtabEntry.h"

namespace intermediate{ namespace symtab {                  //Using necessarry namespaces.
    using namespace intermediate;
    using namespace std;
    #define UNNAMED_PREFIX string("_unnamed_")              //String name for all unnamed types,
    #define UNNAMED_PREFIX_LENGTH UNNAMED_PREFIX.length()   //and length.
    class SymTable                                          //Class for Symbol Table
    {
        private:
            static map<string, Entry *> SymContent;         //map for table
            int nestLV;                                     //nesting level
            Entry *owner;                                   //Owner of Table
            static int unnamedCount;                        //Counter for unnamed types
        public:
            //Constructor
            SymTable(const int nestLV)
            {
                //empty
            }

            //Destructor
            virtual ~SymTable()
            {
                //empty
            }

            //making entry to table
            //need symbol name, type, and parent table.
            Entry *enter(const string name, identifier kind, Symtab *symtab)
            {
                Entry *anEntry = new Entry(name, kind, symtab);
                SymContent[name] = anEntry;
                return anEntry;
            }

            //Looking up symTable for existing symbol by name.
            Entry *lookup(const string symName)
            {
                if(SymContent.find(symName) != SymContent.end())    //if name founded before end of table
                {
                    return SymContent[symName];                     //return name
                }
                else
                {
                    return nullptr;                                 //else null
                }
                //return (SymContent.find(symName) != SymContent.end()) ? SymContent[symName] :nullptr;
            }

            //Generate unnamed type
            static string generateUnNamed()
            {
                unnamedCount++;                                     //increment counter
                return UNNAMED_PREFIX + to_string(unnamedCount);
            }

            //Getters
            Entry *getOwner()
            {
                return owner;
            }
            int getNestLV()
            {
                return nestLV;
            }

            //Return vector of sorted Entries
            vector<Entry*> sortedEntry()
            {
                vector<Entry *> list;
                map<string, Entry *>::iterator it;  //iterates whole list
                for(it = SymContent.begin(); it != SymContent.end(); it++)
                {
                    list.push_back(it->second); //sorting entries
                }
                return list;                    //return the list after sort
            }

            //Setters
            void setOwner(Entry *owner)
            {
                this->owner = owner;
            }

            //Changing the types of all elements in table to kind.
            void resetKind(identifier kind)
            {
                vector<Entry *> list;
                map<string, Entry *>::iterator it;
                for(it = SymContent.begin(); it != SymContent.end(); it++)
                {
                    Entry *anEntry = it->second;
                    if(anEntry->getIdenti() == identifier::VARIABLE)
                    {
                        anEntry->setIdenti(kind);
                    }
                }
            }


    };//SymTable
}}//intermediate

#endif
