#include "SymtabStack.h"


SymtabStack::SymtabStack() : current_nesting_level(0), program_id(nullptr)   //constructor
{
    stack.push_back(new Symtab(0));
}

virtual SymtabStack::~SymtabStack()              //destructor
{
    for (Symtab *symtab : stack) if (symtab != nullptr) delete symtab;
}

//get the current nesting level
int SymtabStack::getCurrentNestingLevel() const { return current_nesting_level; }

//get the prgram id
SymtabEntry *SymtabStack::getProgramId() const { return program_id; }

//set the program id
void SymtabStack::setProgramId(SymtabEntry *id) { program_id = id; }

//get the symtab
Symtab *SymtabStack::getLocalSymtab() const { return stack[current_nesting_level]; }

//push a symtab onto the stack
Symtab *SymtabStack::push()
{
    Symtab *symtab = new Symtab(++current_nesting_level);
    stack.push_back(symtab);

    return symtab;
}

//push a symtab onto the stack with a given parameter
Symtab *SymtabStack::push(Symtab *symtab)
{
    ++current_nesting_level;
    stack.push_back(symtab);

    return symtab;
}

//pop the symtab off the stack
Symtab *SymtabStack::pop()
{
    Symtab *symtab = stack[current_nesting_level];
    stack.erase(stack.begin() + current_nesting_level);
    current_nesting_level--;

    return symtab;
}

//enter an entry into the symtab at the nesting level
SymtabEntry *SymtabStack::enterLocal(const string name, const Kind kind)
{
    return stack[current_nesting_level]->enter(name, kind);
}

//lookup the symtab table
SymtabEntry *SymtabStack::lookupLocal(const string name) const
{
    return stack[current_nesting_level]->lookup(name);
}

/**
 * Look up an existing symbol table entry throughout the stack.
 * @param name the name of the entry.
 * @return the entry, or null if it does not exist.
 */
SymtabEntry *SymtabStack::lookup(const string name) const
{
    SymtabEntry *found_entry = nullptr;

    // Search the current and enclosing scopes.
    for (int i = current_nesting_level;
            (i >= 0) && (found_entry == nullptr); --i)
    {
        found_entry = stack[i]->lookup(name);
    }

    return found_entry;
}