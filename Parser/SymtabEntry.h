#ifndef NEWSYMTABENTRY_H_
#define NEWSYMTABENTRY_H_

#include <string>
#include <vector>
#include <map>

namespace intermediate { namespace type {
    class Typespec;
}};

namespace intermediate { namespace symtab {

    using namespace std;
    using intermediate::type::Typespec;

    class Symtab;

    enum class identifier
    {
        CONSTANT, ENUMERATION_CONSTANT, TYPE, VARIABLE, RECORD_FIELD,
        VALUE_PARAMETER, REFERENCE_PARAMETER, PROGRAM_PARAMETER,
        PROGRAM, PROCEDURE, FUNCTION, UNDEFINED
    };// identifier

    static const string identifier_str[] =
    {
        "constant","enumeration constant","type","variable","record field","value parameter","reference parameter","program parameter",
        "PROGRAM","PROCEDURE","FUNCTION","undefined"
    };// identifier string

    static map<string, identifier> SymIdenti =
    {
        {"constant", identifier::CONSTANT},
        {"enumeration constant", identifier::ENUMERATION_CONSTANT},
        {"type", identifier::TYPE},
        {"variable", identifier::VARIABLE},
        {"record field", identifier::RECORD_FIELD},
        {"value parameter", identifier::VALUE_PARAMETER},
        {"reference parameter", identifier::REFERENCE_PARAMETER},
        {"program parameter", identifier::PROGRAM_PARAMETER},
        {"PROGRAM", identifier::PROGRAM},
        {"PROCEDURE", identifier::PROCEDURE},
        {"FUNCTION", identifier::FUNCTION},
        {"undefined", identifier::UNDEFINED}
    };// map

    class Entry
    {
        private:
            string symName;         //identifier name
            double symReal;         //identifier info
            int symInt;             //...
            bool symBoolean;        //...
            identifier kind;        //what kind of identifier
            vector<int> lineNum;    // source line number.
            Typespec *typespec;     //type specification
            Symtab *symtab;         //parent symbol table
            /*
            EntryInfo info;     //entry information
            */
        public:
            //constructor
            Entry(const string symName, const identifier kind, Symtab *symtab)
            //: symName(symName), identi(identi), symtab(symtab), typespec(nullptr)
            {
                switch (kind)
                {
                    case identifier::CONSTANT:
                    case identifier::ENUMERATION_CONSTANT:
                    case identifier::VARIABLE:
                    case identifier::RECORD_FIELD:
                    case identifier::VALUE_PARAMETER:
                    //info.data.value = nullptr;
                    default: break;
                }
            }
            /*
            Entry(string name) : symName(name), symReal(0.0)
            {
                //empty
            }
            */

            //Deconstructor
            virtual ~Entry()
            {
                //empty
            }

            //Getters
            string getName() const
            {
                return symName;
            }
            double getReal() const //DO THE GETTER AND SETTER FOR ALL PRIVATE VALUE TYPES
            {
                return symReal;
            }
            int getInt() const
            {
                return symInt;
            }
            bool getBool() const
            {
                return symBoolean;
            }
            identifier getIdenti() const{
                return kind;
            }
            Symtab *getSymtab() const{
                return symtab;
            }
            Typespec *getType() const{
                return typespec;
            }
            vector<int> *getLineNum()
            {
                return &lineNum;
            }

            //Setters
            void setName(const string symName)
            {
                this->symName = symName;
            }
            void setReal(const double symReal)
            {
                this->symReal = symReal;
            }
            void setInt(const int symInt)
            {
                this->symInt = symInt;
            }
            void setBool(const bool symBoolean)
            {
                this->symBoolean = symBoolean;
            }
            void setIdenti(const identifier kind)
            {
                this->kind = kind;
            }
            void setType(Typespec *typespec)
            {
                this->typespec = typespec;
            }
            void appendLineNum(const int num)
            {
                lineNum.push_back(num);
            }
    };// Entry
}}// intermediate::symtab

#endif