#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <string>
#include <map>
#include <vector>

#include "../Object.h"
#include "Symtab.h"

using namespace std;

class Symtab;
class SymtabEntry;

enum class TypeForm
{
    SCALAR, ARRAY
};

static const string FORM_STRINGS[] = 
{
    "scalar", "array"
};

constexpr TypeForm SCALAR = TypeForm::SCALAR;
constexpr TypeForm ARRAY = TypeForm::ARRAY;

enum class TypeKey
{
    // Array
    ARRAY_INDEX_TYPE, ARRAY_ELEMENT_TYPE, ARRAY_ELEMENT_COUNT,
};

class Typespec 
{
    private:
        union TypeInfo
        {
            struct
            {
                Typespec *indexType;
                Typespec *elementType;
                int elementCount;
            } array;
        };

        TypeForm form;
        SymtabEntry *identifier;  // type identifier
        TypeInfo info;


public:
    /**
     * Constructor.
     * @param form the type form.
     */
    Typespec() : form((TypeForm) -1), identifier(nullptr) {}

    /**
     * Constructor.
     * @param form the type form.
     */
    Typespec(TypeForm form) : form(form), identifier(nullptr)
    {
        switch (form)
        {
            case TypeForm::ARRAY:
                info.array.indexType = nullptr;
                info.array.elementType = nullptr;
                info.array.elementCount = 0;
                break;
            default: break;
        }
    }

    /**
     * Destructor.
     */
    virtual ~Typespec() {}

    /**
     * Determine whether or not the type is structured (array)
     * @return true if structured, false if not.
     */
    bool isStructured() const
    {
        return (form == ARRAY);
    }

    /**
     * Get the type form.
     * @return the form.
     */
    TypeForm getForm() const { return form; }

    /**
     * Get the type identifier's symbol table entry.
     * @return the symbol table entry.
     */
    SymtabEntry *getIdentifier() const { return identifier; }

    /**
     * Set the type identifier's symbol table entry.
     * @param identifier the symbol table entry.
     */
    void setIdentifier(SymtabEntry *identifier) { this->identifier = identifier; }

    /**
    * Return the base type of this type.
    * @return the base type.
    */
    Typespec *baseType()
    {
        return this;
    }

    /**
     * Get the array index data type.
     * @return the data type.
     */
    Typespec *getArrayIndexType() const { return info.array.indexType; }

    /**
     * Set the array index data type.
     * @parm index_type the data type to set.
     */
    void setArrayIndexType(Typespec *index_type)
    {
        info.array.indexType = index_type;
    }

    /**
     * Get the array element data type.
     * @return the data type.
     */
    Typespec *getArrayElementType() const { return info.array.elementType; }

    /**
     * Set the array element data type.
     * @return element_type the data type to set.
     */
    void setArrayElementType(Typespec *element_type)
    {
        info.array.elementType = element_type;
    }

    /**
     * Get the array element count.
     * @return the count.
     */
    int getArrayElementCount() const { return info.array.elementCount; }

    /**
     * Set the array element count.
     * @parm element_count the count to set.
     */
    void setArrayElementCount(const int element_count)
    {
        info.array.elementCount = element_count;
    }


};

#endif /* TYPESPEC_H_ */