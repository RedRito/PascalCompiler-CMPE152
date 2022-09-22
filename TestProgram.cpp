#include <string>
#include "Scanner/scanner.h"
#include "Scanner/FileReader.h"
#include "Scanner/PToken.h"
#include "Parser/Parser.h"
#include "Parser/TreeWalker.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "RUN BY ./main [\"FileName\"]" << endl;
        exit(1);
    }
    string fileName = argv[1];
    FileReader *file = new FileReader(fileName);

    Scanner *test = new Scanner(file);
    Symtab *symtab = new Symtab();
    Parser *parser = new Parser(test, symtab);
    cout << "Parsing the program" << endl;
    ParserNode *programTree = parser->parseTheProgram();
    int errnum = parser->getErrNum();
    if (errnum == 0)
    {
        cout << "Parse tree:" << endl << endl;
        TreeWalker *walker = new TreeWalker();
        walker->print(programTree);
        //walker->print(programTree);
    }
    else
    {
        cout << endl << "There were " << errnum << " errors." << endl;
        TreeWalker *walker = new TreeWalker();
        walker->print(programTree);
    }

}