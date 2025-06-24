
flex 2105118.l  
g++ lex.yy.c -o lexer
./lexer ../inputs/input2.txt

# ../clean.sh
rm lex.yy.c
rm lexer