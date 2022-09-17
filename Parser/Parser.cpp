#include "../Scanner/PToken.h"
#include "Parser.h"

//Pascal statement syntax
/*
    compound statment and assignment statment
    a compound statment contains a begin, statmentList, and end;
    a statment contains itself and may contain a semicolon
    an assignment statment contains a variable/identifier, " := " assign token, and an expression
*/

//Pascal expressions
/*
    simple expression, PLUSOP or MINUSOP a term, OPTIONALLY (with PLUSOP, MINUSOP, OROP, and a TERM)
    a expression is 2 simple expressions together with a relational operator = <> < <= > >=


    A TERM
    contains a factor, or optionally
        MULTOP, DIVOP, DIV, MOD, ANDOP
        as well as any number of factors

    A FACTOR
    contains a variable, xor a number, or a string, or a NOT followed by a factor, or a LEFTPAREN, expression, RIGHTPAREN.  
*/


//types of statements cont.
/*
    compoundStatments
    assignmentStatement
    WHILE statment
    Repeat statement        syntax = REPEAT -> statementlist -> UNTIL -> expression
    for statment    
    if statement
    case statement

*/

