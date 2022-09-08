#include <string>
#include "Scanner/scanner.h"
#include "Scanner/FileReader.h"
#include "Scanner/PToken.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "RUN BY ./main \"FileName\"" << endl;
        exit(1);
    }
    string fileName = argv[1];
    FileReader *file = new FileReader(fileName);
    /*
    char currentCh = file -> getCurrentChar();
    while(currentCh != EOF)
    {
        currentCh = file -> nextChar();
        cout << currentCh;
    }
    cout << endl;
    cout << "END OF FILE" << endl;
    */
   Scanner *test = new Scanner(file);
   Token *token = test -> nextToken();
   cout << Token::toString(token) << endl;

}