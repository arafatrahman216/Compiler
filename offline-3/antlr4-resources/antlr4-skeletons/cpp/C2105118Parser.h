
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


// Generated from C2105118Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105118Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33, HASH = 34, UNRECOGNIZED_CHAR = 35
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleParameter_list_err = 6, 
    RuleCompound_statement = 7, RuleVar_declaration = 8, RuleDeclaration_list_err = 9, 
    RuleType_specifier = 10, RuleDeclaration_list = 11, RuleStatements = 12, 
    RuleStatement = 13, RuleExpression_statement = 14, RuleVariable = 15, 
    RuleExpression = 16, RuleLogic_expression_err = 17, RuleLogic_expression = 18, 
    RuleRel_expression = 19, RuleSimple_expression = 20, RuleTerm = 21, 
    RuleUnary_expression = 22, RuleFactor = 23, RuleArgument_list = 24, 
    RuleArguments = 25
  };

  explicit C2105118Parser(antlr4::TokenStream *input);

  C2105118Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105118Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  	SymbolTable symbolTable; 
  	int func_def=0;
  	int stopargMismatch = 0;
  	std::string stopargMismatchName = "";
  	std::string currentIndex= "CONST_INT";
  	std::string currentType = "INT";
  	std:: string retType = "";
  	vector<std::string> currentParams;
  	vector<std::string> currentArgs;
  	

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

  	bool insertIntoSymbolTable(const std::string &name, const std::string &type, int line_number, vector<std::string> params, bool isArray=false, int isFunction=0, int func_params=0) {
  		bool insertSuccess = symbolTable.Insert(name, type, isArray, isFunction, params, parserLogFile);
  		if (!insertSuccess && isFunction == 0) {
  			std::string errMsg = "Error at line " + std::to_string(line_number) + ": Multiple declaration of " + name;
  			if (func_params > 0) {
  				errMsg += " in parameter";
  			}
  			writeIntoErrorFile(errMsg);
  			writeIntoparserLogFile(errMsg, 2);
  			syntaxErrorCount++;
  		}
  		return insertSuccess;

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


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Parameter_list_errContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expression_errContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C2105118Parser::ProgramContext *programContext = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    C2105118Parser::ProgramContext *pg = nullptr;
    C2105118Parser::UnitContext *unitContext = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    C2105118Parser::Var_declarationContext *vd = nullptr;
    C2105118Parser::Func_declarationContext *func_declarationContext = nullptr;
    C2105118Parser::Func_definitionContext *func_definitionContext = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    C2105118Parser::Type_specifierContext *type_specifierContext = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105118Parser::Parameter_listContext *parameter_listContext = nullptr;
    antlr4::Token *sm = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    C2105118Parser::Type_specifierContext *type_specifierContext = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105118Parser::Parameter_listContext *parameter_listContext = nullptr;
    C2105118Parser::Compound_statementContext *cs = nullptr;
    C2105118Parser::Parameter_list_errContext *parameter_list_errContext = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();
    Parameter_list_errContext *parameter_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    C2105118Parser::Parameter_listContext *pl = nullptr;
    C2105118Parser::Type_specifierContext *type_specifierContext = nullptr;
    antlr4::Token *idToken = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Parameter_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    C2105118Parser::Type_specifierContext *type_specifierContext = nullptr;
    antlr4::Token *addopToken = nullptr;
    Parameter_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_list_errContext* parameter_list_err();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    C2105118Parser::StatementsContext *statementsContext = nullptr;
    antlr4::Token *rcurlToken = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    C2105118Parser::Type_specifierContext *t = nullptr;
    C2105118Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    antlr4::Token *addopToken = nullptr;
    C2105118Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ID();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    int line_number;
    std::string type;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    C2105118Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *addopToken = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    bool retError = false;
    C2105118Parser::StatementsContext *sts = nullptr;
    C2105118Parser::StatementContext *statementContext = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    bool retError = false;
    C2105118Parser::Var_declarationContext *var_declarationContext = nullptr;
    C2105118Parser::Expression_statementContext *expression_statementContext = nullptr;
    C2105118Parser::Compound_statementContext *compound_statementContext = nullptr;
    C2105118Parser::Expression_statementContext *esa = nullptr;
    C2105118Parser::Expression_statementContext *esb = nullptr;
    C2105118Parser::ExpressionContext *expressionContext = nullptr;
    C2105118Parser::StatementContext *statementContext = nullptr;
    C2105118Parser::StatementContext *st = nullptr;
    C2105118Parser::StatementContext *s1 = nullptr;
    C2105118Parser::StatementContext *s2 = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *returnToken = nullptr;
    antlr4::Token *sm = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_name;
    int line_number;
    antlr4::Token *semicolonToken = nullptr;
    C2105118Parser::ExpressionContext *expressionContext = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string trueName;
    bool indexed = false;
    std::string type;
    antlr4::Token *idToken = nullptr;
    C2105118Parser::ExpressionContext *expressionContext = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    C2105118Parser::Logic_expressionContext *logic_expressionContext = nullptr;
    C2105118Parser::VariableContext *variableContext = nullptr;
    antlr4::Token *assignopToken = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Logic_expression_errContext *logic_expression_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expression_errContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    antlr4::Token *addopToken = nullptr;
    Logic_expression_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ASSIGNOP();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expression_errContext* logic_expression_err();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    C2105118Parser::Rel_expressionContext *rel_expressionContext = nullptr;
    C2105118Parser::Rel_expressionContext *rl = nullptr;
    antlr4::Token *logicopToken = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    C2105118Parser::Simple_expressionContext *simple_expressionContext = nullptr;
    C2105118Parser::Simple_expressionContext *sl1 = nullptr;
    antlr4::Token *relopToken = nullptr;
    C2105118Parser::Simple_expressionContext *sl2 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    std::string err;
    C2105118Parser::Simple_expressionContext *se = nullptr;
    C2105118Parser::TermContext *termContext = nullptr;
    antlr4::Token *hashToken = nullptr;
    antlr4::Token *addopToken = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *HASH();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    C2105118Parser::TermContext *tm = nullptr;
    C2105118Parser::Unary_expressionContext *unary_expressionContext = nullptr;
    antlr4::Token *mulopToken = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std::string type;
    antlr4::Token *addopToken = nullptr;
    C2105118Parser::Unary_expressionContext *ue = nullptr;
    antlr4::Token *notToken = nullptr;
    C2105118Parser::Unary_expressionContext *unary_expressionContext = nullptr;
    C2105118Parser::FactorContext *factorContext = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    int line_number;
    std:: string type;
    C2105118Parser::VariableContext *variableContext = nullptr;
    antlr4::Token *idToken = nullptr;
    C2105118Parser::Argument_listContext *argument_listContext = nullptr;
    C2105118Parser::ExpressionContext *expressionContext = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *const_floatToken = nullptr;
    antlr4::Token *incopToken = nullptr;
    antlr4::Token *decopToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    int line_number;
    C2105118Parser::ArgumentsContext *argumentsContext = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    int line_number;
    C2105118Parser::ArgumentsContext *ar = nullptr;
    C2105118Parser::Logic_expressionContext *logic_expressionContext = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

