#include <string>
#include "Scanner/scanner.h"
#include "Scanner/FileReader.h"
#include "Scanner/PToken.h"
#include "Parser/Parser.h"
#include "Parser/TreeWalker.h"
using namespace std;


void testScanner(FileReader *file)
{
    cout << "TESTING SCANNER" << endl;
    Scanner *test= new Scanner(file);
    test->printTokens();
}
void testParser(Scanner *scanner, Symtab *symtab)
{
    Parser *parser = new Parser(scanner, symtab);
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
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "RUN BY ./main -{scan, parse} [\"FileName\"]" << endl;
        exit(1);
    }
    string optarg = argv[1];
    string fileName = argv[2];
    FileReader *file = new FileReader(fileName);
    if(optarg == "-scan")
    {
        testScanner(file);
    }
    else if(optarg == "-parse")
    {
        testParser(new Scanner(file), new Symtab());

    }
    else
    {
        testParser(new Scanner(file), new Symtab());
    }
    return 0;
}