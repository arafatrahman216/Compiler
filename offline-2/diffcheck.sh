
flex 2105118.l  
g++ lex.yy.c -o lexer

./lexer inputs/input1.txt
diff -wB 2105118_token.txt inputs/input1_token.txt
diff -wB 2105118_log.txt inputs/input1_log.txt


./lexer inputs/input2.txt
diff -wB 2105118_token.txt inputs/input2_token.txt
diff -wB 2105118_log.txt inputs/input2_log.txt


./lexer inputs/input3.txt
diff -wB 2105118_token.txt inputs/input3_token.txt
diff -wB 2105118_log.txt inputs/input3_log.txt

rm lex.yy.c
rm lexer