
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


#include "C2105118ParserListener.h"

#include "C2105118Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105118ParserStaticData final {
  C2105118ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105118ParserStaticData(const C2105118ParserStaticData&) = delete;
  C2105118ParserStaticData(C2105118ParserStaticData&&) = delete;
  C2105118ParserStaticData& operator=(const C2105118ParserStaticData&) = delete;
  C2105118ParserStaticData& operator=(C2105118ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105118parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105118ParserStaticData> c2105118parserParserStaticData = nullptr;

void c2105118parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105118parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105118parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105118ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
      "type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,33,405,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,91,
  	8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,3,4,113,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,123,8,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,136,8,5,10,5,12,5,139,
  	9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,151,8,6,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,163,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,
  	3,9,173,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,183,8,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,196,8,10,10,10,
  	12,10,199,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,209,8,11,
  	10,11,12,11,212,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	3,12,266,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,274,8,13,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,3,14,284,8,14,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,3,15,294,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,
  	16,304,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,314,8,17,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,325,8,18,10,18,12,18,328,
  	9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,339,8,19,10,19,
  	12,19,342,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	3,20,355,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,3,21,383,8,21,1,22,1,22,1,22,1,22,3,22,389,8,22,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,5,23,400,8,23,10,23,12,23,403,9,23,1,23,0,
  	7,2,10,20,22,36,38,46,24,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,0,0,421,0,48,1,0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,
  	90,1,0,0,0,8,112,1,0,0,0,10,122,1,0,0,0,12,150,1,0,0,0,14,162,1,0,0,0,
  	16,164,1,0,0,0,18,172,1,0,0,0,20,182,1,0,0,0,22,200,1,0,0,0,24,265,1,
  	0,0,0,26,273,1,0,0,0,28,283,1,0,0,0,30,293,1,0,0,0,32,303,1,0,0,0,34,
  	313,1,0,0,0,36,315,1,0,0,0,38,329,1,0,0,0,40,354,1,0,0,0,42,382,1,0,0,
  	0,44,388,1,0,0,0,46,390,1,0,0,0,48,49,3,2,1,0,49,50,6,0,-1,0,50,1,1,0,
  	0,0,51,52,6,1,-1,0,52,53,3,4,2,0,53,54,6,1,-1,0,54,61,1,0,0,0,55,56,10,
  	2,0,0,56,57,3,4,2,0,57,58,6,1,-1,0,58,60,1,0,0,0,59,55,1,0,0,0,60,63,
  	1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,3,1,0,0,0,63,61,1,0,0,0,64,65,
  	3,14,7,0,65,66,6,2,-1,0,66,74,1,0,0,0,67,68,3,6,3,0,68,69,6,2,-1,0,69,
  	74,1,0,0,0,70,71,3,8,4,0,71,72,6,2,-1,0,72,74,1,0,0,0,73,64,1,0,0,0,73,
  	67,1,0,0,0,73,70,1,0,0,0,74,5,1,0,0,0,75,76,3,18,9,0,76,77,5,31,0,0,77,
  	78,5,14,0,0,78,79,3,10,5,0,79,80,5,15,0,0,80,81,5,20,0,0,81,82,6,3,-1,
  	0,82,91,1,0,0,0,83,84,3,18,9,0,84,85,5,31,0,0,85,86,5,14,0,0,86,87,5,
  	15,0,0,87,88,5,20,0,0,88,89,6,3,-1,0,89,91,1,0,0,0,90,75,1,0,0,0,90,83,
  	1,0,0,0,91,7,1,0,0,0,92,93,3,18,9,0,93,94,5,31,0,0,94,95,6,4,-1,0,95,
  	96,5,14,0,0,96,97,6,4,-1,0,97,98,3,10,5,0,98,99,6,4,-1,0,99,100,5,15,
  	0,0,100,101,3,12,6,0,101,102,6,4,-1,0,102,113,1,0,0,0,103,104,3,18,9,
  	0,104,105,5,31,0,0,105,106,6,4,-1,0,106,107,5,14,0,0,107,108,6,4,-1,0,
  	108,109,5,15,0,0,109,110,3,12,6,0,110,111,6,4,-1,0,111,113,1,0,0,0,112,
  	92,1,0,0,0,112,103,1,0,0,0,113,9,1,0,0,0,114,115,6,5,-1,0,115,116,3,18,
  	9,0,116,117,5,31,0,0,117,118,6,5,-1,0,118,123,1,0,0,0,119,120,3,18,9,
  	0,120,121,6,5,-1,0,121,123,1,0,0,0,122,114,1,0,0,0,122,119,1,0,0,0,123,
  	137,1,0,0,0,124,125,10,4,0,0,125,126,5,21,0,0,126,127,3,18,9,0,127,128,
  	5,31,0,0,128,129,6,5,-1,0,129,136,1,0,0,0,130,131,10,3,0,0,131,132,5,
  	21,0,0,132,133,3,18,9,0,133,134,6,5,-1,0,134,136,1,0,0,0,135,124,1,0,
  	0,0,135,130,1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,
  	11,1,0,0,0,139,137,1,0,0,0,140,141,5,16,0,0,141,142,6,6,-1,0,142,143,
  	3,22,11,0,143,144,5,17,0,0,144,145,6,6,-1,0,145,151,1,0,0,0,146,147,5,
  	16,0,0,147,148,6,6,-1,0,148,149,5,17,0,0,149,151,6,6,-1,0,150,140,1,0,
  	0,0,150,146,1,0,0,0,151,13,1,0,0,0,152,153,3,18,9,0,153,154,3,20,10,0,
  	154,155,5,20,0,0,155,156,6,7,-1,0,156,163,1,0,0,0,157,158,3,18,9,0,158,
  	159,3,16,8,0,159,160,5,20,0,0,160,161,6,7,-1,0,161,163,1,0,0,0,162,152,
  	1,0,0,0,162,157,1,0,0,0,163,15,1,0,0,0,164,165,6,8,-1,0,165,17,1,0,0,
  	0,166,167,5,11,0,0,167,173,6,9,-1,0,168,169,5,12,0,0,169,173,6,9,-1,0,
  	170,171,5,13,0,0,171,173,6,9,-1,0,172,166,1,0,0,0,172,168,1,0,0,0,172,
  	170,1,0,0,0,173,19,1,0,0,0,174,175,6,10,-1,0,175,176,5,31,0,0,176,183,
  	6,10,-1,0,177,178,5,31,0,0,178,179,5,18,0,0,179,180,5,32,0,0,180,181,
  	5,19,0,0,181,183,6,10,-1,0,182,174,1,0,0,0,182,177,1,0,0,0,183,197,1,
  	0,0,0,184,185,10,4,0,0,185,186,5,21,0,0,186,187,5,31,0,0,187,196,6,10,
  	-1,0,188,189,10,3,0,0,189,190,5,21,0,0,190,191,5,31,0,0,191,192,5,18,
  	0,0,192,193,5,32,0,0,193,194,5,19,0,0,194,196,6,10,-1,0,195,184,1,0,0,
  	0,195,188,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,
  	21,1,0,0,0,199,197,1,0,0,0,200,201,6,11,-1,0,201,202,3,24,12,0,202,203,
  	6,11,-1,0,203,210,1,0,0,0,204,205,10,1,0,0,205,206,3,24,12,0,206,207,
  	6,11,-1,0,207,209,1,0,0,0,208,204,1,0,0,0,209,212,1,0,0,0,210,208,1,0,
  	0,0,210,211,1,0,0,0,211,23,1,0,0,0,212,210,1,0,0,0,213,214,3,14,7,0,214,
  	215,6,12,-1,0,215,266,1,0,0,0,216,217,3,26,13,0,217,218,6,12,-1,0,218,
  	266,1,0,0,0,219,220,3,12,6,0,220,221,6,12,-1,0,221,266,1,0,0,0,222,223,
  	5,7,0,0,223,224,5,14,0,0,224,225,3,26,13,0,225,226,3,26,13,0,226,227,
  	3,30,15,0,227,228,5,15,0,0,228,229,3,24,12,0,229,230,6,12,-1,0,230,266,
  	1,0,0,0,231,232,5,5,0,0,232,233,5,14,0,0,233,234,3,30,15,0,234,235,5,
  	15,0,0,235,236,3,24,12,0,236,237,6,12,-1,0,237,266,1,0,0,0,238,239,5,
  	5,0,0,239,240,5,14,0,0,240,241,3,30,15,0,241,242,5,15,0,0,242,243,3,24,
  	12,0,243,244,5,6,0,0,244,245,3,24,12,0,245,246,6,12,-1,0,246,266,1,0,
  	0,0,247,248,5,8,0,0,248,249,5,14,0,0,249,250,3,30,15,0,250,251,5,15,0,
  	0,251,252,3,24,12,0,252,253,6,12,-1,0,253,266,1,0,0,0,254,255,5,9,0,0,
  	255,256,5,14,0,0,256,257,5,31,0,0,257,258,5,15,0,0,258,259,5,20,0,0,259,
  	266,6,12,-1,0,260,261,5,10,0,0,261,262,3,30,15,0,262,263,5,20,0,0,263,
  	264,6,12,-1,0,264,266,1,0,0,0,265,213,1,0,0,0,265,216,1,0,0,0,265,219,
  	1,0,0,0,265,222,1,0,0,0,265,231,1,0,0,0,265,238,1,0,0,0,265,247,1,0,0,
  	0,265,254,1,0,0,0,265,260,1,0,0,0,266,25,1,0,0,0,267,268,5,20,0,0,268,
  	274,6,13,-1,0,269,270,3,30,15,0,270,271,5,20,0,0,271,272,6,13,-1,0,272,
  	274,1,0,0,0,273,267,1,0,0,0,273,269,1,0,0,0,274,27,1,0,0,0,275,276,5,
  	31,0,0,276,284,6,14,-1,0,277,278,5,31,0,0,278,279,5,18,0,0,279,280,3,
  	30,15,0,280,281,5,19,0,0,281,282,6,14,-1,0,282,284,1,0,0,0,283,275,1,
  	0,0,0,283,277,1,0,0,0,284,29,1,0,0,0,285,286,3,32,16,0,286,287,6,15,-1,
  	0,287,294,1,0,0,0,288,289,3,28,14,0,289,290,5,30,0,0,290,291,3,32,16,
  	0,291,292,6,15,-1,0,292,294,1,0,0,0,293,285,1,0,0,0,293,288,1,0,0,0,294,
  	31,1,0,0,0,295,296,3,34,17,0,296,297,6,16,-1,0,297,304,1,0,0,0,298,299,
  	3,34,17,0,299,300,5,29,0,0,300,301,3,34,17,0,301,302,6,16,-1,0,302,304,
  	1,0,0,0,303,295,1,0,0,0,303,298,1,0,0,0,304,33,1,0,0,0,305,306,3,36,18,
  	0,306,307,6,17,-1,0,307,314,1,0,0,0,308,309,3,36,18,0,309,310,5,28,0,
  	0,310,311,3,36,18,0,311,312,6,17,-1,0,312,314,1,0,0,0,313,305,1,0,0,0,
  	313,308,1,0,0,0,314,35,1,0,0,0,315,316,6,18,-1,0,316,317,3,38,19,0,317,
  	318,6,18,-1,0,318,326,1,0,0,0,319,320,10,1,0,0,320,321,5,22,0,0,321,322,
  	3,38,19,0,322,323,6,18,-1,0,323,325,1,0,0,0,324,319,1,0,0,0,325,328,1,
  	0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,37,1,0,0,0,328,326,1,0,0,0,
  	329,330,6,19,-1,0,330,331,3,40,20,0,331,332,6,19,-1,0,332,340,1,0,0,0,
  	333,334,10,1,0,0,334,335,5,24,0,0,335,336,3,40,20,0,336,337,6,19,-1,0,
  	337,339,1,0,0,0,338,333,1,0,0,0,339,342,1,0,0,0,340,338,1,0,0,0,340,341,
  	1,0,0,0,341,39,1,0,0,0,342,340,1,0,0,0,343,344,5,22,0,0,344,345,3,40,
  	20,0,345,346,6,20,-1,0,346,355,1,0,0,0,347,348,5,27,0,0,348,349,3,40,
  	20,0,349,350,6,20,-1,0,350,355,1,0,0,0,351,352,3,42,21,0,352,353,6,20,
  	-1,0,353,355,1,0,0,0,354,343,1,0,0,0,354,347,1,0,0,0,354,351,1,0,0,0,
  	355,41,1,0,0,0,356,357,3,28,14,0,357,358,6,21,-1,0,358,383,1,0,0,0,359,
  	360,5,31,0,0,360,361,5,14,0,0,361,362,3,44,22,0,362,363,5,15,0,0,363,
  	364,6,21,-1,0,364,383,1,0,0,0,365,366,5,14,0,0,366,367,3,30,15,0,367,
  	368,5,15,0,0,368,369,6,21,-1,0,369,383,1,0,0,0,370,371,5,32,0,0,371,383,
  	6,21,-1,0,372,373,5,33,0,0,373,383,6,21,-1,0,374,375,3,28,14,0,375,376,
  	5,25,0,0,376,377,6,21,-1,0,377,383,1,0,0,0,378,379,3,28,14,0,379,380,
  	5,26,0,0,380,381,6,21,-1,0,381,383,1,0,0,0,382,356,1,0,0,0,382,359,1,
  	0,0,0,382,365,1,0,0,0,382,370,1,0,0,0,382,372,1,0,0,0,382,374,1,0,0,0,
  	382,378,1,0,0,0,383,43,1,0,0,0,384,385,3,46,23,0,385,386,6,22,-1,0,386,
  	389,1,0,0,0,387,389,1,0,0,0,388,384,1,0,0,0,388,387,1,0,0,0,389,45,1,
  	0,0,0,390,391,6,23,-1,0,391,392,3,32,16,0,392,393,6,23,-1,0,393,401,1,
  	0,0,0,394,395,10,2,0,0,395,396,5,21,0,0,396,397,3,32,16,0,397,398,6,23,
  	-1,0,398,400,1,0,0,0,399,394,1,0,0,0,400,403,1,0,0,0,401,399,1,0,0,0,
  	401,402,1,0,0,0,402,47,1,0,0,0,403,401,1,0,0,0,26,61,73,90,112,122,135,
  	137,150,162,172,182,195,197,210,265,273,283,293,303,313,326,340,354,382,
  	388,401
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105118parserParserStaticData = std::move(staticData);
}

}

C2105118Parser::C2105118Parser(TokenStream *input) : C2105118Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105118Parser::C2105118Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105118Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105118parserParserStaticData->atn, c2105118parserParserStaticData->decisionToDFA, c2105118parserParserStaticData->sharedContextCache, options);
}

C2105118Parser::~C2105118Parser() {
  delete _interpreter;
}

const atn::ATN& C2105118Parser::getATN() const {
  return *c2105118parserParserStaticData->atn;
}

std::string C2105118Parser::getGrammarFileName() const {
  return "C2105118Parser.g4";
}

const std::vector<std::string>& C2105118Parser::getRuleNames() const {
  return c2105118parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105118Parser::getVocabulary() const {
  return c2105118parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105118Parser::getSerializedATN() const {
  return c2105118parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105118Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::ProgramContext* C2105118Parser::StartContext::program() {
  return getRuleContext<C2105118Parser::ProgramContext>(0);
}


size_t C2105118Parser::StartContext::getRuleIndex() const {
  return C2105118Parser::RuleStart;
}

void C2105118Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105118Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C2105118Parser::StartContext* C2105118Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105118Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<StartContext *>(_localctx)->programContext = program(0);

    		std::string message = "Line "+ std::to_string(antlrcpp::downCast<StartContext *>(_localctx)->programContext->line_number) + ": start : program\n\n";
    		writeIntoparserLogFile(message, 0);
    		printSymbolTable();
    		message="";
    		message += "Total number of lines: " + std::to_string(antlrcpp::downCast<StartContext *>(_localctx)->programContext->line_number) + "\n";
    		message += "Total number of errors: " + std::to_string(syntaxErrorCount) + "\n";
    		writeIntoparserLogFile(message, 0);
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105118Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::UnitContext* C2105118Parser::ProgramContext::unit() {
  return getRuleContext<C2105118Parser::UnitContext>(0);
}

C2105118Parser::ProgramContext* C2105118Parser::ProgramContext::program() {
  return getRuleContext<C2105118Parser::ProgramContext>(0);
}


size_t C2105118Parser::ProgramContext::getRuleIndex() const {
  return C2105118Parser::RuleProgram;
}

void C2105118Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105118Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C2105118Parser::ProgramContext* C2105118Parser::program() {
   return program(0);
}

C2105118Parser::ProgramContext* C2105118Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105118Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105118Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext = unit();

    		std:: string message = "Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number) + ": program : unit";
    		message += "\n\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
    		antlrcpp::downCast<ProgramContext *>(_localctx)->unit_name =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
    		antlrcpp::downCast<ProgramContext *>(_localctx)->line_number =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number;
    		writeIntoparserLogFile(message, 2);
    	
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->pg = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext = unit();

                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number) + ": program : program unit";
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->unit_name =  antlrcpp::downCast<ProgramContext *>(_localctx)->pg->unit_name + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->line_number =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number;
                  		message += "\n\n" + _localctx->unit_name ;
                  		writeIntoparserLogFile(message, 2);
                  	 
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105118Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Var_declarationContext* C2105118Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105118Parser::Var_declarationContext>(0);
}

C2105118Parser::Func_declarationContext* C2105118Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105118Parser::Func_declarationContext>(0);
}

C2105118Parser::Func_definitionContext* C2105118Parser::UnitContext::func_definition() {
  return getRuleContext<C2105118Parser::Func_definitionContext>(0);
}


size_t C2105118Parser::UnitContext::getRuleIndex() const {
  return C2105118Parser::RuleUnit;
}

void C2105118Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105118Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C2105118Parser::UnitContext* C2105118Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105118Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();

      		std::string message = "Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->vd->line_number) + ": unit : var_declaration";
      		message += "\n\n" + antlrcpp::downCast<UnitContext *>(_localctx)->vd->var_name;
      		antlrcpp::downCast<UnitContext *>(_localctx)->unit_name =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->var_name ;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line_number =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->line_number;
      		writeIntoparserLogFile(message, 2);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->func_declarationContext = func_declaration();

      		std::string message = "Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->func_declarationContext->line_number) + ": unit : func_declaration";
      		message += "\n\n" + antlrcpp::downCast<UnitContext *>(_localctx)->func_declarationContext->unit_name ;
      		antlrcpp::downCast<UnitContext *>(_localctx)->unit_name =  antlrcpp::downCast<UnitContext *>(_localctx)->func_declarationContext->unit_name;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line_number =  antlrcpp::downCast<UnitContext *>(_localctx)->func_declarationContext->line_number;
      		writeIntoparserLogFile(message, 2);
      	
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->func_definitionContext = func_definition();

      		std::string message = "Line " + std::to_string(antlrcpp::downCast<UnitContext *>(_localctx)->func_definitionContext->line_number) + ": unit : func_definition";
      		message += "\n\n" + antlrcpp::downCast<UnitContext *>(_localctx)->func_definitionContext->unit_name ;
      		antlrcpp::downCast<UnitContext *>(_localctx)->unit_name =  antlrcpp::downCast<UnitContext *>(_localctx)->func_definitionContext->unit_name;
      		antlrcpp::downCast<UnitContext *>(_localctx)->line_number =  antlrcpp::downCast<UnitContext *>(_localctx)->func_definitionContext->line_number;
      		writeIntoparserLogFile(message, 2);
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105118Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Type_specifierContext* C2105118Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105118Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105118Parser::Func_declarationContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105118Parser::LPAREN, 0);
}

C2105118Parser::Parameter_listContext* C2105118Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105118Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105118Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105118Parser::RPAREN, 0);
}

tree::TerminalNode* C2105118Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105118Parser::SEMICOLON, 0);
}


size_t C2105118Parser::Func_declarationContext::getRuleIndex() const {
  return C2105118Parser::RuleFunc_declaration;
}

void C2105118Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105118Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C2105118Parser::Func_declarationContext* C2105118Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105118Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(77);
      match(C2105118Parser::LPAREN);
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext = parameter_list(0);
      setState(79);
      match(C2105118Parser::RPAREN);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      			std::string var_type = antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->type;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine(),false, 1);
      		std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
      		message += "\n\n" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext->name_line + ");";
      		writeIntoparserLogFile(message, 2);
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext->name_line + ");";
      		antlrcpp::downCast<Func_declarationContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine();

      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(83);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(85);
      match(C2105118Parser::LPAREN);
      setState(86);
      match(C2105118Parser::RPAREN);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      			std::string var_type = antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->type;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine(),false, 1);
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
      			message += "\n\n" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "();";
      			writeIntoparserLogFile(message, 2);
      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "();";
      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine();
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105118Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Type_specifierContext* C2105118Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105118Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105118Parser::Func_definitionContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105118Parser::LPAREN, 0);
}

C2105118Parser::Parameter_listContext* C2105118Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105118Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105118Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105118Parser::RPAREN, 0);
}

C2105118Parser::Compound_statementContext* C2105118Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105118Parser::Compound_statementContext>(0);
}


size_t C2105118Parser::Func_definitionContext::getRuleIndex() const {
  return C2105118Parser::RuleFunc_definition;
}

void C2105118Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105118Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C2105118Parser::Func_definitionContext* C2105118Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105118Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(93);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      			
      			std::string var_type = antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->type;
      			// cout<< "var_type is: " << var_type << endl;
      			retType = var_type;
      			cout<< "retType is: " << retType << endl;
      			
      			insertIntoSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine(),false, 1);
      		
      setState(95);
      match(C2105118Parser::LPAREN);

      				func_def=1;
      				enterScope();
      			
      setState(97);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->parameter_listContext = parameter_list(0);


      				symbolInfo* sinfo = getVarType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
      				int isFunction = sinfo ? sinfo->getIsFunction() : 1;
      				if (isFunction == 0){
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      				}
      				if (sinfo != nullptr && sinfo->getType() != var_type) {
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      			}
      				
      				
      setState(99);
      match(C2105118Parser::RPAREN);
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

      			// cout<< "type_specifier is: " << antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->name_line << endl;
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->parameter_listContext->name_line + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->unit_name ;
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      			retType = "";
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      		std::string var_type = antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->type;
      		// cout<< "var_type is: " << var_type << endl;
      		retType = var_type;
      		cout<< "retType is: " << retType << endl;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine(),false, 1);
      		
      setState(106);
      match(C2105118Parser::LPAREN);

      				func_def=1;
      				enterScope();	
      		
      setState(108);
      match(C2105118Parser::RPAREN);
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

      			// cout<< "type_specifier is: " << antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->name_line << endl;
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "()" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->unit_name;
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement";
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105118Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Type_specifierContext* C2105118Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105118Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105118Parser::Parameter_listContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::Parameter_listContext::COMMA() {
  return getToken(C2105118Parser::COMMA, 0);
}

C2105118Parser::Parameter_listContext* C2105118Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105118Parser::Parameter_listContext>(0);
}


size_t C2105118Parser::Parameter_listContext::getRuleIndex() const {
  return C2105118Parser::RuleParameter_list;
}

void C2105118Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105118Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C2105118Parser::Parameter_listContext* C2105118Parser::parameter_list() {
   return parameter_list(0);
}

C2105118Parser::Parameter_listContext* C2105118Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105118Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105118Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(115);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(116);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      	// cout<< "func_def is: "<< func_def <<endl;

      	currentParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText());
      	std::string var_type = antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type;
      	if (func_def==1) {
      		insertIntoSymbolTable(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine(), false, 0,1);
      	}
      	antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
      	std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": parameter_list : type_specifier ID";
      	message += "\n\n" + _localctx->name_line;
      	writeIntoparserLogFile(message, 2);
      	
      break;
    }

    case 2: {
      setState(119);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();

      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line;
      		std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->line_number) + ": parameter_list : type_specifier";
      		message += "\n\n" + antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line;
      		writeIntoparserLogFile(message, 2);
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(137);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(135);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(124);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(125);
          match(C2105118Parser::COMMA);
          setState(126);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();
          setState(127);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

                    	// cout<< "func_def is: "<< func_def <<endl;
                    	std::string var_type = antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type;
                    	currentParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText());
                    	if (func_def==1) {
                    		insertIntoSymbolTable(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine(), false, 0,1);
                    	}
                    	// cout<<"Inserting into symbol table: "<< antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() <<"while func_def is"<<func_def<<endl;
                    	antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->name_line + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                    	std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID";
                    	message += "\n\n" + _localctx->name_line;
                    	writeIntoparserLogFile(message, 2);
                    	
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(130);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(131);
          match(C2105118Parser::COMMA);
          setState(132);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();

                    	antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->name_line + ", " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line;
                    	std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->line_number) + ": parameter_list : parameter_list COMMA type_specifier";
                    	message += "\n\n" + _localctx->name_line;
                    	writeIntoparserLogFile(message, 2);
                    	
          break;
        }

        default:
          break;
        } 
      }
      setState(139);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105118Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::Compound_statementContext::LCURL() {
  return getToken(C2105118Parser::LCURL, 0);
}

C2105118Parser::StatementsContext* C2105118Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105118Parser::StatementsContext>(0);
}

tree::TerminalNode* C2105118Parser::Compound_statementContext::RCURL() {
  return getToken(C2105118Parser::RCURL, 0);
}


size_t C2105118Parser::Compound_statementContext::getRuleIndex() const {
  return C2105118Parser::RuleCompound_statement;
}

void C2105118Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105118Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C2105118Parser::Compound_statementContext* C2105118Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105118Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      match(C2105118Parser::LCURL);

      				if (func_def==1) func_def=0;
      				else enterScope();
      			
      setState(142);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->statementsContext = statements(0);
      setState(143);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105118Parser::RCURL);

      				std::string message = "Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL statements RCURL";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->unit_name =  "{\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->statementsContext->unit_name + "\n}";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
      				message += "\n\n" + _localctx->unit_name;
      				writeIntoparserLogFile(message, 2);
      				exitScope();

      				if (antlrcpp::downCast<Compound_statementContext *>(_localctx)->statementsContext->retError) {
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": Cannot return value from function foo4 with void return type";
      					writeIntoErrorFile(errMsg);
      					message = errMsg;
      					writeIntoparserLogFile(message, 2);
      					syntaxErrorCount++	;
      				}
      			
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      match(C2105118Parser::LCURL);

      				if (func_def==1) func_def=0;
      				else enterScope();
      			
      setState(148);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105118Parser::RCURL);
       
      				func_def=0;
      				std::string message = "Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL RCURL";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->unit_name =  "{\n}";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
      				message += "\n\n" + _localctx->unit_name;
      				writeIntoparserLogFile(message, 2);
      				exitScope();

      			
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105118Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Type_specifierContext* C2105118Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105118Parser::Type_specifierContext>(0);
}

C2105118Parser::Declaration_listContext* C2105118Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105118Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105118Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105118Parser::SEMICOLON, 0);
}

C2105118Parser::Declaration_list_errContext* C2105118Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105118Parser::Declaration_list_errContext>(0);
}


size_t C2105118Parser::Var_declarationContext::getRuleIndex() const {
  return C2105118Parser::RuleVar_declaration;
}

void C2105118Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105118Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C2105118Parser::Var_declarationContext* C2105118Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105118Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(153);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(154);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      		std::string var = antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->name_line + ";";
      		std::string message = "Line "+ std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON";
      		if (antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->type == "VOID") {
      			std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void";
      			writeIntoErrorFile(errMsg);
      			message += "\n\n" + errMsg;
      			syntaxErrorCount++;
      		}
      		message += "\n\n" + var; 
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->var_name =  var;
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->line_number =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine();
      		writeIntoparserLogFile(message, 2);
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(158);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(159);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

              writeIntoErrorFile(
                  std::string("Line# ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );

              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105118Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105118Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105118Parser::RuleDeclaration_list_err;
}

void C2105118Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105118Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C2105118Parser::Declaration_list_errContext* C2105118Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105118Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
    		cout << "Error in declaration list" << endl;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105118Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::Type_specifierContext::INT() {
  return getToken(C2105118Parser::INT, 0);
}

tree::TerminalNode* C2105118Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105118Parser::FLOAT, 0);
}

tree::TerminalNode* C2105118Parser::Type_specifierContext::VOID() {
  return getToken(C2105118Parser::VOID, 0);
}


size_t C2105118Parser::Type_specifierContext::getRuleIndex() const {
  return C2105118Parser::RuleType_specifier;
}

void C2105118Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105118Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C2105118Parser::Type_specifierContext* C2105118Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105118Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105118Parser::INT);

        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "int";
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->line_number =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine();
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "INT";
        			currentType = "INT";
        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT"+ "\n\n" + antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
        			writeIntoparserLogFile(message,2);
        		
        break;
      }

      case C2105118Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105118Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "float";
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->line_number =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine();
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "FLOAT";
        			currentType = "FLOAT";
        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT"+ "\n\n" + antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
        			writeIntoparserLogFile(message,2);
                
        break;
      }

      case C2105118Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(170);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105118Parser::VOID);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "void";
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->line_number =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine();
        			antlrcpp::downCast<Type_specifierContext *>(_localctx)->type =  "VOID";
        			currentType = "VOID";
        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID"+ "\n\n" + antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
        			writeIntoparserLogFile(message,2);
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105118Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::Declaration_listContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105118Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105118Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105118Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105118Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105118Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105118Parser::Declaration_listContext::COMMA() {
  return getToken(C2105118Parser::COMMA, 0);
}

C2105118Parser::Declaration_listContext* C2105118Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105118Parser::Declaration_listContext>(0);
}


size_t C2105118Parser::Declaration_listContext::getRuleIndex() const {
  return C2105118Parser::RuleDeclaration_list;
}

void C2105118Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105118Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C2105118Parser::Declaration_listContext* C2105118Parser::declaration_list() {
   return declaration_list(0);
}

C2105118Parser::Declaration_listContext* C2105118Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105118Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105118Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(175);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() ;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID"+ "\n\n" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
      			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(), false,0);
      			writeIntoparserLogFile(message,2);
      		  
      break;
    }

    case 2: {
      setState(177);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(178);
      match(C2105118Parser::LTHIRD);
      setState(179);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);
      setState(180);
      match(C2105118Parser::RTHIRD);

      			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]";
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx->name_line;
      			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(), true,0);
      			writeIntoparserLogFile(message,2);
      		  
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(195);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(184);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(185);
          match(C2105118Parser::COMMA);
          setState(186);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->name_line +"," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID"+ "\n\n" + _localctx->name_line;
                    			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(), false,0);
                    			writeIntoparserLogFile(message,2);
                    			
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(188);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(189);
          match(C2105118Parser::COMMA);
          setState(190);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);
          setState(191);
          match(C2105118Parser::LTHIRD);
          setState(192);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);
          setState(193);
          match(C2105118Parser::RTHIRD);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->name_line + "," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]";
                    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx->name_line;
                    			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(), true);
                    			writeIntoparserLogFile(message,2);
                    		  
          break;
        }

        default:
          break;
        } 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105118Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::StatementContext* C2105118Parser::StatementsContext::statement() {
  return getRuleContext<C2105118Parser::StatementContext>(0);
}

C2105118Parser::StatementsContext* C2105118Parser::StatementsContext::statements() {
  return getRuleContext<C2105118Parser::StatementsContext>(0);
}


size_t C2105118Parser::StatementsContext::getRuleIndex() const {
  return C2105118Parser::RuleStatements;
}

void C2105118Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105118Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C2105118Parser::StatementsContext* C2105118Parser::statements() {
   return statements(0);
}

C2105118Parser::StatementsContext* C2105118Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105118Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105118Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(201);
    antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext = statement();

    			antlrcpp::downCast<StatementsContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->unit_name;
    			antlrcpp::downCast<StatementsContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number;
    			antlrcpp::downCast<StatementsContext *>(_localctx)->retError =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->retError;
    			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number) + ": statements : statement";
    			message += "\n\n" + _localctx->unit_name;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->sts = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(204);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(205);
        antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext = statement();

                  			antlrcpp::downCast<StatementsContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementsContext *>(_localctx)->sts->unit_name + "\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->unit_name;
                  			antlrcpp::downCast<StatementsContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number;
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number) + ": statements : statements statement";
                  			message += "\n\n" + _localctx->unit_name;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105118Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Var_declarationContext* C2105118Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105118Parser::Var_declarationContext>(0);
}

std::vector<C2105118Parser::Expression_statementContext *> C2105118Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105118Parser::Expression_statementContext>();
}

C2105118Parser::Expression_statementContext* C2105118Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105118Parser::Expression_statementContext>(i);
}

C2105118Parser::Compound_statementContext* C2105118Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105118Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105118Parser::StatementContext::FOR() {
  return getToken(C2105118Parser::FOR, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::LPAREN() {
  return getToken(C2105118Parser::LPAREN, 0);
}

C2105118Parser::ExpressionContext* C2105118Parser::StatementContext::expression() {
  return getRuleContext<C2105118Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105118Parser::StatementContext::RPAREN() {
  return getToken(C2105118Parser::RPAREN, 0);
}

std::vector<C2105118Parser::StatementContext *> C2105118Parser::StatementContext::statement() {
  return getRuleContexts<C2105118Parser::StatementContext>();
}

C2105118Parser::StatementContext* C2105118Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105118Parser::StatementContext>(i);
}

tree::TerminalNode* C2105118Parser::StatementContext::IF() {
  return getToken(C2105118Parser::IF, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::ELSE() {
  return getToken(C2105118Parser::ELSE, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::WHILE() {
  return getToken(C2105118Parser::WHILE, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::PRINTLN() {
  return getToken(C2105118Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::SEMICOLON() {
  return getToken(C2105118Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105118Parser::StatementContext::RETURN() {
  return getToken(C2105118Parser::RETURN, 0);
}


size_t C2105118Parser::StatementContext::getRuleIndex() const {
  return C2105118Parser::RuleStatement;
}

void C2105118Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105118Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C2105118Parser::StatementContext* C2105118Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105118Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(213);
      antlrcpp::downCast<StatementContext *>(_localctx)->var_declarationContext = var_declaration();

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->var_declarationContext->line_number) + ": statement : var_declaration";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementContext *>(_localctx)->var_declarationContext->var_name;
      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->var_declarationContext->line_number;
      			message += "\n\n" + _localctx->unit_name ;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext = expression_statement();
       
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->line_number) + ": statement : expression_statement";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->unit_name;
      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->line_number;
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      antlrcpp::downCast<StatementContext *>(_localctx)->compound_statementContext = compound_statement();

      		std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->compound_statementContext->line_number) + ": statement : compound_statement";
      		antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementContext *>(_localctx)->compound_statementContext->unit_name;
      		antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->compound_statementContext->line_number;
      		message += "\n\n" + _localctx->unit_name;
      		writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(222);
      match(C2105118Parser::FOR);
      setState(223);
      match(C2105118Parser::LPAREN);
      setState(224);
      antlrcpp::downCast<StatementContext *>(_localctx)->esa = expression_statement();
      setState(225);
      antlrcpp::downCast<StatementContext *>(_localctx)->esb = expression_statement();
      setState(226);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(227);
      match(C2105118Parser::RPAREN);
      setState(228);
      antlrcpp::downCast<StatementContext *>(_localctx)->statementContext = statement();

      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->line_number;
      			std::string message = "Line " + std::to_string(_localctx->line_number) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "for (" + antlrcpp::downCast<StatementContext *>(_localctx)->esa->unit_name + "" + antlrcpp::downCast<StatementContext *>(_localctx)->esb->unit_name + "" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->var_name + ") " + antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->unit_name;
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(231);
      match(C2105118Parser::IF);
      setState(232);
      match(C2105118Parser::LPAREN);
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(234);
      match(C2105118Parser::RPAREN);
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->st = statement();

      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->st->line_number;
      			std::string message = "Line " + std::to_string(_localctx->line_number) + ": statement : IF LPAREN expression RPAREN statement";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->var_name + ") " + antlrcpp::downCast<StatementContext *>(_localctx)->st->unit_name;
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(238);
      match(C2105118Parser::IF);
      setState(239);
      match(C2105118Parser::LPAREN);
      setState(240);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(241);
      match(C2105118Parser::RPAREN);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(243);
      match(C2105118Parser::ELSE);
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();
       
      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->s2->line_number;
      			std::string message = "Line " + std::to_string(_localctx->line_number) + ": statement : IF LPAREN expression RPAREN statement ELSE statement";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "if (" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->var_name + ") " + antlrcpp::downCast<StatementContext *>(_localctx)->s1->unit_name + " else " + antlrcpp::downCast<StatementContext *>(_localctx)->s2->unit_name;
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(247);
      match(C2105118Parser::WHILE);
      setState(248);
      match(C2105118Parser::LPAREN);
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(250);
      match(C2105118Parser::RPAREN);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->statementContext = statement();

      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->line_number;
      			std::string message = "Line " + std::to_string(_localctx->line_number) + ": statement : WHILE LPAREN expression RPAREN statement";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "while (" + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->var_name + ") " + antlrcpp::downCast<StatementContext *>(_localctx)->statementContext->unit_name;
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(254);
      match(C2105118Parser::PRINTLN);
      setState(255);
      match(C2105118Parser::LPAREN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(257);
      match(C2105118Parser::RPAREN);
      setState(258);
      match(C2105118Parser::SEMICOLON);

      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine();
      			std::string message = "Line " + std::to_string(_localctx->line_number) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON";
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
      			if (sinfo == nullptr) {
      				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText();
      				writeIntoErrorFile(errMsg);
      				message += "\n\n" + errMsg;
      				syntaxErrorCount++;
      				currentIndex = "";
      			}
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "printf(" + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ");";
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(260);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105118Parser::RETURN);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      			if (retType == "VOID") {
      				antlrcpp::downCast<StatementContext *>(_localctx)->retError =  true;
      			}
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()) + ": statement : RETURN expression SEMICOLON";
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext->var_name + ";";
      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->sm->getLine();
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105118Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105118Parser::SEMICOLON, 0);
}

C2105118Parser::ExpressionContext* C2105118Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105118Parser::ExpressionContext>(0);
}


size_t C2105118Parser::Expression_statementContext::getRuleIndex() const {
  return C2105118Parser::RuleExpression_statement;
}

void C2105118Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105118Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C2105118Parser::Expression_statementContext* C2105118Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105118Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(267);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C2105118Parser::SEMICOLON);

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON";
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->unit_name =  ";";
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine();
        			message += "\n\n" + _localctx->unit_name;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

      case C2105118Parser::LPAREN:
      case C2105118Parser::ADDOP:
      case C2105118Parser::NOT:
      case C2105118Parser::ID:
      case C2105118Parser::CONST_INT:
      case C2105118Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(269);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext = expression();
        setState(270);
        match(C2105118Parser::SEMICOLON);

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->line_number) + ": expression_statement : expression SEMICOLON";
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->unit_name =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->var_name + ";";
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->line_number;
        			message += "\n\n" + _localctx->unit_name ;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105118Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::VariableContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::VariableContext::LTHIRD() {
  return getToken(C2105118Parser::LTHIRD, 0);
}

C2105118Parser::ExpressionContext* C2105118Parser::VariableContext::expression() {
  return getRuleContext<C2105118Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105118Parser::VariableContext::RTHIRD() {
  return getToken(C2105118Parser::RTHIRD, 0);
}


size_t C2105118Parser::VariableContext::getRuleIndex() const {
  return C2105118Parser::RuleVariable;
}

void C2105118Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105118Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C2105118Parser::VariableContext* C2105118Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105118Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(275);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID";
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      			if (sinfo == nullptr) {
      				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      				writeIntoErrorFile(errMsg);
      				message += "\n\n" + errMsg;
      				syntaxErrorCount++;
      				currentIndex = "";
      			} else if(sinfo->getIsArray()){
      				currentIndex = sinfo->getType();
      				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Type mismatch, " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array";
      				writeIntoErrorFile(errMsg);
      				message += "\n\n" + errMsg;
      				syntaxErrorCount++;
      			}
      			antlrcpp::downCast<VariableContext *>(_localctx)->var_name =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      			antlrcpp::downCast<VariableContext *>(_localctx)->line_number =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
      			antlrcpp::downCast<VariableContext *>(_localctx)->trueName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      			message += "\n\n" + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      			writeIntoparserLogFile(message, 2);
      			antlrcpp::downCast<VariableContext *>(_localctx)->indexed =  false; // not indexed by default

      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(277);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(278);
      match(C2105118Parser::LTHIRD);
      setState(279);
      antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext = expression();
      setState(280);
      match(C2105118Parser::RTHIRD);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID LTHIRD expression RTHIRD";
      			antlrcpp::downCast<VariableContext *>(_localctx)->var_name =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->var_name + "]";
      			antlrcpp::downCast<VariableContext *>(_localctx)->trueName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() ;
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());

      			antlrcpp::downCast<VariableContext *>(_localctx)->line_number =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine();
      			if (sinfo != nullptr) {
      				if (!sinfo->getIsArray()){
      					 currentIndex = "";
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": "+ antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not an array";
      					writeIntoErrorFile(errMsg);
      					message += "\n\n" + errMsg;
      					syntaxErrorCount++;
      				} else {
      					
      					if (currentIndex == "CONST_FLOAT") {
      						std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Expression inside third brackets not an integer";
      						writeIntoErrorFile(errMsg);
      						message += "\n\n" + errMsg;
      						syntaxErrorCount++;
      					}
      				}
      			}

      			antlrcpp::downCast<VariableContext *>(_localctx)->indexed =  true; // indexed
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105118Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Logic_expressionContext* C2105118Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105118Parser::Logic_expressionContext>(0);
}

C2105118Parser::VariableContext* C2105118Parser::ExpressionContext::variable() {
  return getRuleContext<C2105118Parser::VariableContext>(0);
}

tree::TerminalNode* C2105118Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105118Parser::ASSIGNOP, 0);
}


size_t C2105118Parser::ExpressionContext::getRuleIndex() const {
  return C2105118Parser::RuleExpression;
}

void C2105118Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105118Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C2105118Parser::ExpressionContext* C2105118Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105118Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(285);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();
       
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->var_name =  antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->var_name;
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->line_number =  antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->line_number) + ": expression : logic_expression";
      			message += "\n\n" + antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(288);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext = variable();
      setState(289);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105118Parser::ASSIGNOP);
      setState(290);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext = logic_expression();
       
      			std::string ctype = antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->type;
      			bool indexed = antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->indexed;
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->var_name =  antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->var_name + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->var_name;
      			std::string trueName = antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->trueName;
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->line_number =  antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number;
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->trueName);
      			std::string var_type= sinfo ? sinfo->getType() : "";
      			bool isArray = sinfo ? sinfo->getIsArray() : false;
      			// cout<< "variable type is "<< var_type << "for variable " << antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->var_name << endl;
      			// cout<< "is array: " << (isArray ? "true" : "false") << endl;
      			// cout<<" current type is: " << currentIndex << endl;
      			// cout<< "current index is: " << indexed << endl;

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": expression : variable ASSIGNOP logic_expression";
      			if (ctype == "VOID") {
      				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->logic_expressionContext->line_number) + ": Void function used in expression";
      				writeIntoErrorFile(errMsg);
      				message += "\n\n" + errMsg;
      				syntaxErrorCount++;
      				currentType = "";
      			}

      			else if  (sinfo!=nullptr ){
      			if (var_type == "INT" && (currentIndex == "CONST_FLOAT"||currentIndex == "FLOAT")) {
      				if (!isArray) {
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": Type Mismatch";
      					writeIntoErrorFile(errMsg);
      					syntaxErrorCount++;
      					currentType = "";
      					message += "\n\n" + errMsg;
      				}
      				else if (!indexed) {

      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": Type Mismatch, "+ trueName + " is an array";
      					writeIntoErrorFile(errMsg);
      					syntaxErrorCount++;
      					message += "\n\n" + errMsg;
      				}
      				else{
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": Type Mismatch";
      					writeIntoErrorFile(errMsg);
      					syntaxErrorCount++;
      					message += "\n\n" + errMsg;
      				}
      			} else if (var_type == "FLOAT" && (currentIndex == "CONST_INT"||currentIndex == "INT") ) {
      				if (!isArray) {
      					// std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": Type Mismatch";
      					// writeIntoErrorFile(errMsg);
      					// syntaxErrorCount++;
      					currentType="";
      					// message += "\n\n" + errMsg;
      				}
      				else if (!indexed) {
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext->line_number) + ": Type Mismatch, "+ trueName + " is an array";
      					writeIntoErrorFile(errMsg);
      					syntaxErrorCount++;
      					message += "\n\n" + errMsg;
      				}
      			}
      			
      		}
      			

      			message += "\n\n" + _localctx->var_name ;
      			writeIntoparserLogFile(message, 2);
      	
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105118Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105118Parser::Rel_expressionContext *> C2105118Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105118Parser::Rel_expressionContext>();
}

C2105118Parser::Rel_expressionContext* C2105118Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105118Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105118Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105118Parser::LOGICOP, 0);
}


size_t C2105118Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105118Parser::RuleLogic_expression;
}

void C2105118Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105118Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C2105118Parser::Logic_expressionContext* C2105118Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105118Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(295);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();

      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->var_name;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->line_number;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->type;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->line_number) + ": logic_expression : rel_expression";
      			message += "\n\n" + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(298);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rl = antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();
      setState(299);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105118Parser::LOGICOP);
      setState(300);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();

      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rl->var_name + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext->var_name;
      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rl->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rl->line_number) + ": logic_expression : rel_expression LOGICOP rel_expression";
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105118Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105118Parser::Simple_expressionContext *> C2105118Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105118Parser::Simple_expressionContext>();
}

C2105118Parser::Simple_expressionContext* C2105118Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105118Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105118Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105118Parser::RELOP, 0);
}


size_t C2105118Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105118Parser::RuleRel_expression;
}

void C2105118Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105118Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C2105118Parser::Rel_expressionContext* C2105118Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105118Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext = simple_expression(0);

      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->var_name;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->line_number;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->type;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->line_number) + ": rel_expression : simple_expression";
      			message += "\n\n" + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->simple_expressionContext->var_name;
      			writeIntoparserLogFile(message, 2);	
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(308);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1 = simple_expression(0);
      setState(309);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105118Parser::RELOP);
      setState(310);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl2 = simple_expression(0);

      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1->var_name + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl2->var_name;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl2->line_number) + ": rel_expression : simple_expression RELOP simple_expression";
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105118Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::TermContext* C2105118Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105118Parser::TermContext>(0);
}

tree::TerminalNode* C2105118Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
}

C2105118Parser::Simple_expressionContext* C2105118Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105118Parser::Simple_expressionContext>(0);
}


size_t C2105118Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105118Parser::RuleSimple_expression;
}

void C2105118Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105118Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C2105118Parser::Simple_expressionContext* C2105118Parser::simple_expression() {
   return simple_expression(0);
}

C2105118Parser::Simple_expressionContext* C2105118Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105118Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105118Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(316);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);

    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number) + ": simple_expression : term";
    			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
    			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number;
    			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->type;
    			message += "\n\n" + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(319);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(320);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
        setState(321);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);
         
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number) + ": simple_expression : simple_expression ADDOP term";
                  			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->var_name + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
                  			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number;
                  			message += "\n\n" + _localctx->var_name;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105118Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Unary_expressionContext* C2105118Parser::TermContext::unary_expression() {
  return getRuleContext<C2105118Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105118Parser::TermContext::MULOP() {
  return getToken(C2105118Parser::MULOP, 0);
}

C2105118Parser::TermContext* C2105118Parser::TermContext::term() {
  return getRuleContext<C2105118Parser::TermContext>(0);
}


size_t C2105118Parser::TermContext::getRuleIndex() const {
  return C2105118Parser::RuleTerm;
}

void C2105118Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105118Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C2105118Parser::TermContext* C2105118Parser::term() {
   return term(0);
}

C2105118Parser::TermContext* C2105118Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105118Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105118Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(330);
    antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

    			std::string message = "Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": term : unary_expression";
    			antlrcpp::downCast<TermContext *>(_localctx)->var_name =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name;
    			antlrcpp::downCast<TermContext *>(_localctx)->line_number =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number;
    			antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->type;
    			message += "\n\n" + antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(340);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->tm = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(333);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(334);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105118Parser::MULOP);
        setState(335);
        antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

                  			// cout<<"mulop unary "<<  antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText()<< endl;
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": term : term MULOP unary_expression";
                  			if (antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->type == "VOID") {
                  				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": Void function used in expression";
                  				writeIntoErrorFile(errMsg);
                  				syntaxErrorCount++;

                  				message = message + "\n\n" + errMsg;
                  				currentIndex = "";
                  			}
                  			if (currentIndex=="CONST_FLOAT" && antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name != "0"){
                  				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": Non-Integer operand on modulus operator";
                  				writeIntoErrorFile(errMsg);
                  				syntaxErrorCount++;
                  				message= message + "\n\n" + errMsg;
                  				currentIndex = "";
                  			}
                  			if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%" && antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name == "0") {
                  				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": Modulus by Zero";
                  				writeIntoErrorFile(errMsg);
                  				syntaxErrorCount++;
                  				message= message + "\n\n" + errMsg;
                  				currentIndex = "";
                  			}
                  			antlrcpp::downCast<TermContext *>(_localctx)->var_name =  antlrcpp::downCast<TermContext *>(_localctx)->tm->var_name + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name;
                  			antlrcpp::downCast<TermContext *>(_localctx)->line_number =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number;
                  			message += "\n\n" + _localctx->var_name;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105118Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105118Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
}

C2105118Parser::Unary_expressionContext* C2105118Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105118Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105118Parser::Unary_expressionContext::NOT() {
  return getToken(C2105118Parser::NOT, 0);
}

C2105118Parser::FactorContext* C2105118Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105118Parser::FactorContext>(0);
}


size_t C2105118Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105118Parser::RuleUnary_expression;
}

void C2105118Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105118Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C2105118Parser::Unary_expressionContext* C2105118Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105118Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(354);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(343);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
        setState(344);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line_number) + ": unary_expression : ADDOP unary_expression";
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->var_name;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line_number;
        			message += "\n\n" + _localctx->var_name;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

      case C2105118Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(347);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C2105118Parser::NOT);
        setState(348);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext = unary_expression();

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line_number) + ": unary_expression : NOT unary_expression";
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->var_name;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_expressionContext->line_number;
        			message += "\n\n" + _localctx->var_name;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

      case C2105118Parser::LPAREN:
      case C2105118Parser::ID:
      case C2105118Parser::CONST_INT:
      case C2105118Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(351);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext = factor();

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->line_number) + ": unary_expression : factor";
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->var_name;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->type;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->line_number;
        			message += "\n\n" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->factorContext->var_name;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105118Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::VariableContext* C2105118Parser::FactorContext::variable() {
  return getRuleContext<C2105118Parser::VariableContext>(0);
}

tree::TerminalNode* C2105118Parser::FactorContext::ID() {
  return getToken(C2105118Parser::ID, 0);
}

tree::TerminalNode* C2105118Parser::FactorContext::LPAREN() {
  return getToken(C2105118Parser::LPAREN, 0);
}

C2105118Parser::Argument_listContext* C2105118Parser::FactorContext::argument_list() {
  return getRuleContext<C2105118Parser::Argument_listContext>(0);
}

tree::TerminalNode* C2105118Parser::FactorContext::RPAREN() {
  return getToken(C2105118Parser::RPAREN, 0);
}

C2105118Parser::ExpressionContext* C2105118Parser::FactorContext::expression() {
  return getRuleContext<C2105118Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105118Parser::FactorContext::CONST_INT() {
  return getToken(C2105118Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105118Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105118Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105118Parser::FactorContext::INCOP() {
  return getToken(C2105118Parser::INCOP, 0);
}

tree::TerminalNode* C2105118Parser::FactorContext::DECOP() {
  return getToken(C2105118Parser::DECOP, 0);
}


size_t C2105118Parser::FactorContext::getRuleIndex() const {
  return C2105118Parser::RuleFactor;
}

void C2105118Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105118Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C2105118Parser::FactorContext* C2105118Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105118Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(356);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable";
      			message += "\n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name;
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name;
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(360);
      match(C2105118Parser::LPAREN);
      setState(361);
      antlrcpp::downCast<FactorContext *>(_localctx)->argument_listContext = argument_list();
      setState(362);
      match(C2105118Parser::RPAREN);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": factor : ID LPAREN argument_list RPAREN";
      			std::string var_name = antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->argument_listContext->name_line + ")";

      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText());
      			std::string currentType = sinfo ? sinfo->getType() : "";
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  currentType;
      			if (sinfo == nullptr) {
      				std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText();
      				writeIntoErrorFile(errMsg);
      				message += "\n\n" + errMsg;
      				syntaxErrorCount++;
      				currentIndex = "";
      			}

      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->argument_listContext->name_line + ")";
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(365);
      match(C2105118Parser::LPAREN);
      setState(366);
      antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext = expression();
      setState(367);
      match(C2105118Parser::RPAREN);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext->line_number) + ": factor : LPAREN expression RPAREN";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext->var_name + ")";
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext->line_number;
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(370);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine()) + ": factor : CONST_INT";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine();
      			currentIndex = "CONST_INT";
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(372);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C2105118Parser::CONST_FLOAT);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine()) + ": factor : CONST_FLOAT";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine();
      			message += "\n\n" + _localctx->var_name;
      			currentIndex = "CONST_FLOAT";
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(374);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(375);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105118Parser::INCOP);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable INCOP";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name + antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(378);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(379);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C2105118Parser::DECOP);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable DECOP";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name + antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105118Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::ArgumentsContext* C2105118Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105118Parser::ArgumentsContext>(0);
}


size_t C2105118Parser::Argument_listContext::getRuleIndex() const {
  return C2105118Parser::RuleArgument_list;
}

void C2105118Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105118Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C2105118Parser::Argument_listContext* C2105118Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105118Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::LPAREN:
      case C2105118Parser::ADDOP:
      case C2105118Parser::NOT:
      case C2105118Parser::ID:
      case C2105118Parser::CONST_INT:
      case C2105118Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(384);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext = arguments(0);

        			antlrcpp::downCast<Argument_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->name_line;
        			antlrcpp::downCast<Argument_listContext *>(_localctx)->line_number =  antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->line_number;
        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->line_number) + ": argument_list : arguments";
        			message += "\n\n" + antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->name_line;
        			writeIntoparserLogFile(message, 2);
        			
        break;
      }

      case C2105118Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105118Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Logic_expressionContext* C2105118Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105118Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105118Parser::ArgumentsContext::COMMA() {
  return getToken(C2105118Parser::COMMA, 0);
}

C2105118Parser::ArgumentsContext* C2105118Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105118Parser::ArgumentsContext>(0);
}


size_t C2105118Parser::ArgumentsContext::getRuleIndex() const {
  return C2105118Parser::RuleArguments;
}

void C2105118Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105118Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C2105118Parser::ArgumentsContext* C2105118Parser::arguments() {
   return arguments(0);
}

C2105118Parser::ArgumentsContext* C2105118Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105118Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105118Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C2105118Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(391);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext = logic_expression();

    			antlrcpp::downCast<ArgumentsContext *>(_localctx)->name_line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name;
    			antlrcpp::downCast<ArgumentsContext *>(_localctx)->line_number =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number;
    			std::string message = "Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number) + ": arguments : logic_expression";
    			message += "\n\n" + _localctx->name_line;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(401);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->ar = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(394);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(395);
        match(C2105118Parser::COMMA);
        setState(396);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext = logic_expression();

                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->name_line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->ar->name_line + "," + antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name;
                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->line_number =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number;
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number) + ": arguments : arguments COMMA logic_expression";
                  			message += "\n\n" + _localctx->name_line;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(403);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105118Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105118Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105118parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105118parserParserOnceFlag, c2105118parserParserInitialize);
#endif
}
