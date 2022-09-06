#include <string>
#include "FileReader.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    string fileName = argv[1];
    FileReader *file = new FileReader(fileName);
    char currentCh = file -> getCurrentChar();
    while(currentCh != EOF)
    {
        currentCh = file -> nextChar();
        cout << currentCh << endl;
    }
}