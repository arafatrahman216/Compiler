antlr4 -v 4.13.2 -Dlanguage=Cpp C2105118Lexer.g4
antlr4 -v 4.13.2 -Dlanguage=Cpp C2105118Parser.g4
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c C2105118Lexer.cpp C2105118Parser.cpp Ctester.cpp
g++ -std=c++17 -w C2105118Lexer.o C2105118Parser.o Ctester.o -L/usr/local/lib/ -lantlr4-runtime -o Ctester.out -pthread
LD_LIBRARY_PATH=/usr/local/lib ./Ctester.out $1
