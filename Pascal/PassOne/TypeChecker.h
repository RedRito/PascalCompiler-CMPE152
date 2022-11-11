#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include "Typespec.h"

using namespace std;

class TypeChecker
{
public:
    
    static bool TypeChecker::isInteger(Typespec *typespec, Typespec *initial)
    {

        return    (typespec != nullptr)
           && (typespec->baseType() == initial->integerType);
    }

    static bool TypeChecker::areBothInteger(Typespec *typespec1, Typespec *typespec2, Typespec *initial)
    {
        return isInteger(typespec1, initial) && isInteger(typespec2, initial);
    }

   
    static bool TypeChecker::isReal(Typespec *typespec, Typespec *initial)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == initial->realType);
    }

    static bool TypeChecker::isIntegerOrReal(Typespec *typespec, Typespec *initial)
    {
        return isInteger(typespec, initial) || isReal(typespec, initial);
    }

    static bool TypeChecker::isAtLeastOneReal(Typespec *typespec1, Typespec *typespec2, Typespec *initial)
    {
        return (isReal(typespec1, initial) && isReal(typespec2, initial)) ||
           (isReal(typespec1, initial) && isInteger(typespec2, initial)) ||
           (isInteger(typespec1, initial) && isReal(typespec2, initial));
    }

    static bool TypeChecker::isBoolean(Typespec *typespec, Typespec *initial)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == initial->booleanType);
    }

    static bool TypeChecker::areBothBoolean(Typespec *typespec1, Typespec *typespec2, Typespec *initial)
    {
        return isBoolean(typespec1, initial) && isBoolean(typespec2, initial);
    }

    static bool TypeChecker::isChar(Typespec *typespec, Typespec *initial)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == initial->charType);
    }

    static bool TypeChecker::isString(Typespec *typespec, Typespec *initial)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == initial->stringType);
    }

    static bool TypeChecker::areBothString(Typespec *typespec1, Typespec *typespec2, Typespec *initial)
    {
        return isString(typespec1, initial) && isString(typespec2, initial);
    }

    static bool TypeChecker::areAssignmentCompatible(Typespec *targetTypespec, Typespec *valueTypespec, Typespec *initial)
    {
        if ((targetTypespec == nullptr) || (valueTypespec == nullptr)) return false;

        targetTypespec = targetTypespec->baseType();
        valueTypespec  = valueTypespec->baseType();

        bool compatible = false;

        if (targetTypespec == valueTypespec) compatible = true;

        else if (isReal(targetTypespec, initial) && isInteger(valueTypespec, initial)) compatible = true;

        return compatible;
    }   

    static bool TypeChecker::TypeChareComparisonCompatible (Typespec *typespec1, Typespec *typespec2, Typespec *initial)
    {
        if ((typespec1 == nullptr) || (typespec2 == nullptr))  return false;

        typespec1 = typespec1->baseType();
        typespec2 = typespec2->baseType();
        TypeForm form = typespec1->getForm();

        bool compatible = false;

        if ( (typespec1 == typespec2)
            && (form == SCALAR) )
        {
            compatible = true;
        }

        else if (isAtLeastOneReal(typespec1, typespec2, initial)) compatible = true;

        return compatible;
    }                                   
};


#endif /* TYPECHECKER_H_ */
