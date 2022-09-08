#include <string>
#include "Scanner/scanner.h"
#include "Scanner/FileReader.h"
#include "Scanner/PToken.h"
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
    test ->printTokens();
    //test ->printToFile("masterTestCaseOutput.txt");
    //Testing Team 7's group test input file.
    FileReader *groupFile = new FileReader("test_in.txt");
    Scanner *groupTest = new Scanner(groupFile);
    groupTest ->printToFile("test-out.txt");

}