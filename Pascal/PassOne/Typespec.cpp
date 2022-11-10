#include "Typespec.h"
 
 
 /**
     * Constructor.
     * @param form the type form.
     */
    Typespec::Typespec() : form((TypeForm) -1), identifier(nullptr) {}

    /**
     * Constructor.
     * @param form the type form.
     */
     Typespec::Typespec(TypeForm form) : form(form), identifier(nullptr)
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
    virtual  Typespec::~Typespec() {}

    /**
     * Determine whether or not the type is structured (array)
     * @return true if structured, false if not.
     */
    bool  Typespec::isStructured() const
    {
        return (form == ARRAY);
    }

    /**
     * Get the type form.
     * @return the form.
     */
    TypeForm  Typespec::getForm() const { return form; }

    /**
     * Get the type identifier's symbol table entry.
     * @return the symbol table entry.
     */
    SymtabEntry * Typespec::getIdentifier() const { return identifier; }

    /**
     * Set the type identifier's symbol table entry.
     * @param identifier the symbol table entry.
     */
    void  Typespec::setIdentifier(SymtabEntry *identifier) { this->identifier = identifier; }

    /**
    * Return the base type of this type.
    * @return the base type.
    */
    Typespec * Typespec::baseType()
    {
        return this;
    }

    /**
     * Get the array index data type.
     * @return the data type.
     */
    Typespec * Typespec::getArrayIndexType() const { return info.array.indexType; }

    /**
     * Set the array index data type.
     * @parm index_type the data type to set.
     */
    void  Typespec::setArrayIndexType(Typespec *index_type)
    {
        info.array.indexType = index_type;
    }

    /**
     * Get the array element data type.
     * @return the data type.
     */
    Typespec * Typespec::getArrayElementType() const { return info.array.elementType; }

    /**
     * Set the array element data type.
     * @return element_type the data type to set.
     */
    void  Typespec::setArrayElementType(Typespec *element_type)
    {
        info.array.elementType = element_type;
    }

    /**
     * Get the array element count.
     * @return the count.
     */
    int  Typespec::getArrayElementCount() const { return info.array.elementCount; }

    /**
     * Set the array element count.
     * @parm element_count the count to set.
     */
    void  Typespec::setArrayElementCount(const int element_count)
    {
        info.array.elementCount = element_count;
    }

    /**
     * Create a type specification of a given form.
     * @param form the form.
     * @return the type specification.
     */
    Typespec * Typespec::create_type(const TypeForm form)
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

    void  Typespec::initialize(SymtabStack *symtabStack)
    {
        initialize_types(symtabStack);
    }

    void  Typespec::initialize_types(SymtabStack *symtab_stack)
    {
    // Type integer.
    integer_id = symtab_stack->enterLocal("Integer", Kind::TYPE);
    integerType = Typespec::create_type((TypeForm) SCALAR);
    integerType->setIdentifier(integer_id);
    integer_id->setKind(Kind::TYPE);
    integer_id->setType(integerType);

    // Type real.
    real_id = symtab_stack->enterLocal("Real");
    realType = Typespec::create_type((TypeForm) SCALAR);
    realType->setIdentifier(real_id);
    real_id->setKind(Kind::TYPE);
    real_id->setType(realType);

    // Type boolean.
    boolean_id = symtab_stack->enterLocal("Boolean");
    booleanType = Typespec::create_type((TypeForm) SCALAR);
    booleanType->setIdentifier(boolean_id);
    boolean_id->setKind(Kind::TYPE);
    boolean_id->setType(booleanType);

    // Type char.
    char_id = symtab_stack->enterLocal("Char");
    charType = Typespec::create_type((TypeForm) SCALAR);
    charType->setIdentifier(char_id);
    char_id->setKind(Kind::TYPE);
    char_id->setType(charType);

    // Type string
    string_id = symtab_stack->enterLocal("String");
    stringType = Typespec::create_type((TypeForm) SCALAR);
    stringType->setIdentifier(string_id);
    string_id->setKind(Kind::TYPE);
    string_id->setType(stringType);

    // Undefined type.
    undefinedType = Typespec::create_type((TypeForm) SCALAR);

    // Type void.
    void_id = symtab_stack->enterLocal("Void");
    voidType = Typespec::create_type((TypeForm) SCALAR);
    voidType->setIdentifier(void_id);
    void_id->setKind(Kind::TYPE);
    void_id->setType(voidType);
    }