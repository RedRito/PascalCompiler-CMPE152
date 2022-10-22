#ifndef SYMTABPRINTER_H_
#define SYMTABPRINTER_H_

#include <string>
#include <vector>
#include "PassOne/Symtab.h"

class Symtab;

class SymtabPrinter
{

    public:
        void printSymtab(Symtab *symbtab);
        SymtabPrinter(Symtab *symtab): symtab(symtab){};
    private:
    Symtab *symtab;


};

#endif