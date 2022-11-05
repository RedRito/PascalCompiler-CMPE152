# PascalCompiler-CMPE152
Pascal compiler built with C++ and ANTLR4.
## Installation
1. Make sure to have Antlr4 installed. Follow this [repo](https://github.com/chriscons8/Compiler-Design.git): https://github.com/chriscons8/Compiler-Design.git to help with installation
2. In your home directory, copy files or clone files.

## How To Run
```
make antlr
make compile
./main.out -{scan, parse, tofile} "filename"
```

## Make Commands
1. make
  - run main
2. make antlr
  - runs antlr
3. make compile
  - compiles the necessary files
4. make clean
  - removes main.out