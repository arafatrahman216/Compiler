#include <iostream>
#include <bits/stdc++.h>
#include "addons/2105118_helper.h"
#include <string>
#include <fstream>

using namespace std;


int numberOFBuckets = 7;

SymbolTable * st ;


int lineno = 1;
int counter = 0;
int errorCount = 0;
int warningCount = 0;
int spaceCount = 0;


string currentString = "";
string currentSlashComment = "";
string currentStarComment = "";
string currentConstChar = "";
string currentConvertedString = "";
string currentFloat = "";



fstream file;
fstream fout;


string Capitalize(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        result += toupper(str[i]);
    }
    return result;
}

void printLineNo(bool error=false){
    if(!error){
        fout<<"Line no "<<lineno<<": ";
    }
    else{
        fout<<"Error at line no "<<lineno<<": ";
    }
}

bool handleSpecialChar(string text){
    if(text == "\'"){
        currentConstChar = "\'";
        currentConvertedString = "\'";
        return true;
    }
    else if(text == "\\"){
        currentConstChar = "\\";
        currentConvertedString = "\\";
        return true;
    }
    else if(text == "'\\n'"){
        currentConstChar= "\n";
        return true;
    }
    else if(text == "'\\r'"){
        currentConstChar = "\r";
        return true;
    }
    else if(text == "'\\f'"){
        currentConstChar = "\f";
        return true;
    }
    else if(text == "'\\b'"){
        currentConstChar = "\b";
        return true;
    }
    else if(text == "'\\t'"){
        currentConstChar = "\t";
        return true;
    }
    else if(text == "'\\v'"){
        currentConstChar = "\v";
        return true;
    }
    else if(text == "'\\a'"){
        currentConstChar = "\a";
        return true;
    }
    else if(text == "'\\0'"){
        currentConstChar = "\0";
        return true;
    }
    return false;
}

class TokenLexemPair{
    public:
    string lexem;
    string token;

    TokenLexemPair(){}

    TokenLexemPair( string token,string lexem){
        this->lexem = lexem;
        this->token = token;
    }

    string getLexem(){
        return lexem;
    }

    string getToken(){
        return token;
    }

    string print(){
        string result = "<" + token + "," + lexem + ">";    
        if(token == "KEYWORD"){
            result = "<" + lexem + ">";
        }
        return result;
    }
    
};


TokenLexemPair getTokenLexemPair(string token,string lexeme){
    if(token == "KEYWORD"){
        return TokenLexemPair(token, Capitalize(lexeme));
    }
    else {
        return TokenLexemPair(token, lexeme);
    }

    
}


void printTokenLexemPair(string token,string lexeme){
    TokenLexemPair tokenLexemPair ;
    printLineNo();
    if(token == "KEYWORD"){
        fout<<"Token <"<<Capitalize(lexeme)<<"> Lexeme "<<lexeme<<" found"<<endl<<endl;;
         tokenLexemPair = getTokenLexemPair(token,lexeme);
    }  
    else if (token=="ID" || token=="CONST_INT" || token=="CONST_FLOAT" || token=="CONST_CHAR" || token=="STRING"){
        if (token == "CONST_CHAR" || token == "STRING") {
            fout<<"Token <"<<token<<"> Lexeme "<<lexeme<<" found";
            fout<<" --> "<<"<"<<token<<", "<<currentConstChar<<">"<<endl<<endl;
             tokenLexemPair = getTokenLexemPair(token,currentConstChar);
        }
        else{
            fout<<"Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<endl<<endl;
             tokenLexemPair = getTokenLexemPair(token,lexeme);
        }

        if (token != "STRING"){
            if (st->Insert(lexeme,token)){
                st->PrintAllScopeTable();
            }
        }

    }
    else if(token == "LCURL"){
         tokenLexemPair = getTokenLexemPair(token,lexeme);
        fout<<"Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<endl<<endl;
        st->EnterScope();
    }
    else if(token == "RCURL"){
         tokenLexemPair = getTokenLexemPair(token,lexeme);
        fout<<"Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<endl<<endl;
        st->ExitScope();
    }else{
         tokenLexemPair = getTokenLexemPair(token,lexeme);
        fout<<"Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<endl<<endl;
    }
    if (token!="COMMENT")    file << tokenLexemPair.print()<<" ";
}

void generateError(string errorMessage,string text){
    errorCount++;
    // cout<<currentConstChar<<endl;
    // cout<<currentConvertedString<<endl;
    printLineNo(true);
    fout<<errorMessage <<" "<<currentConvertedString<<endl<<endl<<endl;
    currentConvertedString = "";
}

void handleConstChar(string text){
    if(text.length() == 2){
        generateError("Empty character constant error",currentConstChar);
    }
    else if(text.length() > 3){
        if(handleSpecialChar(text)){
            printTokenLexemPair("CONST_CHAR",text);
            return;
        }
        generateError("Multi character constant error",currentConstChar);
    }
    else{
        if(text == "\'\\\'"){ 
            generateError("Unterminated character",currentConstChar);
        }
        else{
            printTokenLexemPair("CONST_CHAR",text);
        }
    }
}



void ENDOFILE(){
    st->PrintAllScopeTable();
    fout<<"Total lines: "<<lineno<<endl;
    fout<<"Total errors: "<<errorCount<<endl;
    // cout<<"Total lines: "<<lineno<<endl;
    // cout<<"Total errors: "<<errorCount<<endl;
}

void handleString(string text){
    printTokenLexemPair("STRING",text);
}



char convertSpecialChar(string text){
	char character;
	char c = text[1];
	switch(c)
	{
		case '0': character = '\0'; break;
		case 'v': character = '\v'; break;
		case 'b': character = '\b'; break;
		case 'r': character = '\r'; break;
		case 'f': character = '\f'; break;
		case 'a': character = '\a'; break;
		case '\'': character = '\''; break;
		case '\\': character = '\\'; break;
		case 't': character = '\t'; break;
		case 'n': character = '\n'; break;
		case '\"': character = '\"'; break;
		default : character = '#';          
	}
	return character;
}

void handleComment(string text){
    printTokenLexemPair("COMMENT",text);
    // cout<<"Double slash"<<endl;
}