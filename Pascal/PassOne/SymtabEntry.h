#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_

#include <string>
#include <map>
#include <vector>
#include "Symtab.h"
#include "Typespec.h"
#include "../Object.h"

namespace PassOne { namespace type { 
    class Typespec;
}}

namespace PassOne { namespace symtab {
    using namespace std;
    using PassOne::type::Typespec;
    class Symtab;
    class SymtabEntry;



enum class Kind
{
    CONSTANT, ENUMERATION_CONSTANT, TYPE, VARIABLE, RECORD_FIELD,
    VALUE_PARAMETER, REFERENCE_PARAMETER, PROGRAM_PARAMETER,
    PROGRAM, PROCEDURE, FUNCTION,
    UNDEFINED
};

static const string KIND_STRINGS[] =
{
    "constant", "enumeration constant", "type", "variable", "record field",
    "value parameter", "reference parameter", "program parameter",
    "PROGRAM", "PROCEDURE", "FUNCTION",
    "undefined"
};

enum class SymtabKey
{
    // Constant.
    CONSTANT_VALUE,

    // Procedure or function.
    ROUTINE_CODE, ROUTINE_SYMTAB, ROUTINE_ICODE,
    ROUTINE_PARMS, ROUTINE_ROUTINES,
    ROUTINE_VARS_SIZE,  // total size of local variables on stack (in bytes)
    ROUTINE_PARMS_SIZE, // total size of parameters on stack (in bytes)
    ROUTINE_SERIAL,     // serial number (used for routine labels)
    ROUTINE_NESTING_LEVEL, // nesting level (starting from 1..)

    // Variable or record field value.
    DATA_VALUE,
    SIZE,  // variable size in bytes
    LOCATION        // location in stack frame 
};
enum class Routine
{
    DECLARED, FORWARD,
    READ, READLN, WRITE, WRITELN,
    ABS, ARCTAN, CHR, COS, EXP, LN, ODD, ORD,
    EOF_FUNCTION, EOLN_FUNCTION,
    PRED, ROUND, SIN, SQR, SQRT, SUCC, TRUNC,
};

class SymtabEntry
{
    public:
    SymtabEntry(const string name, const Kind kind, Symtab *symtab): name(name), kind(kind), typespec(nullptr), symtab(symtab) 
    {
        switch(kind)
        {
            case Kind::CONSTANT:
            case Kind::ENUMERATION_CONSTANT:
            case Kind::VARIABLE:
            case Kind::RECORD_FIELD:
            case Kind::VALUE_PARAMETER:
                info = nullptr;
                break;
            case Kind::PROGRAM:
            case Kind::PROCEDURE:
            case Kind::FUNCTION:
                routine.symtab = nullptr;
                routine.parameters  = new vector<SymtabEntry *>();
                routine.subroutines = new vector<SymtabEntry *>();
                break;
            default: break;
        }
    };
    virtual ~SymtabEntry(){};

    string getName()
    {
        return name;
    };                               //get the name of the entry
    Kind getKind()
    {
        return kind;
    };                                 //get the kind of entry
    void setKind(Kind kind)
    {
        this->kind = kind;
    };                        //set the kind of entry
    Symtab *getSymtab(){
        return symtab;
    };                            //get the symbol table

    Typespec *getType() const { return typespec; }; //get the type

    void setType(Typespec *typespec) { this->typespec = typespec; };


    vector<int>* getLineNumebers()
    {
        return &lineNumbers;
    };                 //get the array of line numbers
    void appendLineNumber(const int number)
    {
        lineNumbers.push_back(number);
    };        //Append a source line number to the entry.
    Object getValue()
    {
        return *info;
    };                              //Get the data value stored with this entry.
    void setValue(Object value)
    {
        info = new Object(value);
    };                    //Set the data value into this entry.
    void setAttribute(SymtabKey key, Object value) 
    {
        contents[key] = value;
    }
    Object getAttribute(SymtabKey key)
    {
        return contents[key];
    }
    bool hasAttribute(SymtabKey key)
    {
        return (contents.find(key) != contents.end());
    }
    Routine getRoutineCode() const { return routine.code; }

    /**
     * Set the routine code.
     * @parm code the code to set.
     */
    void setRoutineCode(const Routine code) { routine.code = code;}

    /**
     * Get the routine's symbol table.
     * @return the symbol table.
     */
    Symtab *getRoutineSymtab() const { return routine.symtab; }

    /**
     * Set the routine's symbol table.
     * @parm symtab the symbol table to set.
     */
    void setRoutineSymtab(Symtab *symtab) { routine.symtab = symtab; }

    /**
     * Get the vector of symbol table entries of the routine's formal parameters.
     * @return the vector.
     */
    vector<SymtabEntry *> *getRoutineParameters() const
    {
        return routine.parameters;
    }

    /**
     * Set the vector symbol table entries of parameters of the routine.
     * @parm parameters the vector to set.
     */
    void setRoutineParameters(vector<SymtabEntry *> *parameters)
    {
        routine.parameters = parameters;
    }

    /**
     * Get the vector of symbol table entries of the nested subroutines.
     * @return the vector.
     */
    vector<SymtabEntry *> *getSubroutines() const
    {
        return routine.subroutines;
    }

    /**
     * Append to the arraylist of symbol table entries of the nested subroutines.
     * @parm subroutineId the symbol table entry of the subroutine to append.
     */
    void appendSubroutine(SymtabEntry *subroutineId)
    {
        routine.subroutines->push_back(subroutineId);
    }

    /**
     * Get the routine's executable code.
     * @return the executable code.
     */
    Object getExecutable() const { return *routine.executable; }

    /**
     * Set the routine's executable code.
     * @parm executable the executable code to set.
     */
    void setExecutable(Object executable)
    {
        routine.executable = new Object(executable);
    }

    private:
    string name;
    Symtab *symtab;
    Kind kind;
    Typespec *typespec;    
    vector<int> lineNumbers; //an array of linenumbers
    map<SymtabKey, Object> contents;
    Object *info;
    struct 
    {
        Routine code;                        // routine code
        Symtab *symtab;                      // routine's symbol table
        vector<SymtabEntry *> *parameters;   // routine's formal parameters
        vector<SymtabEntry *> *subroutines;  // symtab entries of subroutines
        Object *executable;
    } routine;
    
};

}} //part of namespace symtab
#endif