#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <string>
#include <map>
#include <vector>

#include "Pascal/PassOne/Object.h"
#include "Pascal/PassOne/Symtab.h"

using namespace std;

enum class TypeForm
{
    SCALAR, ARRAY,
};

constexpr TypeForm SCALAR = TypeForm::SCALAR;
constexpr TypeForm ARRAY = TypeForm::ARRAY;

enum class TypeKey
{
    // Array
    ARRAY_INDEX_TYPE, ARRAY_ELEMENT_TYPE, ARRAY_ELEMENT_COUNT,
};

constexpr TypeKey ARRAY_INDEX_TYPE = TypeKey::ARRAY_INDEX_TYPE;
constexpr TypeKey ARRAY_ELEMENT_TYPE = TypeKey::ARRAY_ELEMENT_TYPE;
constexpr TypeKey ARRAY_ELEMENT_COUNT = TypeKey::ARRAY_ELEMENT_COUNT;

class TypeSpec 
{
public:
    /**
     * Constructor.
     * @param form the type form.
     */
    TypeSpec();

    /**
     * Constructor.
     * @param form the type form.
     */
    TypeSpec::TypeSpec() : form((TypeForm) -1), type_id(nullptr)
    {
        initialize();
    }

    TypeSpec::TypeSpec(TypeForm form) : form(form), type_id(nullptr)
    {
        initialize();
    }

    /**
     * Constructor.
     * @param value a string value.
     */
    TypeSpec::TypeSpec(string value)
{
    initialize();
    form = (TypeForm) ARRAY;

    int length = value.length();

    set_attribute((TypeKey) ARRAY_INDEX_TYPE, index_type);
    set_attribute((TypeKey) ARRAY_ELEMENT_TYPE, Predefined::char_type);
    set_attribute((TypeKey) ARRAY_ELEMENT_COUNT, length);
}
    /**
     * Destructor.
     */
    TypeSpec::~TypeSpec(){}

    /**
     * Getter
     * @return the type form.
     */
    TypeForm TypeSpec::get_form() const 
    { 
        return form; 
    }

    /**
     * Getter.
     * @return the type identifier (symbol table entry).
     */
    SymtabEntry *TypeSpec::get_identifier() 
    { 
        return type_id; 
    }

    /**
     * Setter.
     * @param id the type identifier (symbol table entry).
     */
    void TypeSpec::set_identifier(SymtabEntry *id) 
    {
        type_id = id; 
    }

    /**
     * Set an attribute of the specification.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    void TypeSpec::set_attribute(TypeKey key, Object value)
    {
        contents[key] = value;
    }

    /**
     * Get the value of an attribute of the specification.
     * @param key the attribute key.
     * @return the attribute value.
     */
    Object TypeSpec::get_attribute(TypeKey key)
    {
        return contents[key];
    }

    /**
     * Implementation of wci::intermediate::TypeSpec.
     * @return true if this is a Pascal string type.
     */
    bool TypeSpec::is_pascal_string()
    {
        if (form == (TypeForm) ARRAY)
        {
            Object type_value = get_attribute((TypeKey) ARRAY_ELEMENT_TYPE);
            TypeSpec *element_type = cast(type_value, TypeSpec*);

            type_value = this->get_attribute((TypeKey) ARRAY_INDEX_TYPE);
            TypeSpec *index_type = cast(type_value, TypeSpec*);

            return (element_type->base_type()  == Predefined::char_type) &&
                (index_type->base_type() == Predefined::integer_type);
        }
        else
        {
            return false;
        }
    }

 
  

private:
    TypeForm form;
    SymtabEntry *type_id;  // type identifier
    map<TypeKey, Object> contents;

    static bool INITIALIZED = false;

    map<TypeForm, string> TypeSpec::TYPE_FORM_NAMES;
    map<TypeKey,  string> TypeSpec::TYPE_KEY_NAMES;

    /**
     * Initialize the static maps.
     */
    void Typespec::initialize()
    {
        if (INITIALIZED) return;

    vector<TypeForm> form_keys =
    {
        TypeForm::SCALAR,
        TypeForm::ARRAY,
    };

    vector<string> form_names =
    {
        "scalar", "array",
    };

    for (int i = 0; i < form_keys.size(); i++)
    {
        TYPE_FORM_NAMES[form_keys[i]] = form_names[i];
    }

    INITIALIZED = true;
    }
}


#endif /* TYPESPEC_H_ */
