parser grammar C2105118Parser;

options {
    tokenVocab = C2105118Lexer;
}

@parser::header {
	#pragma once
    #include <iostream>
    #include <fstream>
	#include <vector>
    #include <string>
    #include <cstdlib>
    #include "C2105118Lexer.h"
	#include "addons/2105118_symbolTable.h"
    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
	

    extern int syntaxErrorCount;
}

@parser::members {
	SymbolTable symbolTable; 
	int func_def=0;
	std::string currentIndex= "CONST_INT";
	std::string currentType = "INT";
	std:: string retType = "";
	vector<std::string> currentParams;
	int inLoop =0;

    void writeIntoparserLogFile(const std::string message, int newlineCount=1) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }

        parserLogFile << message<< std::string(newlineCount, '\n');

         
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl << std::endl;
        errorFile.flush();
    }

	void insertIntoSymbolTable(const std::string &name, const std::string &type, int line_number, bool isArray=false, int isFunction=0, int func_params=0) {
		if (!symbolTable.Insert(name, type, isArray, isFunction,currentParams, parserLogFile) && isFunction == 0) {
			std::string errMsg = "Error at line " + std::to_string(line_number) + ": Multiple declaration of " + name;
			if (func_params > 0) {
				errMsg += " in parameter";
			}
			writeIntoErrorFile(errMsg);
			writeIntoparserLogFile(errMsg, 2);
			syntaxErrorCount++;
		}
		// cout << "Inserting into symbol table: " << name << " of type " << type << " at line " << line_number << endl;	
	}

	void printSymbolTable() {
		symbolTable.PrintAllScopeTable(parserLogFile);
		
	}

	void enterScope() {
		// cout<< "Entering a new scope." << endl;
		symbolTable.EnterScope();
	}

	void exitScope() {
		// cout<< "Exiting the current scope." << endl;
		printSymbolTable();
		symbolTable.ExitScope();
	}

	symbolInfo* getVarType(std::string var_name) {
		symbolInfo* sinfo = symbolTable.LookUp(var_name);
		if (sinfo == nullptr) {
			return nullptr;
		}
		return sinfo;
	}
}


start : program
	{
		std::string message = "Line "+ std::to_string($program.line_number) + ": start : program\n\n";
		writeIntoparserLogFile(message, 0);
		printSymbolTable();
		message="";
		message += "Total number of lines: " + std::to_string($program.line_number) + "\n";
		message += "Total number of errors: " + std::to_string(syntaxErrorCount) + "\n";
		writeIntoparserLogFile(message, 0);
	}
	;

program returns [std::string unit_name, int line_number]
	: pg=program unit {
			std::string message = "Line " + std::to_string($unit.line_number) + ": program : program unit";
		$unit_name = $pg.unit_name + "\n" + $unit.unit_name;
		$line_number = $unit.line_number;
		message += "\n\n" + $unit_name ;
		writeIntoparserLogFile(message, 2);
	}
	| unit  {
		std:: string message = "Line " + std::to_string($unit.line_number) + ": program : unit";
		message += "\n\n" + $unit.unit_name;
		$unit_name = $unit.unit_name;
		$line_number = $unit.line_number;
		writeIntoparserLogFile(message, 2);
	}

	;
	
unit returns  [ std::string unit_name ,int line_number] 
	: vd=var_declaration
	{
		std::string message = "Line " + std::to_string($vd.line_number) + ": unit : var_declaration";
		message += "\n\n" + $vd.var_name;
		$unit_name = $vd.var_name ;
		$line_number = $vd.line_number;
		writeIntoparserLogFile(message, 2);
	}
     | func_declaration {
		std::string message = "Line " + std::to_string($func_declaration.line_number) + ": unit : func_declaration";
		message += "\n\n" + $func_declaration.unit_name ;
		$unit_name = $func_declaration.unit_name;
		$line_number = $func_declaration.line_number;
		writeIntoparserLogFile(message, 2);
	}
     | func_definition {
		std::string message = "Line " + std::to_string($func_definition.line_number) + ": unit : func_definition";
		message += "\n\n" + $func_definition.unit_name ;
		$unit_name = $func_definition.unit_name;
		$line_number = $func_definition.line_number;
		writeIntoparserLogFile(message, 2);
	} 
    ;

func_declaration returns [std::string unit_name, int line_number]
		 : type_specifier ID LPAREN parameter_list RPAREN sm=SEMICOLON {
			std::string var_type = $type_specifier.type;
			insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(),false, 1);
		std::string message = "Line " + std::to_string($sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
		message += "\n\n" + $type_specifier.name_line + " " + $ID->getText() + "(" + $parameter_list.name_line + ");";
		writeIntoparserLogFile(message, 2);
		$unit_name = $type_specifier.name_line + " " + $ID->getText() + "(" + $parameter_list.name_line + ");";
		$line_number = $ID->getLine();

		}
		| type_specifier ID LPAREN RPAREN sm=SEMICOLON  {
			std::string var_type = $type_specifier.type;
			insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(),false, 1);
			std::string message = "Line " + std::to_string($sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
			message += "\n\n" + $type_specifier.name_line + " " + $ID->getText() + "();";
			writeIntoparserLogFile(message, 2);
			$unit_name = $type_specifier.name_line + " " + $ID->getText() + "();";
			$line_number = $ID->getLine();
	}
		;

func_definition returns [std::string unit_name, int line_number]
		: type_specifier ID {			
			std::string var_type = $type_specifier.type;
			// cout<< "var_type is: " << var_type << endl;
			retType = var_type;
			cout<< "retType is: " << retType << endl;
			
			insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(),false, 1);
		}
		LPAREN {
				func_def=1;
				enterScope();
			}
			parameter_list{

				symbolInfo* sinfo = getVarType($ID->getText());
				int isFunction = sinfo ? sinfo->getIsFunction() : 1;
				if (isFunction == 0){
					std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText();
					writeIntoErrorFile(errMsg);
					writeIntoparserLogFile(errMsg, 2);
					syntaxErrorCount++;
				}
				if (sinfo != nullptr && sinfo->getType() != var_type) {
					std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Return type mismatch of " + $ID->getText();
					writeIntoErrorFile(errMsg);
					writeIntoparserLogFile(errMsg, 2);
					syntaxErrorCount++;
			}
				
				} RPAREN cs=compound_statement {
			// cout<< "type_specifier is: " << $type_specifier.name_line << endl;
			$unit_name = $type_specifier.name_line + " " + $ID->getText() + "(" + $parameter_list.name_line + ")" + $cs.unit_name ;
			$line_number = $cs.line_number;
			std::string message = "Line " + std::to_string($cs.line_number) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
			retType = "";
		}
		| type_specifier ID {
		std::string var_type = $type_specifier.type;
		// cout<< "var_type is: " << var_type << endl;
		retType = var_type;
		cout<< "retType is: " << retType << endl;
			insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(),false, 1);
		}
		LPAREN{
				func_def=1;
				enterScope();	
		}
			 RPAREN cs=compound_statement {
			// cout<< "type_specifier is: " << $type_specifier.name_line << endl;
			$unit_name = $type_specifier.name_line + " " + $ID->getText() + "()" + $cs.unit_name;
			$line_number = $cs.line_number;
			std::string message = "Line " + std::to_string($cs.line_number) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement";
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
 		;				


parameter_list returns [std::string name_line]
  : pl=parameter_list COMMA type_specifier ID{
	// cout<< "func_def is: "<< func_def <<endl;
	std::string var_type = $type_specifier.type;
	currentParams.push_back($ID->getText());
	if (func_def==1) {
		insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(), false, 0,1);
	}
	// cout<<"Inserting into symbol table: "<< $ID->getText() <<"while func_def is"<<func_def<<endl;
	$name_line = $pl.name_line + "," + $type_specifier.name_line + " " + $ID->getText();
	std::string message = "Line " + std::to_string($ID->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID";
	message += "\n\n" + $name_line;
	writeIntoparserLogFile(message, 2);
	}


	| pl=parameter_list COMMA type_specifier {
	$name_line = $pl.name_line + ", " + $type_specifier.name_line;
	std::string message = "Line " + std::to_string($type_specifier.line_number) + ": parameter_list : parameter_list COMMA type_specifier";
	message += "\n\n" + $name_line;
	writeIntoparserLogFile(message, 2);
	}
	| type_specifier ID {
	// cout<< "func_def is: "<< func_def <<endl;

	currentParams.push_back($ID->getText());
	cout<< "size is : " << currentParams.size() << endl;
	std::string var_type = $type_specifier.type;
	if (func_def==1) {
		insertIntoSymbolTable($ID->getText(), var_type, $ID->getLine(), false, 0,1);
	}
	$name_line = $type_specifier.name_line + " " + $ID->getText();
	std::string message = "Line " + std::to_string($ID->getLine()) + ": parameter_list : type_specifier ID";
	message += "\n\n" + $name_line;
	writeIntoparserLogFile(message, 2);
	}
	| type_specifier {
		$name_line = $type_specifier.name_line;
		std::string message = "Line " + std::to_string($type_specifier.line_number) + ": parameter_list : type_specifier";
		message += "\n\n" + $type_specifier.name_line;
		writeIntoparserLogFile(message, 2);
	}
 		;

 		
compound_statement returns [std::string unit_name, int line_number]
	
			: LCURL{
				if (func_def==1) func_def=0;
				else enterScope();
			}
			statements RCURL {
				std::string message = "Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL statements RCURL";
				$unit_name = "{\n" + $statements.unit_name + "\n}";
				$line_number = $RCURL->getLine();
				message += "\n\n" + $unit_name;
				writeIntoparserLogFile(message, 2);
				exitScope();

				if ($statements.retError) {
					std::string errMsg = "Error at line " + std::to_string($RCURL->getLine()) + ": Cannot return value from function foo4 with void return type";
					writeIntoErrorFile(errMsg);
					message = errMsg;
					writeIntoparserLogFile(message, 2);
					syntaxErrorCount++	;
				}
				if (inLoop == 1) {
					inLoop = 0;
				}
			}
 		    | LCURL{
				if (func_def==1) func_def=0;
				else enterScope();
			}
			RCURL { 
				func_def=0;
				std::string message = "Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL RCURL";
				$unit_name = "{\n}";
				$line_number = $RCURL->getLine();
				message += "\n\n" + $unit_name;
				writeIntoparserLogFile(message, 2);
				exitScope();
				if (inLoop == 1) {
					inLoop = 0;
				}

			}
 		    ;
 		    
var_declaration returns [std::string var_name, int line_number]
    : t=type_specifier dl=declaration_list sm=SEMICOLON {
		std::string var = $t.name_line + " " + $dl.name_line + ";";
		std::string message = "Line "+ std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON";
		if ($t.type == "VOID") {
			std::string errMsg = "Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void";
			writeIntoErrorFile(errMsg);
			message += "\n\n" + errMsg;
			syntaxErrorCount++;
		}
		message += "\n\n" + var; 
		$var_name = var;
		$line_number = $sm->getLine();
		writeIntoparserLogFile(message, 2);
      }

	  |
	  t=type_specifier dl=declaration_list ASSIGNOP logic_expression sm=SEMICOLON {
		std::string var = $t.name_line + " " + $dl.name_line + $ASSIGNOP->getText() + $logic_expression.var_name + ";";
		std::string message = "Line "+ std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON";
		message += "\n\n" + var; 
		$var_name = var;
		$line_number = $sm->getLine();
		writeIntoparserLogFile(message, 2);
      }

    | t=type_specifier de=declaration_list_err sm=SEMICOLON {
        writeIntoErrorFile(
            std::string("Line# ") + std::to_string($sm->getLine()) +
            " with error name: " + $de.error_name +
            " - Syntax error at declaration list of variable declaration"
        );

        syntaxErrorCount++;
      }
    ;

declaration_list_err returns [std::string error_name]: {
        $error_name = "Error in declaration list";
		cout << "Error in declaration list" << endl;
    };

 		 
type_specifier returns [std::string name_line, int line_number, std::string type]	
		: INT {
			$name_line = "int";
			$line_number = $INT->getLine();
			$type = "INT";
			currentType = "INT";
			std::string message = "Line " + std::to_string($INT->getLine()) + ": type_specifier : INT"+ "\n\n" + $INT->getText();
			writeIntoparserLogFile(message,2);
		}
 		| FLOAT {
            $name_line = "float";
			$line_number = $FLOAT->getLine();
			$type = "FLOAT";
			currentType = "FLOAT";
			std::string message = "Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT"+ "\n\n" + $FLOAT->getText();
			writeIntoparserLogFile(message,2);
        }
 		| VOID {
            $name_line = "void";
			$line_number = $VOID->getLine();
			$type = "VOID";
			currentType = "VOID";
			std::string message = "Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID"+ "\n\n" + $VOID->getText();
			writeIntoparserLogFile(message,2);
        }
 		;
 		
declaration_list returns [std::string name_line]
 		  
		  : dl=declaration_list COMMA ID {
			$name_line = $dl.name_line +"," + $ID->getText();
			std::string message = "Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID"+ "\n\n" + $name_line;
			insertIntoSymbolTable($ID->getText(), currentType, $ID->getLine(), false,0);
			writeIntoparserLogFile(message,2);
			}
 		  | dl=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
			$name_line = $dl.name_line + "," + $ID->getText() + "[" + $CONST_INT->getText() + "]";
			std::string message = "Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + $name_line;
			insertIntoSymbolTable($ID->getText(), currentType, $ID->getLine(), true);
			writeIntoparserLogFile(message,2);
		  }
 		  | ID {
			$name_line = $ID->getText() ;
			std::string message = "Line " + std::to_string($ID->getLine()) + ": declaration_list : ID"+ "\n\n" + $ID->getText();
			insertIntoSymbolTable($ID->getText(), currentType, $ID->getLine(), false,0);
			writeIntoparserLogFile(message,2);
		  }
 		  | ID LTHIRD CONST_INT RTHIRD {
			$name_line = $ID->getText() + "[" + $CONST_INT->getText() + "]";
			std::string message = "Line " + std::to_string($ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + $name_line;
			insertIntoSymbolTable($ID->getText(), currentType, $ID->getLine(), true,0);
			writeIntoparserLogFile(message,2);
		  }
 		  ;
 		  
statements returns [std::string unit_name, int line_number, bool retError= false]
		: statement {
			$unit_name = $statement.unit_name;
			$line_number = $statement.line_number;
			$retError = $statement.retError;
			std::string message = "Line " + std::to_string($statement.line_number) + ": statements : statement";
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	   | sts=statements statement {
			$unit_name = $sts.unit_name + "\n" + $statement.unit_name;
			$line_number = $statement.line_number;
			std::string message = "Line " + std::to_string($statement.line_number) + ": statements : statements statement";
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		} 
	   ;
	   
statement returns [std::string unit_name, int line_number, bool retError= false]
	  
		: var_declaration {
			std::string message = "Line " + std::to_string($var_declaration.line_number) + ": statement : var_declaration";
			$unit_name = $var_declaration.var_name;
			$line_number = $var_declaration.line_number;
			message += "\n\n" + $unit_name ;
			writeIntoparserLogFile(message, 2);
		}
	  | expression_statement { 
			std::string message = "Line " + std::to_string($expression_statement.line_number) + ": statement : expression_statement";
			$unit_name = $expression_statement.unit_name;
			$line_number = $expression_statement.line_number;
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | compound_statement {
		std::string message = "Line " + std::to_string($compound_statement.line_number) + ": statement : compound_statement";
		$unit_name = $compound_statement.unit_name;
		$line_number = $compound_statement.line_number;
		message += "\n\n" + $unit_name;
		writeIntoparserLogFile(message, 2);
		}
	  | FOR LPAREN esa=expression_statement esb=expression_statement expression RPAREN statement {
			$line_number = $statement.line_number;
			std::string message = "Line " + std::to_string($line_number) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement";
			$unit_name = "for (" + $esa.unit_name + "" + $esb.unit_name + "" + $expression.var_name + ") " + $statement.unit_name;
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | IF LPAREN expression RPAREN st=statement {
			$line_number = $st.line_number;
			std::string message = "Line " + std::to_string($line_number) + ": statement : IF LPAREN expression RPAREN statement";
			$unit_name = "if (" + $expression.var_name + ") " + $st.unit_name;
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | IF LPAREN expression RPAREN s1=statement ELSE s2=statement { 
			$line_number = $s2.line_number;
			std::string message = "Line " + std::to_string($line_number) + ": statement : IF LPAREN expression RPAREN statement ELSE statement";
			$unit_name = "if (" + $expression.var_name + ") " + $s1.unit_name + " else " + $s2.unit_name;
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | WHILE LPAREN expression RPAREN statement {
			$line_number = $statement.line_number;
			std::string message = "Line " + std::to_string($line_number) + ": statement : WHILE LPAREN expression RPAREN statement";
			$unit_name = "while (" + $expression.var_name + ") " + $statement.unit_name;
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
			$line_number = $ID->getLine();
			std::string message = "Line " + std::to_string($line_number) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON";
			symbolInfo* sinfo = getVarType($ID->getText());
			if (sinfo == nullptr) {
				std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText();
				writeIntoErrorFile(errMsg);
				message += "\n\n" + errMsg;
				syntaxErrorCount++;
				currentIndex = "";
			}
			$unit_name = "printf(" + $ID->getText() + ");";
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
	  | RETURN expression sm=SEMICOLON {
			if (retType == "VOID") {
				$retError = true;
			}
			std::string message = "Line " + std::to_string($RETURN->getLine()) + ": statement : RETURN expression SEMICOLON";
			$unit_name = "return " + $expression.var_name + " ;";
			$line_number = $sm->getLine();
			message += "\n\n" + $unit_name;
			cout << "return" << endl;
			writeIntoparserLogFile(message, 2);

		}
		|
		BREAK sm=SEMICOLON {
			if (inLoop==1){
				std::string message = "Line " + std::to_string($BREAK->getLine()) + ": statement : BREAK SEMICOLON";
				$unit_name = "break ;";
				$line_number = $sm->getLine();
				message += "\n\n" + $unit_name;
				
				writeIntoparserLogFile(message, 2);
			}
			else { 
				std::string message = "Line " + std::to_string($BREAK->getLine()) + ": Break outside loop";
				$unit_name = "break ;";
				$line_number = $sm->getLine();
				message += "\n\n" + $unit_name;
				writeIntoparserLogFile(message, 2);
			}
			cout<<"break"<<endl;
		}|

		CONTINUE sm=SEMICOLON {
			if (inLoop==1){
				std::string message = "Line " + std::to_string($CONTINUE->getLine()) + ": statement : CONTINUE SEMICOLON";
				$unit_name = "continue ;";
				$line_number = $sm->getLine();
				message += "\n\n" + $unit_name;
				writeIntoparserLogFile(message, 2);
			}
			else { 
				std::string message = "Line " + std::to_string($CONTINUE->getLine()) + ": Continue outside loop";
				$unit_name = "continue ;";
				$line_number = $sm->getLine();
				message += "\n\n" + $unit_name;
				writeIntoparserLogFile(message, 2);
			}
			cout<<"continue"<<endl;
		} | 
		DO cs=compound_statement WHILE LPAREN expression RPAREN {
			$unit_name = "do" + $cs.unit_name + "while (" + $expression.var_name + ");";
			$line_number = $RPAREN->getLine();
			std::string message = "Line " + std::to_string($cs.line_number) + ": statement : DO LCURL statement RCURL WHILE LPAREN expression RPAREN";
			message += "\n\n" + $unit_name;
			cout<< "DO "<<endl;
			writeIntoparserLogFile(message, 2);
		}
	  ;
	  
expression_statement returns [std::string unit_name, int line_number]
			: SEMICOLON	{
			std::string message = "Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON";
			$unit_name = ";";
			$line_number = $SEMICOLON->getLine();
			message += "\n\n" + $unit_name;
			writeIntoparserLogFile(message, 2);
		}
		| expression SEMICOLON {
			std::string message = "Line " + std::to_string($expression.line_number) + ": expression_statement : expression SEMICOLON";
			$unit_name = $expression.var_name + ";";
			$line_number = $expression.line_number;
			message += "\n\n" + $unit_name ;
			writeIntoparserLogFile(message, 2);
		}
			;

variable returns [std::string var_name, int line_number, std::string trueName, bool indexed=false]
		: ID 		{
			std::string message = "Line " + std::to_string($ID->getLine()) + ": variable : ID";
			symbolInfo* sinfo = getVarType($ID->getText());
			if (sinfo == nullptr) {
				std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText();
				writeIntoErrorFile(errMsg);
				message += "\n\n" + errMsg;
				syntaxErrorCount++;
				currentIndex = "";
			} else if(sinfo->getIsArray()){
				currentIndex = sinfo->getType();
				std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Type mismatch, " + $ID->getText() + " is an array";
				writeIntoErrorFile(errMsg);
				message += "\n\n" + errMsg;
				syntaxErrorCount++;
			}
			$var_name = $ID->getText();
			$line_number = $ID->getLine();
			$trueName = $ID->getText();
			message += "\n\n" + $ID->getText();
			writeIntoparserLogFile(message, 2);
			$indexed = false; // not indexed by default

		}
	 | ID LTHIRD expression RTHIRD {
			std::string message = "Line " + std::to_string($ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD";
			$var_name = $ID->getText() + "[" + $expression.var_name + "]";
			$trueName = $ID->getText() ;
			symbolInfo* sinfo = getVarType($ID->getText());

			$line_number = $ID->getLine();
			if (sinfo != nullptr) {
				if (!sinfo->getIsArray()){
					 currentIndex = "";
					std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": "+ $ID->getText() + " not an array";
					writeIntoErrorFile(errMsg);
					message += "\n\n" + errMsg;
					syntaxErrorCount++;
				} else {
					
					if (currentIndex == "CONST_FLOAT") {
						std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Expression inside third brackets not an integer";
						writeIntoErrorFile(errMsg);
						message += "\n\n" + errMsg;
						syntaxErrorCount++;
					}
				}
			}

			$indexed = true; // indexed
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	 ;
	 
 expression returns [std::string var_name, int line_number] 
 		: logic_expression	{ 
			$var_name = $logic_expression.var_name;
			$line_number = $logic_expression.line_number;
			std::string message = "Line " + std::to_string($logic_expression.line_number) + ": expression : logic_expression";
			message += "\n\n" + $logic_expression.var_name;
			writeIntoparserLogFile(message, 2);
		}
	   | variable ASSIGNOP logic_expression 	{ 
			std::string ctype = $logic_expression.type;
			bool indexed = $variable.indexed;
			$var_name = $variable.var_name + $ASSIGNOP->getText() + $logic_expression.var_name;
			std::string trueName = $variable.trueName;
			$line_number = $variable.line_number;
			symbolInfo* sinfo = getVarType($variable.trueName);
			std::string var_type= sinfo ? sinfo->getType() : "";
			bool isArray = sinfo ? sinfo->getIsArray() : false;
			// cout<< "variable type is "<< var_type << "for variable " << $variable.var_name << endl;
			// cout<< "is array: " << (isArray ? "true" : "false") << endl;
			// cout<<" current type is: " << currentIndex << endl;
			// cout<< "current index is: " << indexed << endl;

			std::string message = "Line " + std::to_string($variable.line_number) + ": expression : variable ASSIGNOP logic_expression";
			if (ctype == "VOID") {
				std::string errMsg = "Error at line " + std::to_string($logic_expression.line_number) + ": Void function used in expression";
				writeIntoErrorFile(errMsg);
				message += "\n\n" + errMsg;
				syntaxErrorCount++;
				currentType = "";
			}

			else if  (sinfo!=nullptr ){
			if (var_type == "INT" && (currentIndex == "CONST_FLOAT"||currentIndex == "FLOAT")) {
				if (!isArray) {
					std::string errMsg = "Error at line " + std::to_string($variable.line_number) + ": Type Mismatch";
					writeIntoErrorFile(errMsg);
					syntaxErrorCount++;
					currentType = "";
					message += "\n\n" + errMsg;
				}
				else if (!indexed) {

					std::string errMsg = "Error at line " + std::to_string($variable.line_number) + ": Type Mismatch, "+ trueName + " is an array";
					writeIntoErrorFile(errMsg);
					syntaxErrorCount++;
					message += "\n\n" + errMsg;
				}
				else{
					std::string errMsg = "Error at line " + std::to_string($variable.line_number) + ": Type Mismatch";
					writeIntoErrorFile(errMsg);
					syntaxErrorCount++;
					message += "\n\n" + errMsg;
				}
			} else if (var_type == "FLOAT" && (currentIndex == "CONST_INT"||currentIndex == "INT") ) {
				if (!isArray) {
					// std::string errMsg = "Error at line " + std::to_string($variable.line_number) + ": Type Mismatch";
					// writeIntoErrorFile(errMsg);
					// syntaxErrorCount++;
					currentType="";
					// message += "\n\n" + errMsg;
				}
				else if (!indexed) {
					std::string errMsg = "Error at line " + std::to_string($variable.line_number) + ": Type Mismatch, "+ trueName + " is an array";
					writeIntoErrorFile(errMsg);
					syntaxErrorCount++;
					message += "\n\n" + errMsg;
				}
			}
			
		}
			

			message += "\n\n" + $var_name ;
			writeIntoparserLogFile(message, 2);
	}
	;
			
logic_expression returns [std::string var_name, int line_number, std::string type]
		: rel_expression {
			$var_name = $rel_expression.var_name;
			$line_number = $rel_expression.line_number;
			$type = $rel_expression.type;
			std::string message = "Line " + std::to_string($rel_expression.line_number) + ": logic_expression : rel_expression";
			message += "\n\n" + $rel_expression.var_name;
			writeIntoparserLogFile(message, 2);
		} 	
		 | rl=rel_expression LOGICOP rel_expression {
			$var_name = $rl.var_name + $LOGICOP->getText() + $rel_expression.var_name;
			$line_number = $rl.line_number;
			std::string message = "Line " + std::to_string($rl.line_number) + ": logic_expression : rel_expression LOGICOP rel_expression";
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}	
		 ;

rel_expression returns [ std::string var_name, int line_number, std::string type]
		: simple_expression {
			$var_name = $simple_expression.var_name;
			$line_number = $simple_expression.line_number;
			$type = $simple_expression.type;
			std::string message = "Line " + std::to_string($simple_expression.line_number) + ": rel_expression : simple_expression";
			message += "\n\n" + $simple_expression.var_name;
			writeIntoparserLogFile(message, 2);	
		}
		| sl1=simple_expression RELOP sl2=simple_expression {
			$var_name = $sl1.var_name + $RELOP->getText() + $sl2.var_name;
			$line_number = $sl1.line_number;
			std::string message = "Line " + std::to_string($sl2.line_number) + ": rel_expression : simple_expression RELOP simple_expression";
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
		;
				
simple_expression returns [std::string var_name, int line_number, std::string type] 
		: term {
			std::string message = "Line " + std::to_string($term.line_number) + ": simple_expression : term";
			$var_name = $term.var_name;
			$line_number = $term.line_number;
			$type = $term.type;
			message += "\n\n" + $term.var_name;
			writeIntoparserLogFile(message, 2);
		}
		  | se=simple_expression ADDOP term { 
			std::string message = "Line " + std::to_string($term.line_number) + ": simple_expression : simple_expression ADDOP term";
			$var_name = $se.var_name + $ADDOP->getText() + $term.var_name;
			$line_number = $term.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
		  ;

term returns [std::string var_name, int line_number, std::string type]
	:	unary_expression{
			std::string message = "Line " + std::to_string($unary_expression.line_number) + ": term : unary_expression";
			$var_name = $unary_expression.var_name;
			$line_number = $unary_expression.line_number;
			$type = $unary_expression.type;
			message += "\n\n" + $unary_expression.var_name;
			writeIntoparserLogFile(message, 2);
		} 
     |  tm=term MULOP unary_expression {
			// cout<<"mulop unary "<<  $MULOP->getText()<< endl;
			std::string message = "Line " + std::to_string($unary_expression.line_number) + ": term : term MULOP unary_expression";
			if ($unary_expression.type == "VOID") {
				std::string errMsg = "Error at line " + std::to_string($unary_expression.line_number) + ": Void function used in expression";
				writeIntoErrorFile(errMsg);
				syntaxErrorCount++;

				message = message + "\n\n" + errMsg;
				currentIndex = "";
			}
			if (currentIndex=="CONST_FLOAT" && $unary_expression.var_name != "0"){
				std::string errMsg = "Error at line " + std::to_string($unary_expression.line_number) + ": Non-Integer operand on modulus operator";
				writeIntoErrorFile(errMsg);
				syntaxErrorCount++;
				message= message + "\n\n" + errMsg;
				currentIndex = "";
			}
			if ($MULOP->getText() == "%" && $unary_expression.var_name == "0") {
				std::string errMsg = "Error at line " + std::to_string($unary_expression.line_number) + ": Modulus by Zero";
				writeIntoErrorFile(errMsg);
				syntaxErrorCount++;
				message= message + "\n\n" + errMsg;
				currentIndex = "";
			}
			$var_name = $tm.var_name + $MULOP->getText() + $unary_expression.var_name;
			$line_number = $unary_expression.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
     ;

unary_expression returns [std::string var_name, int line_number, std::string type]
		 : ADDOP unary_expression  {
			std::string message = "Line " + std::to_string($unary_expression.line_number) + ": unary_expression : ADDOP unary_expression";
			$var_name = $ADDOP->getText() + $unary_expression.var_name;
			$line_number = $unary_expression.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
		 | NOT unary_expression  {
			std::string message = "Line " + std::to_string($unary_expression.line_number) + ": unary_expression : NOT unary_expression";
			$var_name = $NOT->getText() + $unary_expression.var_name;
			$line_number = $unary_expression.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
		 | factor {
			std::string message = "Line " + std::to_string($factor.line_number) + ": unary_expression : factor";
			$var_name = $factor.var_name;
			$type = $factor.type;
			$line_number = $factor.line_number;
			message += "\n\n" + $factor.var_name;
			writeIntoparserLogFile(message, 2);
		}
		 ;
	
factor returns [std::string var_name, int line_number, std:: string type]
	: variable {
			std::string message = "Line " + std::to_string($variable.line_number) + ": factor : variable";
			message += "\n\n" + $variable.var_name;
			$var_name = $variable.var_name;
			$line_number = $variable.line_number;
			writeIntoparserLogFile(message, 2);
		}
	| ID LPAREN argument_list RPAREN {
			std::string message = "Line " + std::to_string($ID->getLine()) + ": factor : ID LPAREN argument_list RPAREN";
			std::string var_name = $ID->getText() + "(" + $argument_list.name_line + ")";

			symbolInfo* sinfo = getVarType($ID->getText());
			std::string currentType = sinfo ? sinfo->getType() : "";
			$type = currentType;
			if (sinfo == nullptr) {
				std::string errMsg = "Error at line " + std::to_string($ID->getLine()) + ": Undefined function " + $ID->getText();
				writeIntoErrorFile(errMsg);
				message += "\n\n" + errMsg;
				syntaxErrorCount++;
				currentIndex = "";
			}

			$var_name = $ID->getText() + "(" + $argument_list.name_line + ")";
			$line_number = $ID->getLine();
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	| LPAREN expression RPAREN {
			std::string message = "Line " + std::to_string($expression.line_number) + ": factor : LPAREN expression RPAREN";
			$var_name = "(" + $expression.var_name + ")";
			$line_number = $expression.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	| CONST_INT {
			std::string message = "Line " + std::to_string($CONST_INT->getLine()) + ": factor : CONST_INT";
			$var_name = $CONST_INT->getText();
			$line_number = $CONST_INT->getLine();
			currentIndex = "CONST_INT";
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	| CONST_FLOAT {
			std::string message = "Line " + std::to_string($CONST_FLOAT->getLine()) + ": factor : CONST_FLOAT";
			$var_name = $CONST_FLOAT->getText();
			$line_number = $CONST_FLOAT->getLine();
			message += "\n\n" + $var_name;
			currentIndex = "CONST_FLOAT";
			writeIntoparserLogFile(message, 2);
		}
	| variable INCOP {
			std::string message = "Line " + std::to_string($variable.line_number) + ": factor : variable INCOP";
			$var_name = $variable.var_name + $INCOP->getText();
			$line_number = $variable.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	| variable DECOP {
			std::string message = "Line " + std::to_string($variable.line_number) + ": factor : variable DECOP";
			$var_name = $variable.var_name + $DECOP->getText();
			$line_number = $variable.line_number;
			message += "\n\n" + $var_name;
			writeIntoparserLogFile(message, 2);
		}
	;
	
argument_list returns [std::string name_line, int line_number] 
			: arguments  {
			$name_line = $arguments.name_line;
			$line_number = $arguments.line_number;
			std::string message = "Line " + std::to_string($arguments.line_number) + ": argument_list : arguments";
			message += "\n\n" + $arguments.name_line;
			writeIntoparserLogFile(message, 2);
			}
			  |
			  ;

arguments returns [std::string name_line, int line_number]
		: ar=arguments COMMA logic_expression {
			$name_line = $ar.name_line + "," + $logic_expression.var_name;
			$line_number = $logic_expression.line_number;
			std::string message = "Line " + std::to_string($logic_expression.line_number) + ": arguments : arguments COMMA logic_expression";
			message += "\n\n" + $name_line;
			writeIntoparserLogFile(message, 2);
		}
	      | logic_expression {
			$name_line = $logic_expression.var_name;
			$line_number = $logic_expression.line_number;
			std::string message = "Line " + std::to_string($logic_expression.line_number) + ": arguments : logic_expression";
			message += "\n\n" + $name_line;
			writeIntoparserLogFile(message, 2);
		}
	      ;
