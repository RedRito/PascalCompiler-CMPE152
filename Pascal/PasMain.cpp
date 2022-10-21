#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "PascalLexer.h"
#include "PascalParser.h"
#include "TreeVisitor1.h"

using namespace std;
using namespace antlrcpp;
using namespace antlr4;
int main(int argc, const char *args[])
{
  ifstream ins;
  ofstream output;
  output.open("test-out.txt");
  ins.open(args[1]); //open given file from cli
  if(ins.fail())
  {
    cout << "failed to open file" << endl;
  }
  //lexer
  ANTLRInputStream input(ins);
  PascalLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  cout << "Tokens:" << endl;
  tokens.fill();
  for (Token *token : tokens.getTokens())
  {
    std::cout << token->toString() << std::endl;
    output << token->toString() << endl;
  }

  // Create a parser which parses the token stream
  // to create a parse tree.
  PascalParser parser(&tokens);
  tree::ParseTree *tree = parser.program();
  // tree *tree2 = parser.program();
  // int children = tree2->getChildCount();
  //cout << "amount of children in program parent is " << children << endl;
  // Print the parse tree in Lisp format.
  cout << tree->getText() << endl;
  cout << endl << "Parse tree (Lisp format):" << endl;
  std::cout << tree->toStringTree(&parser) << endl;

  TreeVisitor1 *visitor = new TreeVisitor1();
  visitor->visit(tree);
  ins.close();
  output.close();
  return 0;
}
