#include <string>
#include "FileReader.cpp"
using namespace std;

int main()
{
    FileReader *file = new FileReader("HelloWorld.txt");
    char currentCh = file -> getCurrentChar();
    while(currentCh != EOF)
    {
        currentCh = file -> nextChar();
        cout << currentCh << endl;
    }
}