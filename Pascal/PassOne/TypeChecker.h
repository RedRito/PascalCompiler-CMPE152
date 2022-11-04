#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include "Typespec.h"

using namespace std;

class TypeChecker
{
public:
    
    static bool TypeChecker::isInteger(Typespec *typespec)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == Predefined::integerType);
    }

    static bool TypeChecker::areBothInteger(Typespec *typespec1, Typespec *typespec2)
    {
        return isInteger(typespec1) && isInteger(typespec2);
    }

   
    static bool TypeChecker::isReal(Typespec *typespec)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == Predefined::realType);
    }

    static bool TypeChecker::isIntegerOrReal(Typespec *typespec)
    {
        return isInteger(typespec) || isReal(typespec);
    }

    static bool TypeChecker::isAtLeastOneReal(Typespec *typespec1, Typespec *typespec2)
    {
        return (isReal(typespec1) && isReal(typespec2)) ||
           (isReal(typespec1) && isInteger(typespec2)) ||
           (isInteger(typespec1) && isReal(typespec2));
    }

    static bool TypeChecker::isBoolean(Typespec *typespec)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == Predefined::booleanType);
    }

    static bool TypeChecker::areBothBoolean(Typespec *typespec1, Typespec *typespec2)
    {
        return isBoolean(typespec1) && isBoolean(typespec2);
    }

    static bool TypeChecker::isChar(Typespec *typespec)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == Predefined::charType);
    }

    static bool TypeChecker::isString(Typespec *typespec)
    {
        return    (typespec != nullptr)
           && (typespec->baseType() == Predefined::stringType);
    }

    static bool TypeChecker::areBothString(Typespec *typespec1, Typespec *typespec2)
    {
        return isString(typespec1) && isString(typespec2);
    }

    static bool TypeChecker::areAssignmentCompatible(Typespec *targetTypespec,
                                        Typespec *valueTypespec)
    {
        if ((targetTypespec == nullptr) || (valueTypespec == nullptr)) return false;

        targetTypespec = targetTypespec->baseType();
        valueTypespec  = valueTypespec->baseType();

        bool compatible = false;

        if (targetTypespec == valueTypespec) compatible = true;

        else if (isReal(targetTypespec) && isInteger(valueTypespec)) compatible = true;

        return compatible;
    }   

    static bool TypeChecker::TypeChareComparisonCompatible (Typespec *typespec1,
                                        Typespec *typespec2)
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

        else if (isAtLeastOneReal(typespec1, typespec2)) compatible = true;

        return compatible;
    }                                   
};


#endif /* TYPECHECKER_H_ */
