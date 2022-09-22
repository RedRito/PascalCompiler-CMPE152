#include <iostream>
#include <fstream>
#include <string>
#include "Scanner/scanner.h"
#include "Scanner/FileReader.h"
#include "Scanner/PToken.h"
#include "Parser/Parser.h"
#include "Parser/TreeWalker.h"
using namespace std;

//test the scanner
void testScanner(FileReader *file)
{
    cout << "TESTING SCANNER" << endl;
    Scanner *test= new Scanner(file);
    test->printTokens();
}
//tests the parser, prints to stdout or your terminal
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
//tests the parser, APPENDS! output to a given file.
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

//main program
int main(int argc, char *argv[])
{
    //if the are not enough arguments 
    if(argc != 3)
    {
        cout << "RUN BY ./main -{scan, parse, tofile} [\"FileName\"]" << endl;
        exit(1);
    }
    string optarg = argv[1];
    string fileName = argv[2];
    FileReader *file = new FileReader(fileName);
    //scanner test
    if(optarg == "-scan")
    {
        testScanner(file);
    }
    else if(optarg == "-parse") //parser test
    {
        testParser(new Scanner(file), new Symtab());
    }
    else if(optarg == "-tofile")  //parser test tof file
    {
        testParserToFile(new Scanner(file), new Symtab(), "test-out.txt");
    }
    return 0;
}