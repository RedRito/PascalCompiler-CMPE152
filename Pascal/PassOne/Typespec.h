#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <string>
#include <map>
#include <vector>

#include "../Object.h"
#include "Symtab.h"
#include "SymtabStack.h"
#include "SymtabEntry.h"

using namespace std;


using namespace PassOne::symtab;

namespace PassOne { namespace type {

using namespace std;



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
     Typespec *integerType;
     Typespec *realType;
     Typespec *booleanType;
     Typespec *charType;
     Typespec *stringType;
     Typespec *undefinedType;
     Typespec *voidType;

    SymtabEntry *integer_id;
    SymtabEntry *real_id;
    SymtabEntry *boolean_id;
    SymtabEntry *char_id;
    SymtabEntry *string_id;
    SymtabEntry *void_id;

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

    /**
     * Create a type specification of a given form.
     * @param form the form.
     * @return the type specification.
     */
    Typespec *create_type(const TypeForm form)
    {
        return new Typespec(form);
    }

    /**
     * Create a string type specification.
     * @param value the string value.
     * @return the type specification.
     */
    // Typespec *create_string_type(const string value)
    // {
    //     return new Typespec(value);
    // }

    void initialize(SymtabStack *symtabStack)
    {
        initialize_types(symtabStack);
    }

    void initialize_types(SymtabStack *symtab_stack)
    {
    // Type integer.
    const string strInt = "integer";
    integer_id = symtab_stack->enterLocal(strInt, Kind::TYPE);
    integerType = Typespec::create_type((TypeForm) SCALAR);
    integerType->setIdentifier(integer_id);
    integer_id->setKind(Kind::TYPE);
    integer_id->setType(integerType);

    // Type real.
    real_id = symtab_stack->enterLocal("real", Kind::TYPE);
    realType = Typespec::create_type((TypeForm) SCALAR);
    realType->setIdentifier(real_id);
    real_id->setKind(Kind::TYPE);
    real_id->setType(realType);

    // Type boolean.
    boolean_id = symtab_stack->enterLocal("boolean", Kind::TYPE);
    booleanType = Typespec::create_type((TypeForm) SCALAR);
    booleanType->setIdentifier(boolean_id);
    boolean_id->setKind(Kind::TYPE);
    boolean_id->setType(booleanType);

    // Type char.
    char_id = symtab_stack->enterLocal("char", Kind::TYPE);
    charType = Typespec::create_type((TypeForm) SCALAR);
    charType->setIdentifier(char_id);
    char_id->setKind(Kind::TYPE);
    char_id->setType(charType);

    // Type string
    string_id = symtab_stack->enterLocal("string", Kind::TYPE);
    stringType = Typespec::create_type((TypeForm) SCALAR);
    stringType->setIdentifier(string_id);
    string_id->setKind(Kind::TYPE);
    string_id->setType(stringType);

    // Undefined type.
    undefinedType = Typespec::create_type((TypeForm) SCALAR);

    // Type void.
    void_id = symtab_stack->enterLocal("void", Kind::TYPE);
    voidType = Typespec::create_type((TypeForm) SCALAR);
    voidType->setIdentifier(void_id);
    void_id->setKind(Kind::TYPE);
    void_id->setType(voidType);
    }

};

}}

#endif /* TYPESPEC_H_ */