#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "PascalLexer.h"
#include "PascalParser.h"
#include "TreeVisitor1.h"
#include "TreeVisitor2.h"

using namespace std;
using namespace antlrcpp;
using namespace antlr4;


int main(int argc, const char *args[])
{
  if(argc != 3)
  {
    cout << "RUN BY ./main -{scan, parse, tofile, compile} [\"FileName\"]" << endl;
    exit(1);
  }
  string arg = args[1];
  string fileName = args[2];
  cout << "ARGS " << arg << endl;
  ifstream ins;
  ins.open(fileName); //open given file from cli
  if(ins.fail())
  {
    cout << "failed to open file" << endl;
  }
  //lexer
  ANTLRInputStream input(ins);
  PascalLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  tokens.fill();

  // Create a parser which parses the token stream
  // to create a parse tree.
  PascalParser parser(&tokens);
  tree::ParseTree *tree = parser.program();

  if(arg == "-scan")
  {
    cout << "Tokens:" << endl;
    for (Token *token : tokens.getTokens())
    {
      std::cout << token->toString() << std::endl;
    }
  }
  else if(arg == "-parse")
  {
    cout << endl << "Parse tree (Lisp format):" << endl;
    std::cout << tree->toStringTree(&parser) << endl;

    TreeVisitor1 *visitor = new TreeVisitor1();
    visitor->visit(tree);
  }
  else if(arg == "-tofile")
  {
    cout << endl << "Parse tree (Lisp format):" << endl;
    std::cout << tree->toStringTree(&parser) << endl;

    TreeVisitor1 *visitor = new TreeVisitor1();
    TreeVisitor1 visitor1;
    visitor->visit(tree);
    visitor->printToFile("test-out.txt");
  }
  else if(arg == "-compile")
  {
    cout << endl << "Compile:" << endl;
//    TreeVisitor1 *visitor = new TreeVisitor1();
//    visitor->visit(tree);
    cout << endl << "Generate code:" << endl;
    TreeVisitor2 *visitor = new TreeVisitor2();
    visitor->visit(tree);
  }
  else
  {
    cout << "RUN BY ./main -{scan, parse, tofile, compile} [\"FileName\"]" << endl;
  }
  

  ins.close();
  return 0;
}
