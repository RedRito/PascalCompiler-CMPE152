#ifndef NEWSYMTAB_H_
#define NEWSYMTAB_H_

#include <string>
#include <map>
#include "newSymtabEntry.h"

namespace intermediate{ namespace symtab {
    using namespace intermediate;
    using namespace std;
    #define UNNAMED_PREFIX string("_unnamed_")
    #define UNNAMED_PREFIX_LENGTH UNNAMED_PREFIX.length()
    class SymTable
    {
        private:
            static map<string, Entry *> SymContent;
            int nestLV;
            Entry *owner;
            static int unnamedCount;
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
            Entry *enter(const string name, identifier kind, Symtab *symtab)
            {
                Entry *anEntry = new Entry(name, kind, symtab);
                SymContent[name] = anEntry;
                return anEntry;
            }

            //Looking up symTable for existing symbol
            Entry *lookup(const string symName)
            {
                if(SymContent.find(symName) != SymContent.end())
                {
                    return SymContent[symName];
                }
                else
                {
                    return nullptr;
                }
                //return (SymContent.find(symName) != SymContent.end()) ? SymContent[symName] :nullptr;
            }

            //Generate unnamed type
            static string gernerateUnNamed()
            {
                unnamedCount++;
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
            void resetVar(identifier kind)
            {
                vector<Entry *> list;
                map<string, Entry *>::iterator it;

                for(it = SymContent.begin(); it != SymContent.end(); it++)
                {
                    Entry *anEntry = it->second;
                    if(anEntry->getIdenti() == VARIABLE)
                    {
                        anEntry->setIdenti(kind);
                    }
                }
            }


    };//SymTable
}}//intermediate

#endif