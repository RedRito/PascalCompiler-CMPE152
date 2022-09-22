#include <iostream>
#include <fstream>
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
    cout << "printing symtab " << endl;
    parser->symtab->outputSymbolTable();
}
void testParserToFile(Scanner *scanner, Symtab *symtab, string filename)
{
    ofstream printFile;
    printFile.open(filename, std::ios_base::app);
    if (printFile.fail())
    {
        cout << " COULD NOT OPEN THE FILE " << filename << endl;
        exit(1);
    }

    Parser *parser = new Parser(scanner, symtab);
    printFile << "Parsing the program" << endl;
    ParserNode *programTree = parser->parseTheProgram();
    
    int errnum = parser->getErrNum();
    if (errnum == 0)
    {
        printFile << "Parse tree:" << endl << endl;
        TreeWalker *walker = new TreeWalker();
        walker->printToFile(programTree,filename);
        //walker->print(programTree);
    }
    else
    {
        printFile << endl << "There were " << errnum << " errors." << endl;
        TreeWalker *walker = new TreeWalker();
        walker->printToFile(programTree, filename);
    }
    printFile << "printing symtab " << endl;
    parser->symtab->outputSymbolTableToFile(filename);
    printFile.close();
}


int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "RUN BY ./main -{scan, parse, file} [\"FileName\"]" << endl;
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
    else if(optarg == "-file")
    {
        testParserToFile(new Scanner(file), new Symtab(), "test-out.txt");
    }
    return 0;
}