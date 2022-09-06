#include <string>
#include "FileReader.cpp"
using namespace std;

int main()
{
    FileReader *file = new FileReader("HelloWorld.pas");
    char currentCh = file -> getCurrentChar();
    while(currentCh != EOF)
    {
        currentCh = file -> nextChar();
        cout << currentCh << endl;
    }
}