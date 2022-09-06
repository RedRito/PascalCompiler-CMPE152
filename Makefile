CC = g++
CFLAGS = -Wall -g

main: TestProgram.o
	g++ TestProgram.o -o main

TestProgram.o: TestProgram.cpp
	g++ -c TestProgram.cpp

clean:
	rm *.o