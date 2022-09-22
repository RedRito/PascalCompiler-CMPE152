CC = g++
CFLAGS = -Wall -g

main: TestProgram.o scanner.o PToken.o FileReader.o Parser.o TreeWalker.o ParserNode.o
	g++ TestProgram.o scanner.o PToken.o FileReader.o Parser.o ParserNode.o TreeWalker.o -o main
Parser.o: Parser/Parser.cpp Parser/Parser.h ParserNode.o
	g++ -c Parser/Parser.cpp 
ParserNode.o: Parser/ParserNode.cpp Parser/ParserNode.h	Parser/Symtab.h Parser/SymtabEntry.h
	g++ -c Parser/ParserNode.cpp
TestProgram.o: TestProgram.cpp
	g++ -c TestProgram.cpp
scanner.o: Scanner/scanner.cpp  Scanner/scanner.h
	g++ -c Scanner/scanner.cpp
PToken.o: Scanner/PToken.cpp Scanner/PToken.h
	g++ -c Scanner/PToken.cpp
FileReader.o: Scanner/FileReader.cpp Scanner/FileReader.h
	g++ -c Scanner/FileReader.cpp
TreeWalker.o: Parser/TreeWalker.cpp Parser/TreeWalker.h Parser/ParserNode.h Parser/ParserNode.cpp
	g++ -c Parser/TreeWalker.cpp
clean:
	rm *.o main
