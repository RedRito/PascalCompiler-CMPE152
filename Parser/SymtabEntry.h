#ifndef PSYMTABENTRY_H_
#define PSYMTABENTRY_H_

#include <string>
using namespace std;
class SymtabEntry
{
    private:
        string name;    //the name of the sym
        int value;      //integer
    public:

        //Constructor
        SymtabEntry(string name)
        {
            this->name = name;
            value = 0;
        }
        
        //Getters
        string getName()
        {
            return name;
        }
        int getValue()
        {
            return value;
        }

        //Setter
        void setValue(int value)
        {
            this->value = value;
        }
};

#endif
