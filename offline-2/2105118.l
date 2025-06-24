%option noyywrap

%x TOKENIZE_CONST_CHAR
%x TOKENIZE_STRING
%x TOKENIZE_SLASH_COMMENT
%x TOKENIZE_STAR_COMMENT
%x TOKENIZE_CONST_FLOAT


%{

#include "2105118_tokenHandler.cpp"




FILE *fin ;

%}
 

WHITESPACE  [ \t]
NEWLINE     "\n"|"\r\n"
KEYWORD     "if"|"else"|"while"|"for"|"do"|"switch"|"case"|"goto"|"break"|"continue"|"return"|"default"|"int"|"float"|"char"|"double"|"long"|"short"|"unsigned"|"signed"|"const"|"static"|"struct"|"typedef"|"void"
MULOP       "*"|"/"|"%"
RELOP       "!="|">"|">="|"<="|"<"|"=="
NOT         "!"
BITOP		"&"|"|"|"^"|"<<"|">>"
LOGICOP     "&&"|"||"
INCOP       "++"|"--"
ALPHABET    [a-zA-Z]
DIGIT       [0-9]
ALPHANUM    ({ALPHABET}|"_")({ALPHABET}|{DIGIT})*
ID          ({ALPHABET}|"_")({ALPHANUM}|"_")*
CONST_FLOAT ({CONST_INT}\.?{DIGIT}+?{EXPONENT}?)|({DECIMAL})
CONST_INT   {DIGIT}+
DECIMAL     \.{DIGIT}+
EXPONENT    ([Ee][+-]?{DIGIT}+)
REDUNDANT_FLOAT_POINT	{DIGIT}*(\.{DIGIT}*){2,}{EXPONENT}?
FLOAT_NUM   			{DIGIT}*{DECIMAL}
FRACTION_IN_EXPONENT    [eE][+-]?{DIGIT}*{DECIMAL}+
ILLFORMED_NUMBER		({DIGIT}+|{FLOAT_NUM}){FRACTION_IN_EXPONENT}
INVALID_ID_SUFFIX_PREFIX_NUM   ({DIGIT}+|{FLOAT_NUM}){ID}
LPAREN          "("
RPAREN          ")"
LCURL           "{"
RCURL          "}"
ADDOP           "+"|"-"
ASSIGNOP        "="
SEMICOLON       ";"
LTHIRD          "["
RTHIRD          "]"
COMMA            ","
NONBACKSLASH    [^\\]
BACKSLASH	    "\\"
SINGLE_QUOTE	"\'"
DOUBLE_QUOTE	"\""
DOUBLE_SLASH	"\/\/"
STARSLASH       "/*"
STARSLASH_END   "*/"
SPECIAL_CHARACTER	    "\\0"|"\\v"|"\\b"|"\\r"|"\\f"|"\\a"|"\\\'"|"\\\\"|"\\t"|"\\n"|"\\\""


%%

{WHITESPACE}    {  }
{NEWLINE}       { lineno++; }
{KEYWORD}       { printTokenLexemPair("KEYWORD",yytext); }
{MULOP}         { printTokenLexemPair("MULOP",yytext); }
{RELOP}         { printTokenLexemPair("RELOP",yytext); }
{BITOP}         { printTokenLexemPair("BITOP",yytext); }
{INCOP}         { printTokenLexemPair("INCOP",yytext); }
{LOGICOP}       { printTokenLexemPair("LOGICOP",yytext); }
{CONST_INT}     { printTokenLexemPair("CONST_INT",yytext); }
{ID}            { printTokenLexemPair("ID",yytext); }
{CONST_FLOAT}   { printTokenLexemPair("CONST_FLOAT",yytext); }
{NOT}           { printTokenLexemPair("NOT",yytext); }
{LPAREN}        { printTokenLexemPair("LPAREN",yytext); }
{RPAREN}        { printTokenLexemPair("RPAREN",yytext); }
{LCURL}         { printTokenLexemPair("LCURL",yytext); }
{RCURL}         { printTokenLexemPair("RCURL",yytext); }
{ADDOP}         { printTokenLexemPair("ADDOP",yytext); }
{ASSIGNOP}        { printTokenLexemPair("ASSIGNOP",yytext); }
{SEMICOLON}     { printTokenLexemPair("SEMICOLON",yytext); }
{LTHIRD}        { printTokenLexemPair("LTHIRD",yytext); }
{RTHIRD}        { printTokenLexemPair("RTHIRD",yytext); }
{COMMA}         { printTokenLexemPair("COMMA",yytext); }
{REDUNDANT_FLOAT_POINT}  { 
    currentConvertedString = yytext;
    generateError("Too many decimal points",yytext);
    }
{ILLFORMED_NUMBER} 	{ 
    currentConvertedString = yytext;
    generateError("Ill formed number", yytext);   }
{INVALID_ID_SUFFIX_PREFIX_NUM} 	{ 
    currentConvertedString = yytext;
    generateError("Invalid prefix on ID or invalid suffix on Number", yytext);   }

<INITIAL><<EOF>> { ENDOFILE(); return 0;}

{SINGLE_QUOTE} {
    BEGIN TOKENIZE_CONST_CHAR;
    currentConvertedString = "\'";
    currentConstChar = "";
}
{DOUBLE_QUOTE} {
    BEGIN TOKENIZE_STRING;
    currentConvertedString = "\"";
    counter= 0;
    currentConstChar = "";

}
{DOUBLE_SLASH} {
    BEGIN TOKENIZE_SLASH_COMMENT;
    currentConvertedString = "//";
    counter= 0;
    currentConstChar = "";   
}
{STARSLASH} {
    BEGIN TOKENIZE_STAR_COMMENT;
    currentConvertedString = "/*";
    counter= 0;
    currentConstChar = "";
}



    <TOKENIZE_CONST_CHAR>{
    {SINGLE_QUOTE} {
        currentConvertedString += yytext;
        handleConstChar(currentConvertedString);
        BEGIN INITIAL;
    }
    {NEWLINE} {
        generateError("Unterminated character",currentConvertedString);
        lineno++;
        BEGIN INITIAL;
    }
    <<EOF>> {
        generateError("Unterminated character",currentConvertedString);
        ENDOFILE();
        return 0;
    }

    {BACKSLASH} {
        currentConstChar += yytext; 
        currentConvertedString += yytext;
    }
    {ALPHANUM} {
        currentConstChar += yytext;
        currentConvertedString += yytext;
    }
    {NONBACKSLASH} {
        currentConstChar += yytext;
        currentConvertedString += yytext;
    }

}

    <TOKENIZE_STRING>{
        {DOUBLE_QUOTE} {
            currentConvertedString += yytext;
            lineno += counter;
            handleString(currentConvertedString);
            BEGIN INITIAL;
        }
        <<EOF>> {
            lineno += counter;
            generateError("Unterminated string",currentConvertedString);
            ENDOFILE();
            return 0;
        }
        {BACKSLASH}{NEWLINE} {
            currentConvertedString += yytext;
            counter++;
            }
        {NEWLINE} {
            generateError("Unterminated string",currentConvertedString);
            lineno++;
            lineno += counter;
            BEGIN INITIAL;
        }
        {SPECIAL_CHARACTER} {
            currentConstChar += convertSpecialChar(yytext);
            currentConvertedString += yytext;
        }
        {NONBACKSLASH} {
            currentConstChar += yytext;
            currentConvertedString += yytext;
        }
        . {
            currentConstChar += yytext;
            currentConvertedString += yytext;
        }

        
        
    }

    <TOKENIZE_SLASH_COMMENT>{
        {BACKSLASH}{NEWLINE} {
            lineno++;
            currentConvertedString += yytext;
            
            
        }
        {NEWLINE} {
            handleComment(currentConvertedString);
            lineno++;
            lineno += counter;
            BEGIN INITIAL;
        }
        . {
            currentConvertedString += yytext;
        }

        
    }

    <TOKENIZE_STAR_COMMENT>{
        {STARSLASH_END} {
            currentConvertedString += yytext;
            lineno += counter;
            handleComment(currentConvertedString);
            BEGIN INITIAL;
        }
        {NEWLINE} {
            counter++;
            currentConvertedString += yytext;
        }
        <<EOF>> {
            generateError("Unterminated comment",currentConvertedString);
            lineno += counter;
            ENDOFILE();
            return 0;
        }
        . {
            currentConvertedString += yytext;
        }
    }

.               { 
    currentConvertedString = yytext;
    generateError("Unrecognized character",yytext); }

%%

int main(int argc, char **argv) {
    if(argc != 2){
		cout<<"Sorry! Name of the input file must be provided. Please Try again."<<endl;
		return 0;
	}
    fin = fopen(argv[1], "r");
    if(!fin){
        cout<<"Sorry! File could not be opened. Please Try again."<<endl;
        return 0;
    }
    yyin= fin;

    file.open("2105118_token.txt", ios::out);
    fout.open("2105118_log.txt", ios::out);
    st = new SymbolTable(numberOFBuckets, sdbm);
    yylex();
    file.close();
    fout.close();
    fclose(fin);
    return 0;
}
