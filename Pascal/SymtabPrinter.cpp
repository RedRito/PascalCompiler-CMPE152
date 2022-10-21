#include "SymtabPrinter.h"


void SymtabPrinter::printSymtab(Symtab* symtab)
{
    cout << "PRINTING SYMTAB:" << endl;

    vector<SymtabEntry* > sorted = symtab->sortedEntires();
    for(SymtabEntry* entry : sorted)
    {
        cout << entry->getName() << endl;
    }
}