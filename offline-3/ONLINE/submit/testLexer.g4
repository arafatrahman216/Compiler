lexer grammar C8086Lexer;

@lexer::header {
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;
}

@lexer::members {
    void writeIntoLexLogFile(const std::string &message) {
        if (!lexLogFile.is_open()) {
            lexLogFile.open("lexLogFile.txt", std::ios::app);
            if (!lexLogFile) {
                std::cerr << "Error opening lexLogFile.txt" << std::endl;
                return;
            }
        }
        lexLogFile << message << std::endl;
        lexLogFile.flush();
    }
}

// ---------- Whitespace & Newline ----------
WS : [ \t\r\n]+ -> skip ;


// ---------- Keywords ----------
IF : 'if'         { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText()); };
ELSE : 'else'     { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText()); };
WHILE : 'while'   { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText()); };
FOR : 'for'       { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText()); };
RETURN : 'return' { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText()); };
INT : 'int'       { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText()); };
FLOAT : 'float'   { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText()); };
CHAR : 'char'     { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CHAR> Lexeme " + getText()); };
VOID : 'void'     { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText()); };
PRINTLN : 'println' { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText()); };

RELOP 
    : '!=' { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '!=' operator is not allowed in C8086." << std::endl;
      }
    | '<=' { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '<=' operator is not allowed in C8086." << std::endl;
      }
    | '>=' { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '>=' operator is not allowed in C8086." << std::endl;
      }
    | '==' { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '==' operator is not allowed in C8086." << std::endl;
      }
    | '<'  { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '<' operator is not allowed in C8086." << std::endl;
      }
    | '>'  { 
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());
        std::cerr << "Error: '>' operator is not allowed in C8086." << std::endl;
      };




// ---------- Symbols ----------
LPAREN : '('      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText()); };
RPAREN : ')'      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText()); };
LCURL  : '{'      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText()); };
RCURL  : '}'      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText()); };
LTHIRD : '['      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText()); };
RTHIRD : ']'      { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText()); };
SEMICOLON : ';'   { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText()); };
COMMA : ','       { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText()); };

// ---------- Operators ----------


MULOP : [*/%]     { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText()); };
LOGICOP : '&&' | '||' {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());
};
INCOP : '++' {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());
};
DECOP : '--' {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());
};
ASSIGNOP : '='    { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText()); };
NOT : '!'         { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText()); };
ADDOP : [+\-]     { writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText()); };

// ---------- Identifiers & Constants ----------
ID : [a-zA-Z_][a-zA-Z_0-9]* {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText());
};

CONST_INT : [0-9]+ {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());
};

CONST_FLOAT
    : [0-9]+ '.' [0-9]* ([eE][+\-]? [0-9]+)?    // float with optional exponent
    | '.' [0-9]+ ([eE][+\-]? [0-9]+)?           // leading decimal
    | [0-9]+ ([eE][+\-]? [0-9]+)                // int with exponent
    {
        writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_FLOAT> Lexeme " + getText());
    };

// ---------- Comments ----------
LINE_COMMENT : '//' ~[\r\n]* {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SINGLE LINE COMMENT> Lexeme " + getText());
};
BLOCK_COMMENT : '/*' .*? '*/' -> skip;


// ---------- Fallback ----------
ERROR_CHAR : . {
    writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ERROR> Unrecognized character: " + getText());
};
