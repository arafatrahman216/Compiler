// Generated from /home/arafat219/cmplr/offline-3/ONLINE/C2105118Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C2105118Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, DO=14, BREAK=15, 
		CONTINUE=16, LPAREN=17, RPAREN=18, LCURL=19, RCURL=20, LTHIRD=21, RTHIRD=22, 
		SEMICOLON=23, COMMA=24, ADDOP=25, SUBOP=26, MULOP=27, INCOP=28, DECOP=29, 
		NOT=30, RELOP=31, LOGICOP=32, ASSIGNOP=33, ID=34, CONST_INT=35, CONST_FLOAT=36;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_declaration_list_err = 8, RULE_type_specifier = 9, 
		RULE_declaration_list = 10, RULE_statements = 11, RULE_statement = 12, 
		RULE_expression_statement = 13, RULE_variable = 14, RULE_expression = 15, 
		RULE_logic_expression = 16, RULE_rel_expression = 17, RULE_simple_expression = 18, 
		RULE_term = 19, RULE_unary_expression = 20, RULE_factor = 21, RULE_argument_list = 22, 
		RULE_arguments = 23;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "declaration_list_err", "type_specifier", 
			"declaration_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'printf'", 
			"'return'", "'int'", "'float'", "'void'", "'do'", "'break'", "'continue'", 
			"'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", null, null, null, 
			"'++'", "'--'", "'!'", null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "DO", "BREAK", 
			"CONTINUE", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", 
			"SEMICOLON", "COMMA", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", 
			"RELOP", "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C2105118Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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

	public C2105118Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext program;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			((StartContext)_localctx).program = program(0);

					std::string message = "Line "+ std::to_string(((StartContext)_localctx).program.line_number) + ": start : program\n\n";
					writeIntoparserLogFile(message, 0);
					printSymbolTable();
					message="";
					message += "Total number of lines: " + std::to_string(((StartContext)_localctx).program.line_number) + "\n";
					message += "Total number of errors: " + std::to_string(syntaxErrorCount) + "\n";
					writeIntoparserLogFile(message, 0);
				
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public ProgramContext pg;
		public UnitContext unit;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(52);
			((ProgramContext)_localctx).unit = unit();

					std:: string message = "Line " + std::to_string(((ProgramContext)_localctx).unit.line_number) + ": program : unit";
					message += "\n\n" + ((ProgramContext)_localctx).unit.unit_name;
					((ProgramContext)_localctx).unit_name =  ((ProgramContext)_localctx).unit.unit_name;
					((ProgramContext)_localctx).line_number =  ((ProgramContext)_localctx).unit.line_number;
					writeIntoparserLogFile(message, 2);
				
			}
			_ctx.stop = _input.LT(-1);
			setState(61);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.pg = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(55);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(56);
					((ProgramContext)_localctx).unit = unit();

					          			std::string message = "Line " + std::to_string(((ProgramContext)_localctx).unit.line_number) + ": program : program unit";
					          		((ProgramContext)_localctx).unit_name =  ((ProgramContext)_localctx).pg.unit_name + "\n" + ((ProgramContext)_localctx).unit.unit_name;
					          		((ProgramContext)_localctx).line_number =  ((ProgramContext)_localctx).unit.line_number;
					          		message += "\n\n" + _localctx.unit_name ;
					          		writeIntoparserLogFile(message, 2);
					          	
					}
					} 
				}
				setState(63);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public Var_declarationContext vd;
		public Func_declarationContext func_declaration;
		public Func_definitionContext func_definition;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(73);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(64);
				((UnitContext)_localctx).vd = var_declaration();

						std::string message = "Line " + std::to_string(((UnitContext)_localctx).vd.line_number) + ": unit : var_declaration";
						message += "\n\n" + ((UnitContext)_localctx).vd.var_name;
						((UnitContext)_localctx).unit_name =  ((UnitContext)_localctx).vd.var_name ;
						((UnitContext)_localctx).line_number =  ((UnitContext)_localctx).vd.line_number;
						writeIntoparserLogFile(message, 2);
					
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(67);
				((UnitContext)_localctx).func_declaration = func_declaration();

						std::string message = "Line " + std::to_string(((UnitContext)_localctx).func_declaration.line_number) + ": unit : func_declaration";
						message += "\n\n" + ((UnitContext)_localctx).func_declaration.unit_name ;
						((UnitContext)_localctx).unit_name =  ((UnitContext)_localctx).func_declaration.unit_name;
						((UnitContext)_localctx).line_number =  ((UnitContext)_localctx).func_declaration.line_number;
						writeIntoparserLogFile(message, 2);
					
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(70);
				((UnitContext)_localctx).func_definition = func_definition();

						std::string message = "Line " + std::to_string(((UnitContext)_localctx).func_definition.line_number) + ": unit : func_definition";
						message += "\n\n" + ((UnitContext)_localctx).func_definition.unit_name ;
						((UnitContext)_localctx).unit_name =  ((UnitContext)_localctx).func_definition.unit_name;
						((UnitContext)_localctx).line_number =  ((UnitContext)_localctx).func_definition.line_number;
						writeIntoparserLogFile(message, 2);
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public Type_specifierContext type_specifier;
		public Token ID;
		public Parameter_listContext parameter_list;
		public Token sm;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105118Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105118Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105118Parser.SEMICOLON, 0); }
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(90);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(75);
				((Func_declarationContext)_localctx).type_specifier = type_specifier();
				setState(76);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(77);
				match(LPAREN);
				setState(78);
				((Func_declarationContext)_localctx).parameter_list = parameter_list(0);
				setState(79);
				match(RPAREN);
				setState(80);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

							std::string var_type = ((Func_declarationContext)_localctx).type_specifier.type;
							insertIntoSymbolTable(((Func_declarationContext)_localctx).ID->getText(), var_type, ((Func_declarationContext)_localctx).ID->getLine(),false, 1);
						std::string message = "Line " + std::to_string(((Func_declarationContext)_localctx).sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
						message += "\n\n" + ((Func_declarationContext)_localctx).type_specifier.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "(" + ((Func_declarationContext)_localctx).parameter_list.name_line + ");";
						writeIntoparserLogFile(message, 2);
						((Func_declarationContext)_localctx).unit_name =  ((Func_declarationContext)_localctx).type_specifier.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "(" + ((Func_declarationContext)_localctx).parameter_list.name_line + ");";
						((Func_declarationContext)_localctx).line_number =  ((Func_declarationContext)_localctx).ID->getLine();

						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(83);
				((Func_declarationContext)_localctx).type_specifier = type_specifier();
				setState(84);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(85);
				match(LPAREN);
				setState(86);
				match(RPAREN);
				setState(87);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

							std::string var_type = ((Func_declarationContext)_localctx).type_specifier.type;
							insertIntoSymbolTable(((Func_declarationContext)_localctx).ID->getText(), var_type, ((Func_declarationContext)_localctx).ID->getLine(),false, 1);
							std::string message = "Line " + std::to_string(((Func_declarationContext)_localctx).sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
							message += "\n\n" + ((Func_declarationContext)_localctx).type_specifier.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "();";
							writeIntoparserLogFile(message, 2);
							((Func_declarationContext)_localctx).unit_name =  ((Func_declarationContext)_localctx).type_specifier.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "();";
							((Func_declarationContext)_localctx).line_number =  ((Func_declarationContext)_localctx).ID->getLine();
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public Type_specifierContext type_specifier;
		public Token ID;
		public Parameter_listContext parameter_list;
		public Compound_statementContext cs;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105118Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105118Parser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(112);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(92);
				((Func_definitionContext)_localctx).type_specifier = type_specifier();
				setState(93);
				((Func_definitionContext)_localctx).ID = match(ID);
							
							std::string var_type = ((Func_definitionContext)_localctx).type_specifier.type;
							// cout<< "var_type is: " << var_type << endl;
							retType = var_type;
							cout<< "retType is: " << retType << endl;
							
							insertIntoSymbolTable(((Func_definitionContext)_localctx).ID->getText(), var_type, ((Func_definitionContext)_localctx).ID->getLine(),false, 1);
						
				setState(95);
				match(LPAREN);

								func_def=1;
								enterScope();
							
				setState(97);
				((Func_definitionContext)_localctx).parameter_list = parameter_list(0);


								symbolInfo* sinfo = getVarType(((Func_definitionContext)_localctx).ID->getText());
								int isFunction = sinfo ? sinfo->getIsFunction() : 1;
								if (isFunction == 0){
									std::string errMsg = "Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText();
									writeIntoErrorFile(errMsg);
									writeIntoparserLogFile(errMsg, 2);
									syntaxErrorCount++;
								}
								if (sinfo != nullptr && sinfo->getType() != var_type) {
									std::string errMsg = "Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).ID->getText();
									writeIntoErrorFile(errMsg);
									writeIntoparserLogFile(errMsg, 2);
									syntaxErrorCount++;
							}
								
								
				setState(99);
				match(RPAREN);
				setState(100);
				((Func_definitionContext)_localctx).cs = compound_statement();

							// cout<< "type_specifier is: " << ((Func_definitionContext)_localctx).type_specifier.name_line << endl;
							((Func_definitionContext)_localctx).unit_name =  ((Func_definitionContext)_localctx).type_specifier.name_line + " " + ((Func_definitionContext)_localctx).ID->getText() + "(" + ((Func_definitionContext)_localctx).parameter_list.name_line + ")" + ((Func_definitionContext)_localctx).cs.unit_name ;
							((Func_definitionContext)_localctx).line_number =  ((Func_definitionContext)_localctx).cs.line_number;
							std::string message = "Line " + std::to_string(((Func_definitionContext)_localctx).cs.line_number) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
							retType = "";
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				((Func_definitionContext)_localctx).type_specifier = type_specifier();
				setState(104);
				((Func_definitionContext)_localctx).ID = match(ID);

						std::string var_type = ((Func_definitionContext)_localctx).type_specifier.type;
						// cout<< "var_type is: " << var_type << endl;
						retType = var_type;
						cout<< "retType is: " << retType << endl;
							insertIntoSymbolTable(((Func_definitionContext)_localctx).ID->getText(), var_type, ((Func_definitionContext)_localctx).ID->getLine(),false, 1);
						
				setState(106);
				match(LPAREN);

								func_def=1;
								enterScope();	
						
				setState(108);
				match(RPAREN);
				setState(109);
				((Func_definitionContext)_localctx).cs = compound_statement();

							// cout<< "type_specifier is: " << ((Func_definitionContext)_localctx).type_specifier.name_line << endl;
							((Func_definitionContext)_localctx).unit_name =  ((Func_definitionContext)_localctx).type_specifier.name_line + " " + ((Func_definitionContext)_localctx).ID->getText() + "()" + ((Func_definitionContext)_localctx).cs.unit_name;
							((Func_definitionContext)_localctx).line_number =  ((Func_definitionContext)_localctx).cs.line_number;
							std::string message = "Line " + std::to_string(((Func_definitionContext)_localctx).cs.line_number) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement";
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public std::string name_line;
		public Parameter_listContext pl;
		public Type_specifierContext type_specifier;
		public Token ID;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode COMMA() { return getToken(C2105118Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(122);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(115);
				((Parameter_listContext)_localctx).type_specifier = type_specifier();
				setState(116);
				((Parameter_listContext)_localctx).ID = match(ID);

					// cout<< "func_def is: "<< func_def <<endl;

					currentParams.push_back(((Parameter_listContext)_localctx).ID->getText());
					cout<< "size is : " << currentParams.size() << endl;
					std::string var_type = ((Parameter_listContext)_localctx).type_specifier.type;
					if (func_def==1) {
						insertIntoSymbolTable(((Parameter_listContext)_localctx).ID->getText(), var_type, ((Parameter_listContext)_localctx).ID->getLine(), false, 0,1);
					}
					((Parameter_listContext)_localctx).name_line =  ((Parameter_listContext)_localctx).type_specifier.name_line + " " + ((Parameter_listContext)_localctx).ID->getText();
					std::string message = "Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": parameter_list : type_specifier ID";
					message += "\n\n" + _localctx.name_line;
					writeIntoparserLogFile(message, 2);
					
				}
				break;
			case 2:
				{
				setState(119);
				((Parameter_listContext)_localctx).type_specifier = type_specifier();

						((Parameter_listContext)_localctx).name_line =  ((Parameter_listContext)_localctx).type_specifier.name_line;
						std::string message = "Line " + std::to_string(((Parameter_listContext)_localctx).type_specifier.line_number) + ": parameter_list : type_specifier";
						message += "\n\n" + ((Parameter_listContext)_localctx).type_specifier.name_line;
						writeIntoparserLogFile(message, 2);
					
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(137);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(135);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(124);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(125);
						match(COMMA);
						setState(126);
						((Parameter_listContext)_localctx).type_specifier = type_specifier();
						setState(127);
						((Parameter_listContext)_localctx).ID = match(ID);

						          	// cout<< "func_def is: "<< func_def <<endl;
						          	std::string var_type = ((Parameter_listContext)_localctx).type_specifier.type;
						          	currentParams.push_back(((Parameter_listContext)_localctx).ID->getText());
						          	if (func_def==1) {
						          		insertIntoSymbolTable(((Parameter_listContext)_localctx).ID->getText(), var_type, ((Parameter_listContext)_localctx).ID->getLine(), false, 0,1);
						          	}
						          	// cout<<"Inserting into symbol table: "<< ((Parameter_listContext)_localctx).ID->getText() <<"while func_def is"<<func_def<<endl;
						          	((Parameter_listContext)_localctx).name_line =  ((Parameter_listContext)_localctx).pl.name_line + "," + ((Parameter_listContext)_localctx).type_specifier.name_line + " " + ((Parameter_listContext)_localctx).ID->getText();
						          	std::string message = "Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID";
						          	message += "\n\n" + _localctx.name_line;
						          	writeIntoparserLogFile(message, 2);
						          	
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(130);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(131);
						match(COMMA);
						setState(132);
						((Parameter_listContext)_localctx).type_specifier = type_specifier();

						          	((Parameter_listContext)_localctx).name_line =  ((Parameter_listContext)_localctx).pl.name_line + ", " + ((Parameter_listContext)_localctx).type_specifier.name_line;
						          	std::string message = "Line " + std::to_string(((Parameter_listContext)_localctx).type_specifier.line_number) + ": parameter_list : parameter_list COMMA type_specifier";
						          	message += "\n\n" + _localctx.name_line;
						          	writeIntoparserLogFile(message, 2);
						          	
						}
						break;
					}
					} 
				}
				setState(139);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public StatementsContext statements;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C2105118Parser.LCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode RCURL() { return getToken(C2105118Parser.RCURL, 0); }
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(150);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(140);
				match(LCURL);

								if (func_def==1) func_def=0;
								else enterScope();
							
				setState(142);
				((Compound_statementContext)_localctx).statements = statements(0);
				setState(143);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

								std::string message = "Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL statements RCURL";
								((Compound_statementContext)_localctx).unit_name =  "{\n" + ((Compound_statementContext)_localctx).statements.unit_name + "\n}";
								((Compound_statementContext)_localctx).line_number =  ((Compound_statementContext)_localctx).RCURL->getLine();
								message += "\n\n" + _localctx.unit_name;
								writeIntoparserLogFile(message, 2);
								exitScope();

								if (((Compound_statementContext)_localctx).statements.retError) {
									std::string errMsg = "Error at line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": Cannot return value from function foo4 with void return type";
									writeIntoErrorFile(errMsg);
									message = errMsg;
									writeIntoparserLogFile(message, 2);
									syntaxErrorCount++	;
								}
								if (inLoop == 1) {
									inLoop = 0;
								}
							
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(146);
				match(LCURL);

								if (func_def==1) func_def=0;
								else enterScope();
							
				setState(148);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);
				 
								func_def=0;
								std::string message = "Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL RCURL";
								((Compound_statementContext)_localctx).unit_name =  "{\n}";
								((Compound_statementContext)_localctx).line_number =  ((Compound_statementContext)_localctx).RCURL->getLine();
								message += "\n\n" + _localctx.unit_name;
								writeIntoparserLogFile(message, 2);
								exitScope();
								if (inLoop == 1) {
									inLoop = 0;
								}

							
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Token ASSIGNOP;
		public Logic_expressionContext logic_expression;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105118Parser.SEMICOLON, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C2105118Parser.ASSIGNOP, 0); }
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			setState(169);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(152);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(153);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(154);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

						std::string var = ((Var_declarationContext)_localctx).t.name_line + " " + ((Var_declarationContext)_localctx).dl.name_line + ";";
						std::string message = "Line "+ std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON";
						if (((Var_declarationContext)_localctx).t.type == "VOID") {
							std::string errMsg = "Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void";
							writeIntoErrorFile(errMsg);
							message += "\n\n" + errMsg;
							syntaxErrorCount++;
						}
						message += "\n\n" + var; 
						((Var_declarationContext)_localctx).var_name =  var;
						((Var_declarationContext)_localctx).line_number =  ((Var_declarationContext)_localctx).sm->getLine();
						writeIntoparserLogFile(message, 2);
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(157);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(158);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(159);
				((Var_declarationContext)_localctx).ASSIGNOP = match(ASSIGNOP);
				setState(160);
				((Var_declarationContext)_localctx).logic_expression = logic_expression();
				setState(161);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

						std::string var = ((Var_declarationContext)_localctx).t.name_line + " " + ((Var_declarationContext)_localctx).dl.name_line + ((Var_declarationContext)_localctx).ASSIGNOP->getText() + ((Var_declarationContext)_localctx).logic_expression.var_name + ";";
						std::string message = "Line "+ std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON";
						message += "\n\n" + var; 
						((Var_declarationContext)_localctx).var_name =  var;
						((Var_declarationContext)_localctx).line_number =  ((Var_declarationContext)_localctx).sm->getLine();
						writeIntoparserLogFile(message, 2);
				      
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(164);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(165);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(166);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        writeIntoErrorFile(
				            std::string("Line# ") + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) +
				            " with error name: " + ((Var_declarationContext)_localctx).de.error_name +
				            " - Syntax error at declaration list of variable declaration"
				        );

				        syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public std::string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
					cout << "Error in declaration list" << endl;
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public std::string name_line;
		public int line_number;
		public std::string type;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C2105118Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C2105118Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C2105118Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(179);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(173);
				((Type_specifierContext)_localctx).INT = match(INT);

							((Type_specifierContext)_localctx).name_line =  "int";
							((Type_specifierContext)_localctx).line_number =  ((Type_specifierContext)_localctx).INT->getLine();
							((Type_specifierContext)_localctx).type =  "INT";
							currentType = "INT";
							std::string message = "Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT"+ "\n\n" + ((Type_specifierContext)_localctx).INT->getText();
							writeIntoparserLogFile(message,2);
						
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				            ((Type_specifierContext)_localctx).name_line =  "float";
							((Type_specifierContext)_localctx).line_number =  ((Type_specifierContext)_localctx).FLOAT->getLine();
							((Type_specifierContext)_localctx).type =  "FLOAT";
							currentType = "FLOAT";
							std::string message = "Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT"+ "\n\n" + ((Type_specifierContext)_localctx).FLOAT->getText();
							writeIntoparserLogFile(message,2);
				        
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(177);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				            ((Type_specifierContext)_localctx).name_line =  "void";
							((Type_specifierContext)_localctx).line_number =  ((Type_specifierContext)_localctx).VOID->getLine();
							((Type_specifierContext)_localctx).type =  "VOID";
							currentType = "VOID";
							std::string message = "Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID"+ "\n\n" + ((Type_specifierContext)_localctx).VOID->getText();
							writeIntoparserLogFile(message,2);
				        
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public std::string name_line;
		public Declaration_listContext dl;
		public Token ID;
		public Token CONST_INT;
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105118Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C2105118Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105118Parser.RTHIRD, 0); }
		public TerminalNode COMMA() { return getToken(C2105118Parser.COMMA, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(189);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(182);
				((Declaration_listContext)_localctx).ID = match(ID);

							((Declaration_listContext)_localctx).name_line =  ((Declaration_listContext)_localctx).ID->getText() ;
							std::string message = "Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID"+ "\n\n" + ((Declaration_listContext)_localctx).ID->getText();
							insertIntoSymbolTable(((Declaration_listContext)_localctx).ID->getText(), currentType, ((Declaration_listContext)_localctx).ID->getLine(), false,0);
							writeIntoparserLogFile(message,2);
						  
				}
				break;
			case 2:
				{
				setState(184);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(185);
				match(LTHIRD);
				setState(186);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(187);
				match(RTHIRD);

							((Declaration_listContext)_localctx).name_line =  ((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]";
							std::string message = "Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx.name_line;
							insertIntoSymbolTable(((Declaration_listContext)_localctx).ID->getText(), currentType, ((Declaration_listContext)_localctx).ID->getLine(), true,0);
							writeIntoparserLogFile(message,2);
						  
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(204);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(202);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(191);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(192);
						match(COMMA);
						setState(193);
						((Declaration_listContext)_localctx).ID = match(ID);

						          			((Declaration_listContext)_localctx).name_line =  ((Declaration_listContext)_localctx).dl.name_line +"," + ((Declaration_listContext)_localctx).ID->getText();
						          			std::string message = "Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID"+ "\n\n" + _localctx.name_line;
						          			insertIntoSymbolTable(((Declaration_listContext)_localctx).ID->getText(), currentType, ((Declaration_listContext)_localctx).ID->getLine(), false,0);
						          			writeIntoparserLogFile(message,2);
						          			
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(195);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(196);
						match(COMMA);
						setState(197);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(198);
						match(LTHIRD);
						setState(199);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(200);
						match(RTHIRD);

						          			((Declaration_listContext)_localctx).name_line =  ((Declaration_listContext)_localctx).dl.name_line + "," + ((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]";
						          			std::string message = "Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx.name_line;
						          			insertIntoSymbolTable(((Declaration_listContext)_localctx).ID->getText(), currentType, ((Declaration_listContext)_localctx).ID->getLine(), true);
						          			writeIntoparserLogFile(message,2);
						          		  
						}
						break;
					}
					} 
				}
				setState(206);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public bool retError = false;
		public StatementsContext sts;
		public StatementContext statement;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(208);
			((StatementsContext)_localctx).statement = statement();

						((StatementsContext)_localctx).unit_name =  ((StatementsContext)_localctx).statement.unit_name;
						((StatementsContext)_localctx).line_number =  ((StatementsContext)_localctx).statement.line_number;
						((StatementsContext)_localctx).retError =  ((StatementsContext)_localctx).statement.retError;
						std::string message = "Line " + std::to_string(((StatementsContext)_localctx).statement.line_number) + ": statements : statement";
						message += "\n\n" + _localctx.unit_name;
						writeIntoparserLogFile(message, 2);
					
			}
			_ctx.stop = _input.LT(-1);
			setState(217);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.sts = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(211);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(212);
					((StatementsContext)_localctx).statement = statement();

					          			((StatementsContext)_localctx).unit_name =  ((StatementsContext)_localctx).sts.unit_name + "\n" + ((StatementsContext)_localctx).statement.unit_name;
					          			((StatementsContext)_localctx).line_number =  ((StatementsContext)_localctx).statement.line_number;
					          			std::string message = "Line " + std::to_string(((StatementsContext)_localctx).statement.line_number) + ": statements : statements statement";
					          			message += "\n\n" + _localctx.unit_name;
					          			writeIntoparserLogFile(message, 2);
					          		
					}
					} 
				}
				setState(219);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public bool retError = false;
		public Var_declarationContext var_declaration;
		public Expression_statementContext expression_statement;
		public Compound_statementContext compound_statement;
		public Expression_statementContext esa;
		public Expression_statementContext esb;
		public ExpressionContext expression;
		public StatementContext statement;
		public StatementContext st;
		public StatementContext s1;
		public StatementContext s2;
		public Token ID;
		public Token RETURN;
		public Token sm;
		public Token BREAK;
		public Token CONTINUE;
		public Compound_statementContext cs;
		public Token RPAREN;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C2105118Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C2105118Parser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105118Parser.RPAREN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C2105118Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C2105118Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C2105118Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C2105118Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105118Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C2105118Parser.RETURN, 0); }
		public TerminalNode BREAK() { return getToken(C2105118Parser.BREAK, 0); }
		public TerminalNode CONTINUE() { return getToken(C2105118Parser.CONTINUE, 0); }
		public TerminalNode DO() { return getToken(C2105118Parser.DO, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(286);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(220);
				((StatementContext)_localctx).var_declaration = var_declaration();

							std::string message = "Line " + std::to_string(((StatementContext)_localctx).var_declaration.line_number) + ": statement : var_declaration";
							((StatementContext)_localctx).unit_name =  ((StatementContext)_localctx).var_declaration.var_name;
							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).var_declaration.line_number;
							message += "\n\n" + _localctx.unit_name ;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(223);
				((StatementContext)_localctx).expression_statement = expression_statement();
				 
							std::string message = "Line " + std::to_string(((StatementContext)_localctx).expression_statement.line_number) + ": statement : expression_statement";
							((StatementContext)_localctx).unit_name =  ((StatementContext)_localctx).expression_statement.unit_name;
							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).expression_statement.line_number;
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(226);
				((StatementContext)_localctx).compound_statement = compound_statement();

						std::string message = "Line " + std::to_string(((StatementContext)_localctx).compound_statement.line_number) + ": statement : compound_statement";
						((StatementContext)_localctx).unit_name =  ((StatementContext)_localctx).compound_statement.unit_name;
						((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).compound_statement.line_number;
						message += "\n\n" + _localctx.unit_name;
						writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(229);
				match(FOR);
				setState(230);
				match(LPAREN);
				setState(231);
				((StatementContext)_localctx).esa = expression_statement();
				setState(232);
				((StatementContext)_localctx).esb = expression_statement();
				setState(233);
				((StatementContext)_localctx).expression = expression();
				setState(234);
				match(RPAREN);
				setState(235);
				((StatementContext)_localctx).statement = statement();

							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).statement.line_number;
							std::string message = "Line " + std::to_string(_localctx.line_number) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement";
							((StatementContext)_localctx).unit_name =  "for (" + ((StatementContext)_localctx).esa.unit_name + "" + ((StatementContext)_localctx).esb.unit_name + "" + ((StatementContext)_localctx).expression.var_name + ") " + ((StatementContext)_localctx).statement.unit_name;
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(238);
				match(IF);
				setState(239);
				match(LPAREN);
				setState(240);
				((StatementContext)_localctx).expression = expression();
				setState(241);
				match(RPAREN);
				setState(242);
				((StatementContext)_localctx).st = statement();

							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).st.line_number;
							std::string message = "Line " + std::to_string(_localctx.line_number) + ": statement : IF LPAREN expression RPAREN statement";
							((StatementContext)_localctx).unit_name =  "if (" + ((StatementContext)_localctx).expression.var_name + ") " + ((StatementContext)_localctx).st.unit_name;
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(245);
				match(IF);
				setState(246);
				match(LPAREN);
				setState(247);
				((StatementContext)_localctx).expression = expression();
				setState(248);
				match(RPAREN);
				setState(249);
				((StatementContext)_localctx).s1 = statement();
				setState(250);
				match(ELSE);
				setState(251);
				((StatementContext)_localctx).s2 = statement();
				 
							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).s2.line_number;
							std::string message = "Line " + std::to_string(_localctx.line_number) + ": statement : IF LPAREN expression RPAREN statement ELSE statement";
							((StatementContext)_localctx).unit_name =  "if (" + ((StatementContext)_localctx).expression.var_name + ") " + ((StatementContext)_localctx).s1.unit_name + " else " + ((StatementContext)_localctx).s2.unit_name;
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(254);
				match(WHILE);
				setState(255);
				match(LPAREN);
				setState(256);
				((StatementContext)_localctx).expression = expression();
				setState(257);
				match(RPAREN);
				setState(258);
				((StatementContext)_localctx).statement = statement();

							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).statement.line_number;
							std::string message = "Line " + std::to_string(_localctx.line_number) + ": statement : WHILE LPAREN expression RPAREN statement";
							((StatementContext)_localctx).unit_name =  "while (" + ((StatementContext)_localctx).expression.var_name + ") " + ((StatementContext)_localctx).statement.unit_name;
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(261);
				match(PRINTLN);
				setState(262);
				match(LPAREN);
				setState(263);
				((StatementContext)_localctx).ID = match(ID);
				setState(264);
				match(RPAREN);
				setState(265);
				match(SEMICOLON);

							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).ID->getLine();
							std::string message = "Line " + std::to_string(_localctx.line_number) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON";
							symbolInfo* sinfo = getVarType(((StatementContext)_localctx).ID->getText());
							if (sinfo == nullptr) {
								std::string errMsg = "Error at line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText();
								writeIntoErrorFile(errMsg);
								message += "\n\n" + errMsg;
								syntaxErrorCount++;
								currentIndex = "";
							}
							((StatementContext)_localctx).unit_name =  "printf(" + ((StatementContext)_localctx).ID->getText() + ");";
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(267);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(268);
				((StatementContext)_localctx).expression = expression();
				setState(269);
				((StatementContext)_localctx).sm = match(SEMICOLON);

							if (retType == "VOID") {
								((StatementContext)_localctx).retError =  true;
							}
							std::string message = "Line " + std::to_string(((StatementContext)_localctx).RETURN->getLine()) + ": statement : RETURN expression SEMICOLON";
							((StatementContext)_localctx).unit_name =  "return " + ((StatementContext)_localctx).expression.var_name + " ;";
							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).sm->getLine();
							message += "\n\n" + _localctx.unit_name;
							cout << "return" << endl;
							writeIntoparserLogFile(message, 2);

						
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(272);
				((StatementContext)_localctx).BREAK = match(BREAK);
				setState(273);
				((StatementContext)_localctx).sm = match(SEMICOLON);

							if (inLoop==1){
								std::string message = "Line " + std::to_string(((StatementContext)_localctx).BREAK->getLine()) + ": statement : BREAK SEMICOLON";
								((StatementContext)_localctx).unit_name =  "break ;";
								((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).sm->getLine();
								message += "\n\n" + _localctx.unit_name;
								
								writeIntoparserLogFile(message, 2);
							}
							else { 
								std::string message = "Line " + std::to_string(((StatementContext)_localctx).BREAK->getLine()) + ": Break outside loop";
								((StatementContext)_localctx).unit_name =  "break ;";
								((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).sm->getLine();
								message += "\n\n" + _localctx.unit_name;
								writeIntoparserLogFile(message, 2);
							}
							cout<<"break"<<endl;
						
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(275);
				((StatementContext)_localctx).CONTINUE = match(CONTINUE);
				setState(276);
				((StatementContext)_localctx).sm = match(SEMICOLON);

							if (inLoop==1){
								std::string message = "Line " + std::to_string(((StatementContext)_localctx).CONTINUE->getLine()) + ": statement : CONTINUE SEMICOLON";
								((StatementContext)_localctx).unit_name =  "continue ;";
								((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).sm->getLine();
								message += "\n\n" + _localctx.unit_name;
								writeIntoparserLogFile(message, 2);
							}
							else { 
								std::string message = "Line " + std::to_string(((StatementContext)_localctx).CONTINUE->getLine()) + ": Continue outside loop";
								((StatementContext)_localctx).unit_name =  "continue ;";
								((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).sm->getLine();
								message += "\n\n" + _localctx.unit_name;
								writeIntoparserLogFile(message, 2);
							}
							cout<<"continue"<<endl;
						
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(278);
				match(DO);
				setState(279);
				((StatementContext)_localctx).cs = compound_statement();
				setState(280);
				match(WHILE);
				setState(281);
				match(LPAREN);
				setState(282);
				((StatementContext)_localctx).expression = expression();
				setState(283);
				((StatementContext)_localctx).RPAREN = match(RPAREN);

							((StatementContext)_localctx).unit_name =  "do" + ((StatementContext)_localctx).cs.unit_name + "while (" + ((StatementContext)_localctx).expression.var_name + ");";
							((StatementContext)_localctx).line_number =  ((StatementContext)_localctx).RPAREN->getLine();
							std::string message = "Line " + std::to_string(((StatementContext)_localctx).cs.line_number) + ": statement : DO LCURL statement RCURL WHILE LPAREN expression RPAREN";
							message += "\n\n" + _localctx.unit_name;
							cout<< "DO "<<endl;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public std::string unit_name;
		public int line_number;
		public Token SEMICOLON;
		public ExpressionContext expression;
		public TerminalNode SEMICOLON() { return getToken(C2105118Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_expression_statement);
		try {
			setState(294);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(288);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

							std::string message = "Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : SEMICOLON";
							((Expression_statementContext)_localctx).unit_name =  ";";
							((Expression_statementContext)_localctx).line_number =  ((Expression_statementContext)_localctx).SEMICOLON->getLine();
							message += "\n\n" + _localctx.unit_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(290);
				((Expression_statementContext)_localctx).expression = expression();
				setState(291);
				match(SEMICOLON);

							std::string message = "Line " + std::to_string(((Expression_statementContext)_localctx).expression.line_number) + ": expression_statement : expression SEMICOLON";
							((Expression_statementContext)_localctx).unit_name =  ((Expression_statementContext)_localctx).expression.var_name + ";";
							((Expression_statementContext)_localctx).line_number =  ((Expression_statementContext)_localctx).expression.line_number;
							message += "\n\n" + _localctx.unit_name ;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string trueName;
		public bool indexed = false;
		public Token ID;
		public ExpressionContext expression;
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105118Parser.LTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RTHIRD() { return getToken(C2105118Parser.RTHIRD, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable);
		try {
			setState(304);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(296);
				((VariableContext)_localctx).ID = match(ID);

							std::string message = "Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID";
							symbolInfo* sinfo = getVarType(((VariableContext)_localctx).ID->getText());
							if (sinfo == nullptr) {
								std::string errMsg = "Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText();
								writeIntoErrorFile(errMsg);
								message += "\n\n" + errMsg;
								syntaxErrorCount++;
								currentIndex = "";
							} else if(sinfo->getIsArray()){
								currentIndex = sinfo->getType();
								std::string errMsg = "Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Type mismatch, " + ((VariableContext)_localctx).ID->getText() + " is an array";
								writeIntoErrorFile(errMsg);
								message += "\n\n" + errMsg;
								syntaxErrorCount++;
							}
							((VariableContext)_localctx).var_name =  ((VariableContext)_localctx).ID->getText();
							((VariableContext)_localctx).line_number =  ((VariableContext)_localctx).ID->getLine();
							((VariableContext)_localctx).trueName =  ((VariableContext)_localctx).ID->getText();
							message += "\n\n" + ((VariableContext)_localctx).ID->getText();
							writeIntoparserLogFile(message, 2);
							((VariableContext)_localctx).indexed =  false; // not indexed by default

						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(298);
				((VariableContext)_localctx).ID = match(ID);
				setState(299);
				match(LTHIRD);
				setState(300);
				((VariableContext)_localctx).expression = expression();
				setState(301);
				match(RTHIRD);

							std::string message = "Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD";
							((VariableContext)_localctx).var_name =  ((VariableContext)_localctx).ID->getText() + "[" + ((VariableContext)_localctx).expression.var_name + "]";
							((VariableContext)_localctx).trueName =  ((VariableContext)_localctx).ID->getText() ;
							symbolInfo* sinfo = getVarType(((VariableContext)_localctx).ID->getText());

							((VariableContext)_localctx).line_number =  ((VariableContext)_localctx).ID->getLine();
							if (sinfo != nullptr) {
								if (!sinfo->getIsArray()){
									 currentIndex = "";
									std::string errMsg = "Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": "+ ((VariableContext)_localctx).ID->getText() + " not an array";
									writeIntoErrorFile(errMsg);
									message += "\n\n" + errMsg;
									syntaxErrorCount++;
								} else {
									
									if (currentIndex == "CONST_FLOAT") {
										std::string errMsg = "Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Expression inside third brackets not an integer";
										writeIntoErrorFile(errMsg);
										message += "\n\n" + errMsg;
										syntaxErrorCount++;
									}
								}
							}

							((VariableContext)_localctx).indexed =  true; // indexed
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public Logic_expressionContext logic_expression;
		public VariableContext variable;
		public Token ASSIGNOP;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C2105118Parser.ASSIGNOP, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			setState(314);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(306);
				((ExpressionContext)_localctx).logic_expression = logic_expression();
				 
							((ExpressionContext)_localctx).var_name =  ((ExpressionContext)_localctx).logic_expression.var_name;
							((ExpressionContext)_localctx).line_number =  ((ExpressionContext)_localctx).logic_expression.line_number;
							std::string message = "Line " + std::to_string(((ExpressionContext)_localctx).logic_expression.line_number) + ": expression : logic_expression";
							message += "\n\n" + ((ExpressionContext)_localctx).logic_expression.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(309);
				((ExpressionContext)_localctx).variable = variable();
				setState(310);
				((ExpressionContext)_localctx).ASSIGNOP = match(ASSIGNOP);
				setState(311);
				((ExpressionContext)_localctx).logic_expression = logic_expression();
				 
							std::string ctype = ((ExpressionContext)_localctx).logic_expression.type;
							bool indexed = ((ExpressionContext)_localctx).variable.indexed;
							((ExpressionContext)_localctx).var_name =  ((ExpressionContext)_localctx).variable.var_name + ((ExpressionContext)_localctx).ASSIGNOP->getText() + ((ExpressionContext)_localctx).logic_expression.var_name;
							std::string trueName = ((ExpressionContext)_localctx).variable.trueName;
							((ExpressionContext)_localctx).line_number =  ((ExpressionContext)_localctx).variable.line_number;
							symbolInfo* sinfo = getVarType(((ExpressionContext)_localctx).variable.trueName);
							std::string var_type= sinfo ? sinfo->getType() : "";
							bool isArray = sinfo ? sinfo->getIsArray() : false;
							// cout<< "variable type is "<< var_type << "for variable " << ((ExpressionContext)_localctx).variable.var_name << endl;
							// cout<< "is array: " << (isArray ? "true" : "false") << endl;
							// cout<<" current type is: " << currentIndex << endl;
							// cout<< "current index is: " << indexed << endl;

							std::string message = "Line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": expression : variable ASSIGNOP logic_expression";
							if (ctype == "VOID") {
								std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).logic_expression.line_number) + ": Void function used in expression";
								writeIntoErrorFile(errMsg);
								message += "\n\n" + errMsg;
								syntaxErrorCount++;
								currentType = "";
							}

							else if  (sinfo!=nullptr ){
							if (var_type == "INT" && (currentIndex == "CONST_FLOAT"||currentIndex == "FLOAT")) {
								if (!isArray) {
									std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": Type Mismatch";
									writeIntoErrorFile(errMsg);
									syntaxErrorCount++;
									currentType = "";
									message += "\n\n" + errMsg;
								}
								else if (!indexed) {

									std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": Type Mismatch, "+ trueName + " is an array";
									writeIntoErrorFile(errMsg);
									syntaxErrorCount++;
									message += "\n\n" + errMsg;
								}
								else{
									std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": Type Mismatch";
									writeIntoErrorFile(errMsg);
									syntaxErrorCount++;
									message += "\n\n" + errMsg;
								}
							} else if (var_type == "FLOAT" && (currentIndex == "CONST_INT"||currentIndex == "INT") ) {
								if (!isArray) {
									// std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": Type Mismatch";
									// writeIntoErrorFile(errMsg);
									// syntaxErrorCount++;
									currentType="";
									// message += "\n\n" + errMsg;
								}
								else if (!indexed) {
									std::string errMsg = "Error at line " + std::to_string(((ExpressionContext)_localctx).variable.line_number) + ": Type Mismatch, "+ trueName + " is an array";
									writeIntoErrorFile(errMsg);
									syntaxErrorCount++;
									message += "\n\n" + errMsg;
								}
							}
							
						}
							

							message += "\n\n" + _localctx.var_name ;
							writeIntoparserLogFile(message, 2);
					
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string type;
		public Rel_expressionContext rel_expression;
		public Rel_expressionContext rl;
		public Token LOGICOP;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C2105118Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_logic_expression);
		try {
			setState(324);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(316);
				((Logic_expressionContext)_localctx).rel_expression = rel_expression();

							((Logic_expressionContext)_localctx).var_name =  ((Logic_expressionContext)_localctx).rel_expression.var_name;
							((Logic_expressionContext)_localctx).line_number =  ((Logic_expressionContext)_localctx).rel_expression.line_number;
							((Logic_expressionContext)_localctx).type =  ((Logic_expressionContext)_localctx).rel_expression.type;
							std::string message = "Line " + std::to_string(((Logic_expressionContext)_localctx).rel_expression.line_number) + ": logic_expression : rel_expression";
							message += "\n\n" + ((Logic_expressionContext)_localctx).rel_expression.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(319);
				((Logic_expressionContext)_localctx).rl = ((Logic_expressionContext)_localctx).rel_expression = rel_expression();
				setState(320);
				((Logic_expressionContext)_localctx).LOGICOP = match(LOGICOP);
				setState(321);
				((Logic_expressionContext)_localctx).rel_expression = rel_expression();

							((Logic_expressionContext)_localctx).var_name =  ((Logic_expressionContext)_localctx).rl.var_name + ((Logic_expressionContext)_localctx).LOGICOP->getText() + ((Logic_expressionContext)_localctx).rel_expression.var_name;
							((Logic_expressionContext)_localctx).line_number =  ((Logic_expressionContext)_localctx).rl.line_number;
							std::string message = "Line " + std::to_string(((Logic_expressionContext)_localctx).rl.line_number) + ": logic_expression : rel_expression LOGICOP rel_expression";
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string type;
		public Simple_expressionContext simple_expression;
		public Simple_expressionContext sl1;
		public Token RELOP;
		public Simple_expressionContext sl2;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C2105118Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_rel_expression);
		try {
			setState(334);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(326);
				((Rel_expressionContext)_localctx).simple_expression = simple_expression(0);

							((Rel_expressionContext)_localctx).var_name =  ((Rel_expressionContext)_localctx).simple_expression.var_name;
							((Rel_expressionContext)_localctx).line_number =  ((Rel_expressionContext)_localctx).simple_expression.line_number;
							((Rel_expressionContext)_localctx).type =  ((Rel_expressionContext)_localctx).simple_expression.type;
							std::string message = "Line " + std::to_string(((Rel_expressionContext)_localctx).simple_expression.line_number) + ": rel_expression : simple_expression";
							message += "\n\n" + ((Rel_expressionContext)_localctx).simple_expression.var_name;
							writeIntoparserLogFile(message, 2);	
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(329);
				((Rel_expressionContext)_localctx).sl1 = simple_expression(0);
				setState(330);
				((Rel_expressionContext)_localctx).RELOP = match(RELOP);
				setState(331);
				((Rel_expressionContext)_localctx).sl2 = simple_expression(0);

							((Rel_expressionContext)_localctx).var_name =  ((Rel_expressionContext)_localctx).sl1.var_name + ((Rel_expressionContext)_localctx).RELOP->getText() + ((Rel_expressionContext)_localctx).sl2.var_name;
							((Rel_expressionContext)_localctx).line_number =  ((Rel_expressionContext)_localctx).sl1.line_number;
							std::string message = "Line " + std::to_string(((Rel_expressionContext)_localctx).sl2.line_number) + ": rel_expression : simple_expression RELOP simple_expression";
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string type;
		public Simple_expressionContext se;
		public TermContext term;
		public Token ADDOP;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105118Parser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(337);
			((Simple_expressionContext)_localctx).term = term(0);

						std::string message = "Line " + std::to_string(((Simple_expressionContext)_localctx).term.line_number) + ": simple_expression : term";
						((Simple_expressionContext)_localctx).var_name =  ((Simple_expressionContext)_localctx).term.var_name;
						((Simple_expressionContext)_localctx).line_number =  ((Simple_expressionContext)_localctx).term.line_number;
						((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).term.type;
						message += "\n\n" + ((Simple_expressionContext)_localctx).term.var_name;
						writeIntoparserLogFile(message, 2);
					
			}
			_ctx.stop = _input.LT(-1);
			setState(347);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.se = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(340);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(341);
					((Simple_expressionContext)_localctx).ADDOP = match(ADDOP);
					setState(342);
					((Simple_expressionContext)_localctx).term = term(0);
					 
					          			std::string message = "Line " + std::to_string(((Simple_expressionContext)_localctx).term.line_number) + ": simple_expression : simple_expression ADDOP term";
					          			((Simple_expressionContext)_localctx).var_name =  ((Simple_expressionContext)_localctx).se.var_name + ((Simple_expressionContext)_localctx).ADDOP->getText() + ((Simple_expressionContext)_localctx).term.var_name;
					          			((Simple_expressionContext)_localctx).line_number =  ((Simple_expressionContext)_localctx).term.line_number;
					          			message += "\n\n" + _localctx.var_name;
					          			writeIntoparserLogFile(message, 2);
					          		
					}
					} 
				}
				setState(349);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string type;
		public TermContext tm;
		public Unary_expressionContext unary_expression;
		public Token MULOP;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C2105118Parser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(351);
			((TermContext)_localctx).unary_expression = unary_expression();

						std::string message = "Line " + std::to_string(((TermContext)_localctx).unary_expression.line_number) + ": term : unary_expression";
						((TermContext)_localctx).var_name =  ((TermContext)_localctx).unary_expression.var_name;
						((TermContext)_localctx).line_number =  ((TermContext)_localctx).unary_expression.line_number;
						((TermContext)_localctx).type =  ((TermContext)_localctx).unary_expression.type;
						message += "\n\n" + ((TermContext)_localctx).unary_expression.var_name;
						writeIntoparserLogFile(message, 2);
					
			}
			_ctx.stop = _input.LT(-1);
			setState(361);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.tm = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(354);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(355);
					((TermContext)_localctx).MULOP = match(MULOP);
					setState(356);
					((TermContext)_localctx).unary_expression = unary_expression();

					          			// cout<<"mulop unary "<<  ((TermContext)_localctx).MULOP->getText()<< endl;
					          			std::string message = "Line " + std::to_string(((TermContext)_localctx).unary_expression.line_number) + ": term : term MULOP unary_expression";
					          			if (((TermContext)_localctx).unary_expression.type == "VOID") {
					          				std::string errMsg = "Error at line " + std::to_string(((TermContext)_localctx).unary_expression.line_number) + ": Void function used in expression";
					          				writeIntoErrorFile(errMsg);
					          				syntaxErrorCount++;

					          				message = message + "\n\n" + errMsg;
					          				currentIndex = "";
					          			}
					          			if (currentIndex=="CONST_FLOAT" && ((TermContext)_localctx).unary_expression.var_name != "0"){
					          				std::string errMsg = "Error at line " + std::to_string(((TermContext)_localctx).unary_expression.line_number) + ": Non-Integer operand on modulus operator";
					          				writeIntoErrorFile(errMsg);
					          				syntaxErrorCount++;
					          				message= message + "\n\n" + errMsg;
					          				currentIndex = "";
					          			}
					          			if (((TermContext)_localctx).MULOP->getText() == "%" && ((TermContext)_localctx).unary_expression.var_name == "0") {
					          				std::string errMsg = "Error at line " + std::to_string(((TermContext)_localctx).unary_expression.line_number) + ": Modulus by Zero";
					          				writeIntoErrorFile(errMsg);
					          				syntaxErrorCount++;
					          				message= message + "\n\n" + errMsg;
					          				currentIndex = "";
					          			}
					          			((TermContext)_localctx).var_name =  ((TermContext)_localctx).tm.var_name + ((TermContext)_localctx).MULOP->getText() + ((TermContext)_localctx).unary_expression.var_name;
					          			((TermContext)_localctx).line_number =  ((TermContext)_localctx).unary_expression.line_number;
					          			message += "\n\n" + _localctx.var_name;
					          			writeIntoparserLogFile(message, 2);
					          		
					}
					} 
				}
				setState(363);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std::string type;
		public Token ADDOP;
		public Unary_expressionContext unary_expression;
		public Token NOT;
		public FactorContext factor;
		public TerminalNode ADDOP() { return getToken(C2105118Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C2105118Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_unary_expression);
		try {
			setState(375);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(364);
				((Unary_expressionContext)_localctx).ADDOP = match(ADDOP);
				setState(365);
				((Unary_expressionContext)_localctx).unary_expression = unary_expression();

							std::string message = "Line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line_number) + ": unary_expression : ADDOP unary_expression";
							((Unary_expressionContext)_localctx).var_name =  ((Unary_expressionContext)_localctx).ADDOP->getText() + ((Unary_expressionContext)_localctx).unary_expression.var_name;
							((Unary_expressionContext)_localctx).line_number =  ((Unary_expressionContext)_localctx).unary_expression.line_number;
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(368);
				((Unary_expressionContext)_localctx).NOT = match(NOT);
				setState(369);
				((Unary_expressionContext)_localctx).unary_expression = unary_expression();

							std::string message = "Line " + std::to_string(((Unary_expressionContext)_localctx).unary_expression.line_number) + ": unary_expression : NOT unary_expression";
							((Unary_expressionContext)_localctx).var_name =  ((Unary_expressionContext)_localctx).NOT->getText() + ((Unary_expressionContext)_localctx).unary_expression.var_name;
							((Unary_expressionContext)_localctx).line_number =  ((Unary_expressionContext)_localctx).unary_expression.line_number;
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(372);
				((Unary_expressionContext)_localctx).factor = factor();

							std::string message = "Line " + std::to_string(((Unary_expressionContext)_localctx).factor.line_number) + ": unary_expression : factor";
							((Unary_expressionContext)_localctx).var_name =  ((Unary_expressionContext)_localctx).factor.var_name;
							((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).factor.type;
							((Unary_expressionContext)_localctx).line_number =  ((Unary_expressionContext)_localctx).factor.line_number;
							message += "\n\n" + ((Unary_expressionContext)_localctx).factor.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public std::string var_name;
		public int line_number;
		public std:: string type;
		public VariableContext variable;
		public Token ID;
		public Argument_listContext argument_list;
		public ExpressionContext expression;
		public Token CONST_INT;
		public Token CONST_FLOAT;
		public Token INCOP;
		public Token DECOP;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105118Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105118Parser.LPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C2105118Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C2105118Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C2105118Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C2105118Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C2105118Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_factor);
		try {
			setState(403);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(377);
				((FactorContext)_localctx).variable = variable();

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).variable.line_number) + ": factor : variable";
							message += "\n\n" + ((FactorContext)_localctx).variable.var_name;
							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).variable.var_name;
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).variable.line_number;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(380);
				((FactorContext)_localctx).ID = match(ID);
				setState(381);
				match(LPAREN);
				setState(382);
				((FactorContext)_localctx).argument_list = argument_list();
				setState(383);
				match(RPAREN);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": factor : ID LPAREN argument_list RPAREN";
							std::string var_name = ((FactorContext)_localctx).ID->getText() + "(" + ((FactorContext)_localctx).argument_list.name_line + ")";

							symbolInfo* sinfo = getVarType(((FactorContext)_localctx).ID->getText());
							std::string currentType = sinfo ? sinfo->getType() : "";
							((FactorContext)_localctx).type =  currentType;
							if (sinfo == nullptr) {
								std::string errMsg = "Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Undefined function " + ((FactorContext)_localctx).ID->getText();
								writeIntoErrorFile(errMsg);
								message += "\n\n" + errMsg;
								syntaxErrorCount++;
								currentIndex = "";
							}

							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).ID->getText() + "(" + ((FactorContext)_localctx).argument_list.name_line + ")";
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).ID->getLine();
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(386);
				match(LPAREN);
				setState(387);
				((FactorContext)_localctx).expression = expression();
				setState(388);
				match(RPAREN);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).expression.line_number) + ": factor : LPAREN expression RPAREN";
							((FactorContext)_localctx).var_name =  "(" + ((FactorContext)_localctx).expression.var_name + ")";
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).expression.line_number;
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(391);
				((FactorContext)_localctx).CONST_INT = match(CONST_INT);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).CONST_INT->getLine()) + ": factor : CONST_INT";
							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).CONST_INT->getText();
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).CONST_INT->getLine();
							currentIndex = "CONST_INT";
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(393);
				((FactorContext)_localctx).CONST_FLOAT = match(CONST_FLOAT);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).CONST_FLOAT->getLine()) + ": factor : CONST_FLOAT";
							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).CONST_FLOAT->getText();
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).CONST_FLOAT->getLine();
							message += "\n\n" + _localctx.var_name;
							currentIndex = "CONST_FLOAT";
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(395);
				((FactorContext)_localctx).variable = variable();
				setState(396);
				((FactorContext)_localctx).INCOP = match(INCOP);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).variable.line_number) + ": factor : variable INCOP";
							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).variable.var_name + ((FactorContext)_localctx).INCOP->getText();
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).variable.line_number;
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(399);
				((FactorContext)_localctx).variable = variable();
				setState(400);
				((FactorContext)_localctx).DECOP = match(DECOP);

							std::string message = "Line " + std::to_string(((FactorContext)_localctx).variable.line_number) + ": factor : variable DECOP";
							((FactorContext)_localctx).var_name =  ((FactorContext)_localctx).variable.var_name + ((FactorContext)_localctx).DECOP->getText();
							((FactorContext)_localctx).line_number =  ((FactorContext)_localctx).variable.line_number;
							message += "\n\n" + _localctx.var_name;
							writeIntoparserLogFile(message, 2);
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public std::string name_line;
		public int line_number;
		public ArgumentsContext arguments;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_argument_list);
		try {
			setState(409);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(405);
				((Argument_listContext)_localctx).arguments = arguments(0);

							((Argument_listContext)_localctx).name_line =  ((Argument_listContext)_localctx).arguments.name_line;
							((Argument_listContext)_localctx).line_number =  ((Argument_listContext)_localctx).arguments.line_number;
							std::string message = "Line " + std::to_string(((Argument_listContext)_localctx).arguments.line_number) + ": argument_list : arguments";
							message += "\n\n" + ((Argument_listContext)_localctx).arguments.name_line;
							writeIntoparserLogFile(message, 2);
							
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public std::string name_line;
		public int line_number;
		public ArgumentsContext ar;
		public Logic_expressionContext logic_expression;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105118Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 46;
		enterRecursionRule(_localctx, 46, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(412);
			((ArgumentsContext)_localctx).logic_expression = logic_expression();

						((ArgumentsContext)_localctx).name_line =  ((ArgumentsContext)_localctx).logic_expression.var_name;
						((ArgumentsContext)_localctx).line_number =  ((ArgumentsContext)_localctx).logic_expression.line_number;
						std::string message = "Line " + std::to_string(((ArgumentsContext)_localctx).logic_expression.line_number) + ": arguments : logic_expression";
						message += "\n\n" + _localctx.name_line;
						writeIntoparserLogFile(message, 2);
					
			}
			_ctx.stop = _input.LT(-1);
			setState(422);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.ar = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(415);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(416);
					match(COMMA);
					setState(417);
					((ArgumentsContext)_localctx).logic_expression = logic_expression();

					          			((ArgumentsContext)_localctx).name_line =  ((ArgumentsContext)_localctx).ar.name_line + "," + ((ArgumentsContext)_localctx).logic_expression.var_name;
					          			((ArgumentsContext)_localctx).line_number =  ((ArgumentsContext)_localctx).logic_expression.line_number;
					          			std::string message = "Line " + std::to_string(((ArgumentsContext)_localctx).logic_expression.line_number) + ": arguments : arguments COMMA logic_expression";
					          			message += "\n\n" + _localctx.name_line;
					          			writeIntoparserLogFile(message, 2);
					          		
					}
					} 
				}
				setState(424);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 10:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 11:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 18:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 19:
			return term_sempred((TermContext)_localctx, predIndex);
		case 23:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 8:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001$\u01aa\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001<\b\u0001\n\u0001\f\u0001"+
		"?\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002J\b\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003[\b\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004q\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005"+
		"{\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0005\u0005\u0088\b\u0005\n\u0005\f\u0005\u008b\t\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u0097\b\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u00aa\b\u0007\u0001"+
		"\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u00b4"+
		"\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003"+
		"\n\u00be\b\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0005\n\u00cb\b\n\n\n\f\n\u00ce\t\n\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0005\u000b\u00d8\b\u000b\n\u000b\f\u000b\u00db\t\u000b\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0003\f\u011f\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0003\r\u0127\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u0131"+
		"\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u013b\b\u000f\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0003\u0010\u0145\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u014f"+
		"\b\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u015a\b\u0012\n"+
		"\u0012\f\u0012\u015d\t\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0005"+
		"\u0013\u0168\b\u0013\n\u0013\f\u0013\u016b\t\u0013\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u0178\b\u0014\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0003\u0015\u0194\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u019a\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0005\u0017\u01a5\b\u0017\n\u0017\f\u0017\u01a8\t\u0017\u0001\u0017\u0000"+
		"\u0007\u0002\n\u0014\u0016$&.\u0018\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.\u0000\u0000"+
		"\u01be\u00000\u0001\u0000\u0000\u0000\u00023\u0001\u0000\u0000\u0000\u0004"+
		"I\u0001\u0000\u0000\u0000\u0006Z\u0001\u0000\u0000\u0000\bp\u0001\u0000"+
		"\u0000\u0000\nz\u0001\u0000\u0000\u0000\f\u0096\u0001\u0000\u0000\u0000"+
		"\u000e\u00a9\u0001\u0000\u0000\u0000\u0010\u00ab\u0001\u0000\u0000\u0000"+
		"\u0012\u00b3\u0001\u0000\u0000\u0000\u0014\u00bd\u0001\u0000\u0000\u0000"+
		"\u0016\u00cf\u0001\u0000\u0000\u0000\u0018\u011e\u0001\u0000\u0000\u0000"+
		"\u001a\u0126\u0001\u0000\u0000\u0000\u001c\u0130\u0001\u0000\u0000\u0000"+
		"\u001e\u013a\u0001\u0000\u0000\u0000 \u0144\u0001\u0000\u0000\u0000\""+
		"\u014e\u0001\u0000\u0000\u0000$\u0150\u0001\u0000\u0000\u0000&\u015e\u0001"+
		"\u0000\u0000\u0000(\u0177\u0001\u0000\u0000\u0000*\u0193\u0001\u0000\u0000"+
		"\u0000,\u0199\u0001\u0000\u0000\u0000.\u019b\u0001\u0000\u0000\u00000"+
		"1\u0003\u0002\u0001\u000012\u0006\u0000\uffff\uffff\u00002\u0001\u0001"+
		"\u0000\u0000\u000034\u0006\u0001\uffff\uffff\u000045\u0003\u0004\u0002"+
		"\u000056\u0006\u0001\uffff\uffff\u00006=\u0001\u0000\u0000\u000078\n\u0002"+
		"\u0000\u000089\u0003\u0004\u0002\u00009:\u0006\u0001\uffff\uffff\u0000"+
		":<\u0001\u0000\u0000\u0000;7\u0001\u0000\u0000\u0000<?\u0001\u0000\u0000"+
		"\u0000=;\u0001\u0000\u0000\u0000=>\u0001\u0000\u0000\u0000>\u0003\u0001"+
		"\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000@A\u0003\u000e\u0007\u0000"+
		"AB\u0006\u0002\uffff\uffff\u0000BJ\u0001\u0000\u0000\u0000CD\u0003\u0006"+
		"\u0003\u0000DE\u0006\u0002\uffff\uffff\u0000EJ\u0001\u0000\u0000\u0000"+
		"FG\u0003\b\u0004\u0000GH\u0006\u0002\uffff\uffff\u0000HJ\u0001\u0000\u0000"+
		"\u0000I@\u0001\u0000\u0000\u0000IC\u0001\u0000\u0000\u0000IF\u0001\u0000"+
		"\u0000\u0000J\u0005\u0001\u0000\u0000\u0000KL\u0003\u0012\t\u0000LM\u0005"+
		"\"\u0000\u0000MN\u0005\u0011\u0000\u0000NO\u0003\n\u0005\u0000OP\u0005"+
		"\u0012\u0000\u0000PQ\u0005\u0017\u0000\u0000QR\u0006\u0003\uffff\uffff"+
		"\u0000R[\u0001\u0000\u0000\u0000ST\u0003\u0012\t\u0000TU\u0005\"\u0000"+
		"\u0000UV\u0005\u0011\u0000\u0000VW\u0005\u0012\u0000\u0000WX\u0005\u0017"+
		"\u0000\u0000XY\u0006\u0003\uffff\uffff\u0000Y[\u0001\u0000\u0000\u0000"+
		"ZK\u0001\u0000\u0000\u0000ZS\u0001\u0000\u0000\u0000[\u0007\u0001\u0000"+
		"\u0000\u0000\\]\u0003\u0012\t\u0000]^\u0005\"\u0000\u0000^_\u0006\u0004"+
		"\uffff\uffff\u0000_`\u0005\u0011\u0000\u0000`a\u0006\u0004\uffff\uffff"+
		"\u0000ab\u0003\n\u0005\u0000bc\u0006\u0004\uffff\uffff\u0000cd\u0005\u0012"+
		"\u0000\u0000de\u0003\f\u0006\u0000ef\u0006\u0004\uffff\uffff\u0000fq\u0001"+
		"\u0000\u0000\u0000gh\u0003\u0012\t\u0000hi\u0005\"\u0000\u0000ij\u0006"+
		"\u0004\uffff\uffff\u0000jk\u0005\u0011\u0000\u0000kl\u0006\u0004\uffff"+
		"\uffff\u0000lm\u0005\u0012\u0000\u0000mn\u0003\f\u0006\u0000no\u0006\u0004"+
		"\uffff\uffff\u0000oq\u0001\u0000\u0000\u0000p\\\u0001\u0000\u0000\u0000"+
		"pg\u0001\u0000\u0000\u0000q\t\u0001\u0000\u0000\u0000rs\u0006\u0005\uffff"+
		"\uffff\u0000st\u0003\u0012\t\u0000tu\u0005\"\u0000\u0000uv\u0006\u0005"+
		"\uffff\uffff\u0000v{\u0001\u0000\u0000\u0000wx\u0003\u0012\t\u0000xy\u0006"+
		"\u0005\uffff\uffff\u0000y{\u0001\u0000\u0000\u0000zr\u0001\u0000\u0000"+
		"\u0000zw\u0001\u0000\u0000\u0000{\u0089\u0001\u0000\u0000\u0000|}\n\u0004"+
		"\u0000\u0000}~\u0005\u0018\u0000\u0000~\u007f\u0003\u0012\t\u0000\u007f"+
		"\u0080\u0005\"\u0000\u0000\u0080\u0081\u0006\u0005\uffff\uffff\u0000\u0081"+
		"\u0088\u0001\u0000\u0000\u0000\u0082\u0083\n\u0003\u0000\u0000\u0083\u0084"+
		"\u0005\u0018\u0000\u0000\u0084\u0085\u0003\u0012\t\u0000\u0085\u0086\u0006"+
		"\u0005\uffff\uffff\u0000\u0086\u0088\u0001\u0000\u0000\u0000\u0087|\u0001"+
		"\u0000\u0000\u0000\u0087\u0082\u0001\u0000\u0000\u0000\u0088\u008b\u0001"+
		"\u0000\u0000\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u0089\u008a\u0001"+
		"\u0000\u0000\u0000\u008a\u000b\u0001\u0000\u0000\u0000\u008b\u0089\u0001"+
		"\u0000\u0000\u0000\u008c\u008d\u0005\u0013\u0000\u0000\u008d\u008e\u0006"+
		"\u0006\uffff\uffff\u0000\u008e\u008f\u0003\u0016\u000b\u0000\u008f\u0090"+
		"\u0005\u0014\u0000\u0000\u0090\u0091\u0006\u0006\uffff\uffff\u0000\u0091"+
		"\u0097\u0001\u0000\u0000\u0000\u0092\u0093\u0005\u0013\u0000\u0000\u0093"+
		"\u0094\u0006\u0006\uffff\uffff\u0000\u0094\u0095\u0005\u0014\u0000\u0000"+
		"\u0095\u0097\u0006\u0006\uffff\uffff\u0000\u0096\u008c\u0001\u0000\u0000"+
		"\u0000\u0096\u0092\u0001\u0000\u0000\u0000\u0097\r\u0001\u0000\u0000\u0000"+
		"\u0098\u0099\u0003\u0012\t\u0000\u0099\u009a\u0003\u0014\n\u0000\u009a"+
		"\u009b\u0005\u0017\u0000\u0000\u009b\u009c\u0006\u0007\uffff\uffff\u0000"+
		"\u009c\u00aa\u0001\u0000\u0000\u0000\u009d\u009e\u0003\u0012\t\u0000\u009e"+
		"\u009f\u0003\u0014\n\u0000\u009f\u00a0\u0005!\u0000\u0000\u00a0\u00a1"+
		"\u0003 \u0010\u0000\u00a1\u00a2\u0005\u0017\u0000\u0000\u00a2\u00a3\u0006"+
		"\u0007\uffff\uffff\u0000\u00a3\u00aa\u0001\u0000\u0000\u0000\u00a4\u00a5"+
		"\u0003\u0012\t\u0000\u00a5\u00a6\u0003\u0010\b\u0000\u00a6\u00a7\u0005"+
		"\u0017\u0000\u0000\u00a7\u00a8\u0006\u0007\uffff\uffff\u0000\u00a8\u00aa"+
		"\u0001\u0000\u0000\u0000\u00a9\u0098\u0001\u0000\u0000\u0000\u00a9\u009d"+
		"\u0001\u0000\u0000\u0000\u00a9\u00a4\u0001\u0000\u0000\u0000\u00aa\u000f"+
		"\u0001\u0000\u0000\u0000\u00ab\u00ac\u0006\b\uffff\uffff\u0000\u00ac\u0011"+
		"\u0001\u0000\u0000\u0000\u00ad\u00ae\u0005\u000b\u0000\u0000\u00ae\u00b4"+
		"\u0006\t\uffff\uffff\u0000\u00af\u00b0\u0005\f\u0000\u0000\u00b0\u00b4"+
		"\u0006\t\uffff\uffff\u0000\u00b1\u00b2\u0005\r\u0000\u0000\u00b2\u00b4"+
		"\u0006\t\uffff\uffff\u0000\u00b3\u00ad\u0001\u0000\u0000\u0000\u00b3\u00af"+
		"\u0001\u0000\u0000\u0000\u00b3\u00b1\u0001\u0000\u0000\u0000\u00b4\u0013"+
		"\u0001\u0000\u0000\u0000\u00b5\u00b6\u0006\n\uffff\uffff\u0000\u00b6\u00b7"+
		"\u0005\"\u0000\u0000\u00b7\u00be\u0006\n\uffff\uffff\u0000\u00b8\u00b9"+
		"\u0005\"\u0000\u0000\u00b9\u00ba\u0005\u0015\u0000\u0000\u00ba\u00bb\u0005"+
		"#\u0000\u0000\u00bb\u00bc\u0005\u0016\u0000\u0000\u00bc\u00be\u0006\n"+
		"\uffff\uffff\u0000\u00bd\u00b5\u0001\u0000\u0000\u0000\u00bd\u00b8\u0001"+
		"\u0000\u0000\u0000\u00be\u00cc\u0001\u0000\u0000\u0000\u00bf\u00c0\n\u0004"+
		"\u0000\u0000\u00c0\u00c1\u0005\u0018\u0000\u0000\u00c1\u00c2\u0005\"\u0000"+
		"\u0000\u00c2\u00cb\u0006\n\uffff\uffff\u0000\u00c3\u00c4\n\u0003\u0000"+
		"\u0000\u00c4\u00c5\u0005\u0018\u0000\u0000\u00c5\u00c6\u0005\"\u0000\u0000"+
		"\u00c6\u00c7\u0005\u0015\u0000\u0000\u00c7\u00c8\u0005#\u0000\u0000\u00c8"+
		"\u00c9\u0005\u0016\u0000\u0000\u00c9\u00cb\u0006\n\uffff\uffff\u0000\u00ca"+
		"\u00bf\u0001\u0000\u0000\u0000\u00ca\u00c3\u0001\u0000\u0000\u0000\u00cb"+
		"\u00ce\u0001\u0000\u0000\u0000\u00cc\u00ca\u0001\u0000\u0000\u0000\u00cc"+
		"\u00cd\u0001\u0000\u0000\u0000\u00cd\u0015\u0001\u0000\u0000\u0000\u00ce"+
		"\u00cc\u0001\u0000\u0000\u0000\u00cf\u00d0\u0006\u000b\uffff\uffff\u0000"+
		"\u00d0\u00d1\u0003\u0018\f\u0000\u00d1\u00d2\u0006\u000b\uffff\uffff\u0000"+
		"\u00d2\u00d9\u0001\u0000\u0000\u0000\u00d3\u00d4\n\u0001\u0000\u0000\u00d4"+
		"\u00d5\u0003\u0018\f\u0000\u00d5\u00d6\u0006\u000b\uffff\uffff\u0000\u00d6"+
		"\u00d8\u0001\u0000\u0000\u0000\u00d7\u00d3\u0001\u0000\u0000\u0000\u00d8"+
		"\u00db\u0001\u0000\u0000\u0000\u00d9\u00d7\u0001\u0000\u0000\u0000\u00d9"+
		"\u00da\u0001\u0000\u0000\u0000\u00da\u0017\u0001\u0000\u0000\u0000\u00db"+
		"\u00d9\u0001\u0000\u0000\u0000\u00dc\u00dd\u0003\u000e\u0007\u0000\u00dd"+
		"\u00de\u0006\f\uffff\uffff\u0000\u00de\u011f\u0001\u0000\u0000\u0000\u00df"+
		"\u00e0\u0003\u001a\r\u0000\u00e0\u00e1\u0006\f\uffff\uffff\u0000\u00e1"+
		"\u011f\u0001\u0000\u0000\u0000\u00e2\u00e3\u0003\f\u0006\u0000\u00e3\u00e4"+
		"\u0006\f\uffff\uffff\u0000\u00e4\u011f\u0001\u0000\u0000\u0000\u00e5\u00e6"+
		"\u0005\u0007\u0000\u0000\u00e6\u00e7\u0005\u0011\u0000\u0000\u00e7\u00e8"+
		"\u0003\u001a\r\u0000\u00e8\u00e9\u0003\u001a\r\u0000\u00e9\u00ea\u0003"+
		"\u001e\u000f\u0000\u00ea\u00eb\u0005\u0012\u0000\u0000\u00eb\u00ec\u0003"+
		"\u0018\f\u0000\u00ec\u00ed\u0006\f\uffff\uffff\u0000\u00ed\u011f\u0001"+
		"\u0000\u0000\u0000\u00ee\u00ef\u0005\u0005\u0000\u0000\u00ef\u00f0\u0005"+
		"\u0011\u0000\u0000\u00f0\u00f1\u0003\u001e\u000f\u0000\u00f1\u00f2\u0005"+
		"\u0012\u0000\u0000\u00f2\u00f3\u0003\u0018\f\u0000\u00f3\u00f4\u0006\f"+
		"\uffff\uffff\u0000\u00f4\u011f\u0001\u0000\u0000\u0000\u00f5\u00f6\u0005"+
		"\u0005\u0000\u0000\u00f6\u00f7\u0005\u0011\u0000\u0000\u00f7\u00f8\u0003"+
		"\u001e\u000f\u0000\u00f8\u00f9\u0005\u0012\u0000\u0000\u00f9\u00fa\u0003"+
		"\u0018\f\u0000\u00fa\u00fb\u0005\u0006\u0000\u0000\u00fb\u00fc\u0003\u0018"+
		"\f\u0000\u00fc\u00fd\u0006\f\uffff\uffff\u0000\u00fd\u011f\u0001\u0000"+
		"\u0000\u0000\u00fe\u00ff\u0005\b\u0000\u0000\u00ff\u0100\u0005\u0011\u0000"+
		"\u0000\u0100\u0101\u0003\u001e\u000f\u0000\u0101\u0102\u0005\u0012\u0000"+
		"\u0000\u0102\u0103\u0003\u0018\f\u0000\u0103\u0104\u0006\f\uffff\uffff"+
		"\u0000\u0104\u011f\u0001\u0000\u0000\u0000\u0105\u0106\u0005\t\u0000\u0000"+
		"\u0106\u0107\u0005\u0011\u0000\u0000\u0107\u0108\u0005\"\u0000\u0000\u0108"+
		"\u0109\u0005\u0012\u0000\u0000\u0109\u010a\u0005\u0017\u0000\u0000\u010a"+
		"\u011f\u0006\f\uffff\uffff\u0000\u010b\u010c\u0005\n\u0000\u0000\u010c"+
		"\u010d\u0003\u001e\u000f\u0000\u010d\u010e\u0005\u0017\u0000\u0000\u010e"+
		"\u010f\u0006\f\uffff\uffff\u0000\u010f\u011f\u0001\u0000\u0000\u0000\u0110"+
		"\u0111\u0005\u000f\u0000\u0000\u0111\u0112\u0005\u0017\u0000\u0000\u0112"+
		"\u011f\u0006\f\uffff\uffff\u0000\u0113\u0114\u0005\u0010\u0000\u0000\u0114"+
		"\u0115\u0005\u0017\u0000\u0000\u0115\u011f\u0006\f\uffff\uffff\u0000\u0116"+
		"\u0117\u0005\u000e\u0000\u0000\u0117\u0118\u0003\f\u0006\u0000\u0118\u0119"+
		"\u0005\b\u0000\u0000\u0119\u011a\u0005\u0011\u0000\u0000\u011a\u011b\u0003"+
		"\u001e\u000f\u0000\u011b\u011c\u0005\u0012\u0000\u0000\u011c\u011d\u0006"+
		"\f\uffff\uffff\u0000\u011d\u011f\u0001\u0000\u0000\u0000\u011e\u00dc\u0001"+
		"\u0000\u0000\u0000\u011e\u00df\u0001\u0000\u0000\u0000\u011e\u00e2\u0001"+
		"\u0000\u0000\u0000\u011e\u00e5\u0001\u0000\u0000\u0000\u011e\u00ee\u0001"+
		"\u0000\u0000\u0000\u011e\u00f5\u0001\u0000\u0000\u0000\u011e\u00fe\u0001"+
		"\u0000\u0000\u0000\u011e\u0105\u0001\u0000\u0000\u0000\u011e\u010b\u0001"+
		"\u0000\u0000\u0000\u011e\u0110\u0001\u0000\u0000\u0000\u011e\u0113\u0001"+
		"\u0000\u0000\u0000\u011e\u0116\u0001\u0000\u0000\u0000\u011f\u0019\u0001"+
		"\u0000\u0000\u0000\u0120\u0121\u0005\u0017\u0000\u0000\u0121\u0127\u0006"+
		"\r\uffff\uffff\u0000\u0122\u0123\u0003\u001e\u000f\u0000\u0123\u0124\u0005"+
		"\u0017\u0000\u0000\u0124\u0125\u0006\r\uffff\uffff\u0000\u0125\u0127\u0001"+
		"\u0000\u0000\u0000\u0126\u0120\u0001\u0000\u0000\u0000\u0126\u0122\u0001"+
		"\u0000\u0000\u0000\u0127\u001b\u0001\u0000\u0000\u0000\u0128\u0129\u0005"+
		"\"\u0000\u0000\u0129\u0131\u0006\u000e\uffff\uffff\u0000\u012a\u012b\u0005"+
		"\"\u0000\u0000\u012b\u012c\u0005\u0015\u0000\u0000\u012c\u012d\u0003\u001e"+
		"\u000f\u0000\u012d\u012e\u0005\u0016\u0000\u0000\u012e\u012f\u0006\u000e"+
		"\uffff\uffff\u0000\u012f\u0131\u0001\u0000\u0000\u0000\u0130\u0128\u0001"+
		"\u0000\u0000\u0000\u0130\u012a\u0001\u0000\u0000\u0000\u0131\u001d\u0001"+
		"\u0000\u0000\u0000\u0132\u0133\u0003 \u0010\u0000\u0133\u0134\u0006\u000f"+
		"\uffff\uffff\u0000\u0134\u013b\u0001\u0000\u0000\u0000\u0135\u0136\u0003"+
		"\u001c\u000e\u0000\u0136\u0137\u0005!\u0000\u0000\u0137\u0138\u0003 \u0010"+
		"\u0000\u0138\u0139\u0006\u000f\uffff\uffff\u0000\u0139\u013b\u0001\u0000"+
		"\u0000\u0000\u013a\u0132\u0001\u0000\u0000\u0000\u013a\u0135\u0001\u0000"+
		"\u0000\u0000\u013b\u001f\u0001\u0000\u0000\u0000\u013c\u013d\u0003\"\u0011"+
		"\u0000\u013d\u013e\u0006\u0010\uffff\uffff\u0000\u013e\u0145\u0001\u0000"+
		"\u0000\u0000\u013f\u0140\u0003\"\u0011\u0000\u0140\u0141\u0005 \u0000"+
		"\u0000\u0141\u0142\u0003\"\u0011\u0000\u0142\u0143\u0006\u0010\uffff\uffff"+
		"\u0000\u0143\u0145\u0001\u0000\u0000\u0000\u0144\u013c\u0001\u0000\u0000"+
		"\u0000\u0144\u013f\u0001\u0000\u0000\u0000\u0145!\u0001\u0000\u0000\u0000"+
		"\u0146\u0147\u0003$\u0012\u0000\u0147\u0148\u0006\u0011\uffff\uffff\u0000"+
		"\u0148\u014f\u0001\u0000\u0000\u0000\u0149\u014a\u0003$\u0012\u0000\u014a"+
		"\u014b\u0005\u001f\u0000\u0000\u014b\u014c\u0003$\u0012\u0000\u014c\u014d"+
		"\u0006\u0011\uffff\uffff\u0000\u014d\u014f\u0001\u0000\u0000\u0000\u014e"+
		"\u0146\u0001\u0000\u0000\u0000\u014e\u0149\u0001\u0000\u0000\u0000\u014f"+
		"#\u0001\u0000\u0000\u0000\u0150\u0151\u0006\u0012\uffff\uffff\u0000\u0151"+
		"\u0152\u0003&\u0013\u0000\u0152\u0153\u0006\u0012\uffff\uffff\u0000\u0153"+
		"\u015b\u0001\u0000\u0000\u0000\u0154\u0155\n\u0001\u0000\u0000\u0155\u0156"+
		"\u0005\u0019\u0000\u0000\u0156\u0157\u0003&\u0013\u0000\u0157\u0158\u0006"+
		"\u0012\uffff\uffff\u0000\u0158\u015a\u0001\u0000\u0000\u0000\u0159\u0154"+
		"\u0001\u0000\u0000\u0000\u015a\u015d\u0001\u0000\u0000\u0000\u015b\u0159"+
		"\u0001\u0000\u0000\u0000\u015b\u015c\u0001\u0000\u0000\u0000\u015c%\u0001"+
		"\u0000\u0000\u0000\u015d\u015b\u0001\u0000\u0000\u0000\u015e\u015f\u0006"+
		"\u0013\uffff\uffff\u0000\u015f\u0160\u0003(\u0014\u0000\u0160\u0161\u0006"+
		"\u0013\uffff\uffff\u0000\u0161\u0169\u0001\u0000\u0000\u0000\u0162\u0163"+
		"\n\u0001\u0000\u0000\u0163\u0164\u0005\u001b\u0000\u0000\u0164\u0165\u0003"+
		"(\u0014\u0000\u0165\u0166\u0006\u0013\uffff\uffff\u0000\u0166\u0168\u0001"+
		"\u0000\u0000\u0000\u0167\u0162\u0001\u0000\u0000\u0000\u0168\u016b\u0001"+
		"\u0000\u0000\u0000\u0169\u0167\u0001\u0000\u0000\u0000\u0169\u016a\u0001"+
		"\u0000\u0000\u0000\u016a\'\u0001\u0000\u0000\u0000\u016b\u0169\u0001\u0000"+
		"\u0000\u0000\u016c\u016d\u0005\u0019\u0000\u0000\u016d\u016e\u0003(\u0014"+
		"\u0000\u016e\u016f\u0006\u0014\uffff\uffff\u0000\u016f\u0178\u0001\u0000"+
		"\u0000\u0000\u0170\u0171\u0005\u001e\u0000\u0000\u0171\u0172\u0003(\u0014"+
		"\u0000\u0172\u0173\u0006\u0014\uffff\uffff\u0000\u0173\u0178\u0001\u0000"+
		"\u0000\u0000\u0174\u0175\u0003*\u0015\u0000\u0175\u0176\u0006\u0014\uffff"+
		"\uffff\u0000\u0176\u0178\u0001\u0000\u0000\u0000\u0177\u016c\u0001\u0000"+
		"\u0000\u0000\u0177\u0170\u0001\u0000\u0000\u0000\u0177\u0174\u0001\u0000"+
		"\u0000\u0000\u0178)\u0001\u0000\u0000\u0000\u0179\u017a\u0003\u001c\u000e"+
		"\u0000\u017a\u017b\u0006\u0015\uffff\uffff\u0000\u017b\u0194\u0001\u0000"+
		"\u0000\u0000\u017c\u017d\u0005\"\u0000\u0000\u017d\u017e\u0005\u0011\u0000"+
		"\u0000\u017e\u017f\u0003,\u0016\u0000\u017f\u0180\u0005\u0012\u0000\u0000"+
		"\u0180\u0181\u0006\u0015\uffff\uffff\u0000\u0181\u0194\u0001\u0000\u0000"+
		"\u0000\u0182\u0183\u0005\u0011\u0000\u0000\u0183\u0184\u0003\u001e\u000f"+
		"\u0000\u0184\u0185\u0005\u0012\u0000\u0000\u0185\u0186\u0006\u0015\uffff"+
		"\uffff\u0000\u0186\u0194\u0001\u0000\u0000\u0000\u0187\u0188\u0005#\u0000"+
		"\u0000\u0188\u0194\u0006\u0015\uffff\uffff\u0000\u0189\u018a\u0005$\u0000"+
		"\u0000\u018a\u0194\u0006\u0015\uffff\uffff\u0000\u018b\u018c\u0003\u001c"+
		"\u000e\u0000\u018c\u018d\u0005\u001c\u0000\u0000\u018d\u018e\u0006\u0015"+
		"\uffff\uffff\u0000\u018e\u0194\u0001\u0000\u0000\u0000\u018f\u0190\u0003"+
		"\u001c\u000e\u0000\u0190\u0191\u0005\u001d\u0000\u0000\u0191\u0192\u0006"+
		"\u0015\uffff\uffff\u0000\u0192\u0194\u0001\u0000\u0000\u0000\u0193\u0179"+
		"\u0001\u0000\u0000\u0000\u0193\u017c\u0001\u0000\u0000\u0000\u0193\u0182"+
		"\u0001\u0000\u0000\u0000\u0193\u0187\u0001\u0000\u0000\u0000\u0193\u0189"+
		"\u0001\u0000\u0000\u0000\u0193\u018b\u0001\u0000\u0000\u0000\u0193\u018f"+
		"\u0001\u0000\u0000\u0000\u0194+\u0001\u0000\u0000\u0000\u0195\u0196\u0003"+
		".\u0017\u0000\u0196\u0197\u0006\u0016\uffff\uffff\u0000\u0197\u019a\u0001"+
		"\u0000\u0000\u0000\u0198\u019a\u0001\u0000\u0000\u0000\u0199\u0195\u0001"+
		"\u0000\u0000\u0000\u0199\u0198\u0001\u0000\u0000\u0000\u019a-\u0001\u0000"+
		"\u0000\u0000\u019b\u019c\u0006\u0017\uffff\uffff\u0000\u019c\u019d\u0003"+
		" \u0010\u0000\u019d\u019e\u0006\u0017\uffff\uffff\u0000\u019e\u01a6\u0001"+
		"\u0000\u0000\u0000\u019f\u01a0\n\u0002\u0000\u0000\u01a0\u01a1\u0005\u0018"+
		"\u0000\u0000\u01a1\u01a2\u0003 \u0010\u0000\u01a2\u01a3\u0006\u0017\uffff"+
		"\uffff\u0000\u01a3\u01a5\u0001\u0000\u0000\u0000\u01a4\u019f\u0001\u0000"+
		"\u0000\u0000\u01a5\u01a8\u0001\u0000\u0000\u0000\u01a6\u01a4\u0001\u0000"+
		"\u0000\u0000\u01a6\u01a7\u0001\u0000\u0000\u0000\u01a7/\u0001\u0000\u0000"+
		"\u0000\u01a8\u01a6\u0001\u0000\u0000\u0000\u001a=IZpz\u0087\u0089\u0096"+
		"\u00a9\u00b3\u00bd\u00ca\u00cc\u00d9\u011e\u0126\u0130\u013a\u0144\u014e"+
		"\u015b\u0169\u0177\u0193\u0199\u01a6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}