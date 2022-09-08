CC = g++
CFLAGS = -Wall -g

main: TestProgram.o scanner.o PToken.o FileReader.o
	g++ TestProgram.o scanner.o PToken.o FileReader.o -o main
TestProgram.o: TestProgram.cpp
	g++ -c TestProgram.cpp
scanner.o: Scanner/scanner.cpp  Scanner/scanner.h
	g++ -c Scanner/scanner.cpp
PToken.o: Scanner/PToken.cpp Scanner/PToken.h
	g++ -c Scanner/PToken.cpp
FileReader.o: Scanner/FileReader.cpp Scanner/FileReader.h
	g++ -c Scanner/FileReader.cpp

clean:
	rm *.o main