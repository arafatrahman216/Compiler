
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
      "parameter_list", "parameter_list_err", "compound_statement", "var_declaration", 
      "declaration_list_err", "type_specifier", "declaration_list", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression_err", 
      "logic_expression", "rel_expression", "simple_expression", "term", 
      "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='", "", "", "", "'#'"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "HASH", "UNRECOGNIZED_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,35,451,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,5,1,64,8,1,10,1,12,1,67,9,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,3,2,78,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,3,3,97,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,132,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	3,5,142,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,155,8,5,10,
  	5,12,5,158,9,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,3,7,174,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,3,8,191,8,8,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,3,10,201,8,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,211,8,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,228,8,
  	11,10,11,12,11,231,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,5,12,
  	241,8,12,10,12,12,12,244,9,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,3,13,298,8,13,1,14,1,14,1,14,1,14,1,14,1,14,3,14,306,8,14,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,316,8,15,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,331,8,16,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,347,
  	8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,357,8,19,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,3,20,367,8,20,1,20,1,20,1,20,1,20,1,20,
  	5,20,374,8,20,10,20,12,20,377,9,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,5,21,388,8,21,10,21,12,21,391,9,21,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,3,22,404,8,22,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,432,8,23,1,24,1,24,1,24,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,5,25,446,8,25,10,25,12,25,449,
  	9,25,1,25,0,7,2,10,22,24,40,42,50,26,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,0,0,469,0,52,1,0,0,0,2,55,1,0,
  	0,0,4,77,1,0,0,0,6,96,1,0,0,0,8,131,1,0,0,0,10,141,1,0,0,0,12,159,1,0,
  	0,0,14,173,1,0,0,0,16,190,1,0,0,0,18,192,1,0,0,0,20,200,1,0,0,0,22,210,
  	1,0,0,0,24,232,1,0,0,0,26,297,1,0,0,0,28,305,1,0,0,0,30,315,1,0,0,0,32,
  	330,1,0,0,0,34,332,1,0,0,0,36,346,1,0,0,0,38,356,1,0,0,0,40,366,1,0,0,
  	0,42,378,1,0,0,0,44,403,1,0,0,0,46,431,1,0,0,0,48,433,1,0,0,0,50,436,
  	1,0,0,0,52,53,3,2,1,0,53,54,6,0,-1,0,54,1,1,0,0,0,55,56,6,1,-1,0,56,57,
  	3,4,2,0,57,58,6,1,-1,0,58,65,1,0,0,0,59,60,10,2,0,0,60,61,3,4,2,0,61,
  	62,6,1,-1,0,62,64,1,0,0,0,63,59,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,
  	66,1,0,0,0,66,3,1,0,0,0,67,65,1,0,0,0,68,69,3,16,8,0,69,70,6,2,-1,0,70,
  	78,1,0,0,0,71,72,3,6,3,0,72,73,6,2,-1,0,73,78,1,0,0,0,74,75,3,8,4,0,75,
  	76,6,2,-1,0,76,78,1,0,0,0,77,68,1,0,0,0,77,71,1,0,0,0,77,74,1,0,0,0,78,
  	5,1,0,0,0,79,80,3,20,10,0,80,81,5,31,0,0,81,82,5,14,0,0,82,83,3,10,5,
  	0,83,84,5,15,0,0,84,85,6,3,-1,0,85,86,5,20,0,0,86,87,6,3,-1,0,87,97,1,
  	0,0,0,88,89,3,20,10,0,89,90,5,31,0,0,90,91,5,14,0,0,91,92,5,15,0,0,92,
  	93,6,3,-1,0,93,94,5,20,0,0,94,95,6,3,-1,0,95,97,1,0,0,0,96,79,1,0,0,0,
  	96,88,1,0,0,0,97,7,1,0,0,0,98,99,3,20,10,0,99,100,5,31,0,0,100,101,6,
  	4,-1,0,101,102,5,14,0,0,102,103,6,4,-1,0,103,104,3,10,5,0,104,105,6,4,
  	-1,0,105,106,5,15,0,0,106,107,6,4,-1,0,107,108,3,14,7,0,108,109,6,4,-1,
  	0,109,132,1,0,0,0,110,111,3,20,10,0,111,112,5,31,0,0,112,113,6,4,-1,0,
  	113,114,5,14,0,0,114,115,6,4,-1,0,115,116,3,12,6,0,116,117,6,4,-1,0,117,
  	118,5,15,0,0,118,119,6,4,-1,0,119,120,3,14,7,0,120,121,6,4,-1,0,121,132,
  	1,0,0,0,122,123,3,20,10,0,123,124,5,31,0,0,124,125,6,4,-1,0,125,126,5,
  	14,0,0,126,127,6,4,-1,0,127,128,5,15,0,0,128,129,3,14,7,0,129,130,6,4,
  	-1,0,130,132,1,0,0,0,131,98,1,0,0,0,131,110,1,0,0,0,131,122,1,0,0,0,132,
  	9,1,0,0,0,133,134,6,5,-1,0,134,135,3,20,10,0,135,136,5,31,0,0,136,137,
  	6,5,-1,0,137,142,1,0,0,0,138,139,3,20,10,0,139,140,6,5,-1,0,140,142,1,
  	0,0,0,141,133,1,0,0,0,141,138,1,0,0,0,142,156,1,0,0,0,143,144,10,4,0,
  	0,144,145,5,21,0,0,145,146,3,20,10,0,146,147,5,31,0,0,147,148,6,5,-1,
  	0,148,155,1,0,0,0,149,150,10,3,0,0,150,151,5,21,0,0,151,152,3,20,10,0,
  	152,153,6,5,-1,0,153,155,1,0,0,0,154,143,1,0,0,0,154,149,1,0,0,0,155,
  	158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,11,1,0,0,0,158,156,1,
  	0,0,0,159,160,3,20,10,0,160,161,5,22,0,0,161,162,6,6,-1,0,162,13,1,0,
  	0,0,163,164,5,16,0,0,164,165,6,7,-1,0,165,166,3,24,12,0,166,167,5,17,
  	0,0,167,168,6,7,-1,0,168,174,1,0,0,0,169,170,5,16,0,0,170,171,6,7,-1,
  	0,171,172,5,17,0,0,172,174,6,7,-1,0,173,163,1,0,0,0,173,169,1,0,0,0,174,
  	15,1,0,0,0,175,176,3,20,10,0,176,177,3,22,11,0,177,178,5,20,0,0,178,179,
  	6,8,-1,0,179,191,1,0,0,0,180,181,3,22,11,0,181,182,5,22,0,0,182,183,5,
  	31,0,0,183,184,6,8,-1,0,184,191,1,0,0,0,185,186,3,20,10,0,186,187,3,18,
  	9,0,187,188,5,20,0,0,188,189,6,8,-1,0,189,191,1,0,0,0,190,175,1,0,0,0,
  	190,180,1,0,0,0,190,185,1,0,0,0,191,17,1,0,0,0,192,193,6,9,-1,0,193,19,
  	1,0,0,0,194,195,5,11,0,0,195,201,6,10,-1,0,196,197,5,12,0,0,197,201,6,
  	10,-1,0,198,199,5,13,0,0,199,201,6,10,-1,0,200,194,1,0,0,0,200,196,1,
  	0,0,0,200,198,1,0,0,0,201,21,1,0,0,0,202,203,6,11,-1,0,203,204,5,31,0,
  	0,204,211,6,11,-1,0,205,206,5,31,0,0,206,207,5,18,0,0,207,208,5,32,0,
  	0,208,209,5,19,0,0,209,211,6,11,-1,0,210,202,1,0,0,0,210,205,1,0,0,0,
  	211,229,1,0,0,0,212,213,10,5,0,0,213,214,5,21,0,0,214,215,5,31,0,0,215,
  	228,6,11,-1,0,216,217,10,4,0,0,217,218,5,22,0,0,218,219,5,31,0,0,219,
  	228,6,11,-1,0,220,221,10,3,0,0,221,222,5,21,0,0,222,223,5,31,0,0,223,
  	224,5,18,0,0,224,225,5,32,0,0,225,226,5,19,0,0,226,228,6,11,-1,0,227,
  	212,1,0,0,0,227,216,1,0,0,0,227,220,1,0,0,0,228,231,1,0,0,0,229,227,1,
  	0,0,0,229,230,1,0,0,0,230,23,1,0,0,0,231,229,1,0,0,0,232,233,6,12,-1,
  	0,233,234,3,26,13,0,234,235,6,12,-1,0,235,242,1,0,0,0,236,237,10,1,0,
  	0,237,238,3,26,13,0,238,239,6,12,-1,0,239,241,1,0,0,0,240,236,1,0,0,0,
  	241,244,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,25,1,0,0,0,244,242,
  	1,0,0,0,245,246,3,16,8,0,246,247,6,13,-1,0,247,298,1,0,0,0,248,249,3,
  	28,14,0,249,250,6,13,-1,0,250,298,1,0,0,0,251,252,3,14,7,0,252,253,6,
  	13,-1,0,253,298,1,0,0,0,254,255,5,7,0,0,255,256,5,14,0,0,256,257,3,28,
  	14,0,257,258,3,28,14,0,258,259,3,32,16,0,259,260,5,15,0,0,260,261,3,26,
  	13,0,261,262,6,13,-1,0,262,298,1,0,0,0,263,264,5,5,0,0,264,265,5,14,0,
  	0,265,266,3,32,16,0,266,267,5,15,0,0,267,268,3,26,13,0,268,269,6,13,-1,
  	0,269,298,1,0,0,0,270,271,5,5,0,0,271,272,5,14,0,0,272,273,3,32,16,0,
  	273,274,5,15,0,0,274,275,3,26,13,0,275,276,5,6,0,0,276,277,3,26,13,0,
  	277,278,6,13,-1,0,278,298,1,0,0,0,279,280,5,8,0,0,280,281,5,14,0,0,281,
  	282,3,32,16,0,282,283,5,15,0,0,283,284,3,26,13,0,284,285,6,13,-1,0,285,
  	298,1,0,0,0,286,287,5,9,0,0,287,288,5,14,0,0,288,289,5,31,0,0,289,290,
  	5,15,0,0,290,291,5,20,0,0,291,298,6,13,-1,0,292,293,5,10,0,0,293,294,
  	3,32,16,0,294,295,5,20,0,0,295,296,6,13,-1,0,296,298,1,0,0,0,297,245,
  	1,0,0,0,297,248,1,0,0,0,297,251,1,0,0,0,297,254,1,0,0,0,297,263,1,0,0,
  	0,297,270,1,0,0,0,297,279,1,0,0,0,297,286,1,0,0,0,297,292,1,0,0,0,298,
  	27,1,0,0,0,299,300,5,20,0,0,300,306,6,14,-1,0,301,302,3,32,16,0,302,303,
  	5,20,0,0,303,304,6,14,-1,0,304,306,1,0,0,0,305,299,1,0,0,0,305,301,1,
  	0,0,0,306,29,1,0,0,0,307,308,5,31,0,0,308,316,6,15,-1,0,309,310,5,31,
  	0,0,310,311,5,18,0,0,311,312,3,32,16,0,312,313,5,19,0,0,313,314,6,15,
  	-1,0,314,316,1,0,0,0,315,307,1,0,0,0,315,309,1,0,0,0,316,31,1,0,0,0,317,
  	318,3,36,18,0,318,319,6,16,-1,0,319,331,1,0,0,0,320,321,3,30,15,0,321,
  	322,5,30,0,0,322,323,3,36,18,0,323,324,6,16,-1,0,324,331,1,0,0,0,325,
  	326,3,30,15,0,326,327,5,30,0,0,327,328,3,34,17,0,328,329,6,16,-1,0,329,
  	331,1,0,0,0,330,317,1,0,0,0,330,320,1,0,0,0,330,325,1,0,0,0,331,33,1,
  	0,0,0,332,333,3,40,20,0,333,334,5,22,0,0,334,335,5,30,0,0,335,336,6,17,
  	-1,0,336,337,3,32,16,0,337,35,1,0,0,0,338,339,3,38,19,0,339,340,6,18,
  	-1,0,340,347,1,0,0,0,341,342,3,38,19,0,342,343,5,29,0,0,343,344,3,38,
  	19,0,344,345,6,18,-1,0,345,347,1,0,0,0,346,338,1,0,0,0,346,341,1,0,0,
  	0,347,37,1,0,0,0,348,349,3,40,20,0,349,350,6,19,-1,0,350,357,1,0,0,0,
  	351,352,3,40,20,0,352,353,5,28,0,0,353,354,3,40,20,0,354,355,6,19,-1,
  	0,355,357,1,0,0,0,356,348,1,0,0,0,356,351,1,0,0,0,357,39,1,0,0,0,358,
  	359,6,20,-1,0,359,360,3,42,21,0,360,361,5,34,0,0,361,362,6,20,-1,0,362,
  	367,1,0,0,0,363,364,3,42,21,0,364,365,6,20,-1,0,365,367,1,0,0,0,366,358,
  	1,0,0,0,366,363,1,0,0,0,367,375,1,0,0,0,368,369,10,1,0,0,369,370,5,22,
  	0,0,370,371,3,42,21,0,371,372,6,20,-1,0,372,374,1,0,0,0,373,368,1,0,0,
  	0,374,377,1,0,0,0,375,373,1,0,0,0,375,376,1,0,0,0,376,41,1,0,0,0,377,
  	375,1,0,0,0,378,379,6,21,-1,0,379,380,3,44,22,0,380,381,6,21,-1,0,381,
  	389,1,0,0,0,382,383,10,1,0,0,383,384,5,24,0,0,384,385,3,44,22,0,385,386,
  	6,21,-1,0,386,388,1,0,0,0,387,382,1,0,0,0,388,391,1,0,0,0,389,387,1,0,
  	0,0,389,390,1,0,0,0,390,43,1,0,0,0,391,389,1,0,0,0,392,393,5,22,0,0,393,
  	394,3,44,22,0,394,395,6,22,-1,0,395,404,1,0,0,0,396,397,5,27,0,0,397,
  	398,3,44,22,0,398,399,6,22,-1,0,399,404,1,0,0,0,400,401,3,46,23,0,401,
  	402,6,22,-1,0,402,404,1,0,0,0,403,392,1,0,0,0,403,396,1,0,0,0,403,400,
  	1,0,0,0,404,45,1,0,0,0,405,406,3,30,15,0,406,407,6,23,-1,0,407,432,1,
  	0,0,0,408,409,5,31,0,0,409,410,5,14,0,0,410,411,3,48,24,0,411,412,5,15,
  	0,0,412,413,6,23,-1,0,413,432,1,0,0,0,414,415,5,14,0,0,415,416,3,32,16,
  	0,416,417,5,15,0,0,417,418,6,23,-1,0,418,432,1,0,0,0,419,420,5,32,0,0,
  	420,432,6,23,-1,0,421,422,5,33,0,0,422,432,6,23,-1,0,423,424,3,30,15,
  	0,424,425,5,25,0,0,425,426,6,23,-1,0,426,432,1,0,0,0,427,428,3,30,15,
  	0,428,429,5,26,0,0,429,430,6,23,-1,0,430,432,1,0,0,0,431,405,1,0,0,0,
  	431,408,1,0,0,0,431,414,1,0,0,0,431,419,1,0,0,0,431,421,1,0,0,0,431,423,
  	1,0,0,0,431,427,1,0,0,0,432,47,1,0,0,0,433,434,3,50,25,0,434,435,6,24,
  	-1,0,435,49,1,0,0,0,436,437,6,25,-1,0,437,438,3,36,18,0,438,439,6,25,
  	-1,0,439,447,1,0,0,0,440,441,10,2,0,0,441,442,5,21,0,0,442,443,3,36,18,
  	0,443,444,6,25,-1,0,444,446,1,0,0,0,445,440,1,0,0,0,446,449,1,0,0,0,447,
  	445,1,0,0,0,447,448,1,0,0,0,448,51,1,0,0,0,449,447,1,0,0,0,26,65,77,96,
  	131,141,154,156,173,190,200,210,227,229,242,297,305,315,330,346,356,366,
  	375,389,403,431,447
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
    setState(52);
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
    setState(56);
    antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext = unit();

    		std:: string message = "Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number) + ": program : unit";
    		message += "\n\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
    		antlrcpp::downCast<ProgramContext *>(_localctx)->unit_name =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
    		antlrcpp::downCast<ProgramContext *>(_localctx)->line_number =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number;
    		writeIntoparserLogFile(message, 2);
    	
    _ctx->stop = _input->LT(-1);
    setState(65);
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
        setState(59);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(60);
        antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext = unit();

                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number) + ": program : program unit";
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->unit_name =  antlrcpp::downCast<ProgramContext *>(_localctx)->pg->unit_name + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->unit_name;
                  		antlrcpp::downCast<ProgramContext *>(_localctx)->line_number =  antlrcpp::downCast<ProgramContext *>(_localctx)->unitContext->line_number;
                  		message += "\n\n" + _localctx->unit_name ;
                  		writeIntoparserLogFile(message, 2);
                  	 
      }
      setState(67);
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
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(68);
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
      setState(71);
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
      setState(74);
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
    setState(96);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(81);
      match(C2105118Parser::LPAREN);
      setState(82);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext = parameter_list(0);
      setState(83);
      match(C2105118Parser::RPAREN);

      				// cout<<" in RPAREN of func_declaration, parameter size is: " << currentParams.size() << endl;

      			
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      			std::string var_type = antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->type;

      			// cout<<"param size of " << antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() << " when inserting into symbol table: " << currentParams.size() << endl;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine(),currentParams,false, 1);
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
      			message += "\n\n" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext->name_line + ");";
      			writeIntoparserLogFile(message, 2);
      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->parameter_listContext->name_line + ");";
      			antlrcpp::downCast<Func_declarationContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine();
      			currentParams.clear(); // Clear current parameters after function declaration

      		
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(89);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(90);
      match(C2105118Parser::LPAREN);
      setState(91);
      match(C2105118Parser::RPAREN);

      				// cout<<" in RPAREN of func_declaration, parameter size is: " << currentParams.size() << endl;

      			
      setState(93);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

      			std::string var_type = antlrcpp::downCast<Func_declarationContext *>(_localctx)->type_specifierContext->type;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine(),currentParams,false, 1);
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

C2105118Parser::Parameter_list_errContext* C2105118Parser::Func_definitionContext::parameter_list_err() {
  return getRuleContext<C2105118Parser::Parameter_list_errContext>(0);
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
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(99);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      			
      			std::string var_type = antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->type;
      			// cout<< "var_type is: " << var_type << endl;
      			retType = var_type;
      			// cout<< "retType is: " << retType << endl;
      			bool success = insertIntoSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine(),currentParams,false, 1);
      		
      setState(101);
      match(C2105118Parser::LPAREN);

      				func_def=1;
      				enterScope();
      			
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->parameter_listContext = parameter_list(0);

      				int err=0;

      				symbolInfo* sinfo = getVarType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
      				int isFunction = sinfo ? sinfo->getIsFunction() : 1;
      				if (isFunction == 0){
      					err++;
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      				}

      				if (sinfo != nullptr && sinfo->getType() != var_type) {
      					err++;
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      			}
      				
      				
      setState(105);
      match(C2105118Parser::RPAREN);
       
      				if (!success && err == 0) {
      					int paramsSize = currentParams.size();
      					int storedParamsSize = sinfo ? sinfo->getParams().size() : 0;
      					if (paramsSize != storedParamsSize) {
      						std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      						writeIntoErrorFile(errMsg);
      						writeIntoparserLogFile(errMsg, 2);
      						syntaxErrorCount++;
      					}
      					else {
      						for (int i = 0; i < paramsSize; i++) {
      							if (currentParams[i] != sinfo->getParams()[i]) {
      								std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      								writeIntoErrorFile(errMsg);
      								writeIntoparserLogFile(errMsg, 2);
      								syntaxErrorCount++;
      								cout << "Error at line " << antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine() << ": " << i+1 << "th argument mismatch in function " << antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() << endl;
      								break;
      							}
      						}
      						cout<<"ok" << endl;
      					}
      				}
      				symbolTable.setParams(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), currentParams);
      				// cout<<"param size of " << antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() << " when inserting into symbol table: " << currentParams.size() << endl;
      				currentParams.clear(); // Clear current parameters after function definition 
      				
      setState(107);
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
      setState(110);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(111);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      			
      			std::string var_type = antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->type;
      			// cout<< "var_type is: " << var_type << endl;
      			retType = var_type;
      			// cout<< "retType is: " << retType << endl;
      			bool success = insertIntoSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine(),currentParams,false, 1);
      		
      setState(113);
      match(C2105118Parser::LPAREN);

      				func_def=1;
      				enterScope();
      			
      setState(115);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->parameter_list_errContext = parameter_list_err();

      				int err=0;

      				symbolInfo* sinfo = getVarType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
      				int isFunction = sinfo ? sinfo->getIsFunction() : 1;
      				if (isFunction == 0){
      					err++;
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      				}

      				if (sinfo != nullptr && sinfo->getType() != var_type) {
      					err++;
      					std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
      					writeIntoErrorFile(errMsg);
      					writeIntoparserLogFile(errMsg, 2);
      					syntaxErrorCount++;
      			}
      				
      				
      setState(117);
      match(C2105118Parser::RPAREN);
       
      				currentParams.clear(); // Clear current parameters after function definition 
      				
      setState(119);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->unit_name =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->parameter_list_errContext->name_line + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->unit_name ;
      			antlrcpp::downCast<Func_definitionContext *>(_localctx)->line_number =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->line_number) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement";
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      			retType = "";
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(122);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(123);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      		std::string var_type = antlrcpp::downCast<Func_definitionContext *>(_localctx)->type_specifierContext->type;
      		// cout<< "var_type is: " << var_type << endl;
      		retType = var_type;
      		// cout<< "retType is: " << retType << endl;
      			insertIntoSymbolTable(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine(),currentParams,false, 1);
      		
      setState(125);
      match(C2105118Parser::LPAREN);

      				func_def=1;
      				enterScope();	
      		
      setState(127);
      match(C2105118Parser::RPAREN);
      setState(128);
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
    setState(141);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(134);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();
      setState(135);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);


      	currentParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type);

      	// cout<< "type+spec id "<<endl;
      	// cout<< "size is : " << currentParams.size() <<"for " << antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() << endl;

      	std::string var_type = antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type;
      	if (func_def==1) {
      		insertIntoSymbolTable(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine(),currentParams, false, 0,1);
      	}
      	antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
      	std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": parameter_list : type_specifier ID";
      	message += "\n\n" + _localctx->name_line;
      	symbolInfo* sinfo = getVarType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText());
      	// if (sinfo) {
      	// 	cout << "Variable " << antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() << " is of type " << sinfo->getType() << endl;
      	// }
      	vector<std::string> storedParams = sinfo ? sinfo->getParams() : vector<std::string>();
      	// cout << "Stored parameter no. for " << antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() << ": " << storedParams.size() << endl;
      	writeIntoparserLogFile(message, 2);  
      	
      break;
    }

    case 2: {
      setState(138);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();

      		cout<< "type"<<endl;
      		antlrcpp::downCast<Parameter_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->name_line ;
      		std::string message = "Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->line_number) + ": parameter_list : type_specifier";
       		message += "\n\n" + _localctx->name_line;
      		writeIntoparserLogFile(message, 2);
      	
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(154);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(143);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(144);
          match(C2105118Parser::COMMA);
          setState(145);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext = type_specifier();
          setState(146);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

                    	// cout<< "func_def is: "<< func_def <<endl;
                    	std::string var_type = antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type;
                    	currentParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->type_specifierContext->type);
                    	// cout<< "size is : hh " << currentParams.size() <<"for " << antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() << endl;
                    	if (func_def==1) {
                    		insertIntoSymbolTable(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), var_type, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine(), currentParams, false, 0,1);
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
          setState(149);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(150);
          match(C2105118Parser::COMMA);
          setState(151);
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
      setState(158);
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

//----------------- Parameter_list_errContext ------------------------------------------------------------------

C2105118Parser::Parameter_list_errContext::Parameter_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Type_specifierContext* C2105118Parser::Parameter_list_errContext::type_specifier() {
  return getRuleContext<C2105118Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105118Parser::Parameter_list_errContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
}


size_t C2105118Parser::Parameter_list_errContext::getRuleIndex() const {
  return C2105118Parser::RuleParameter_list_err;
}

void C2105118Parser::Parameter_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list_err(this);
}

void C2105118Parser::Parameter_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list_err(this);
}

C2105118Parser::Parameter_list_errContext* C2105118Parser::parameter_list_err() {
  Parameter_list_errContext *_localctx = _tracker.createInstance<Parameter_list_errContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105118Parser::RuleParameter_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->type_specifierContext = type_specifier();
    setState(160);
    antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);

    		cout<< "type"<<endl;
    		antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->name_line =  antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->type_specifierContext->name_line ;
    		std::string err= "Error at line " + std::to_string(antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA";
    		std::string message = "Line " + std::to_string(antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->addopToken->getLine()) + ": parameter_list : type_specifier";
    		message += "\n\n" + _localctx->name_line;
    		message += "\n\nError at line "+ std::to_string(antlrcpp::downCast<Parameter_list_errContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA";
    		syntaxErrorCount++;
    		writeIntoparserLogFile(message, 2);
    		writeIntoErrorFile(err);
    	
   
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
  enterRule(_localctx, 14, C2105118Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      match(C2105118Parser::LCURL);

      				if (func_def==1) func_def=0;
      				else enterScope();
      			
      setState(165);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->statementsContext = statements(0);
      setState(166);
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
      setState(169);
      match(C2105118Parser::LCURL);

      				if (func_def==1) func_def=0;
      				else enterScope();
      			
      setState(171);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C2105118Parser::RCURL);
       
      				func_def=0;
      				std::string message = "Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL RCURL";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->unit_name =  "{}";
      				antlrcpp::downCast<Compound_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine();
      				message += "\n\n{}" ;
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

tree::TerminalNode* C2105118Parser::Var_declarationContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
}

tree::TerminalNode* C2105118Parser::Var_declarationContext::ID() {
  return getToken(C2105118Parser::ID, 0);
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
  enterRule(_localctx, 16, C2105118Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(176);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(177);
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
      setState(180);
      declaration_list(0);
      setState(181);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
      setState(182);
      match(C2105118Parser::ID);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->var_name =  "";
      		std::string message = "Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->addopToken->getLine()) + ": "+ _localctx->var_name;
      		writeIntoErrorFile(message)	;
      		antlrcpp::downCast<Var_declarationContext *>(_localctx)->line_number =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->addopToken->getLine();
      		writeIntoparserLogFile(message, 2);
      		cout << "Error in declaration list" << endl;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(185);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(186);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(187);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105118Parser::SEMICOLON);

              writeIntoErrorFile(
                  std::string("Line# ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );
      		cout << "Error at line " << antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine() << ": " << antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name << endl;

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
  enterRule(_localctx, 18, C2105118Parser::RuleDeclaration_list_err);

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
  enterRule(_localctx, 20, C2105118Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(194);
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
        setState(196);
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
        setState(198);
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

tree::TerminalNode* C2105118Parser::Declaration_listContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105118Parser::RuleDeclaration_list, precedence);

    

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
    setState(210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(203);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() ;
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID"+ "\n\n" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
      			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(),currentParams, false,0);
      			writeIntoparserLogFile(message,2);
      		  
      break;
    }

    case 2: {
      setState(205);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(206);
      match(C2105118Parser::LTHIRD);
      setState(207);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);
      setState(208);
      match(C2105118Parser::RTHIRD);

      			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]";
      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx->name_line;
      			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(),currentParams, true,0);
      			writeIntoparserLogFile(message,2);
      		  
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(227);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(212);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(213);
          match(C2105118Parser::COMMA);
          setState(214);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->name_line +"," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText();
                    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID"+ "\n\n" + _localctx->name_line;
                    			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(),currentParams, false,0);
                    			writeIntoparserLogFile(message,2);
                    			
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(216);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(217);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
          setState(218);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->name_line ;
                    				std::string message = "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON";
                    				writeIntoErrorFile(message);
                    				writeIntoparserLogFile(message, 2);
                    				syntaxErrorCount++;
                    				syntaxErrorCount++;
                    				cout<<"hello"<<endl;
                    			
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(220);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(221);
          match(C2105118Parser::COMMA);
          setState(222);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C2105118Parser::ID);
          setState(223);
          match(C2105118Parser::LTHIRD);
          setState(224);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);
          setState(225);
          match(C2105118Parser::RTHIRD);

                    			antlrcpp::downCast<Declaration_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->name_line + "," + antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]";
                    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"+ "\n\n" + _localctx->name_line;
                    			insertIntoSymbolTable(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText(), currentType, antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine(),currentParams, true);
                    			writeIntoparserLogFile(message,2);
                    		  
          break;
        }

        default:
          break;
        } 
      }
      setState(231);
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
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, C2105118Parser::RuleStatements, precedence);

    

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
    setState(233);
    antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext = statement();

    			antlrcpp::downCast<StatementsContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->unit_name;
    			antlrcpp::downCast<StatementsContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number;
    			antlrcpp::downCast<StatementsContext *>(_localctx)->retError =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->retError;
    			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number) + ": statements : statement";
    			message += "\n\n" + _localctx->unit_name;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(242);
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
        setState(236);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(237);
        antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext = statement();

                  		antlrcpp::downCast<StatementsContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementsContext *>(_localctx)->sts->unit_name ;
                  		antlrcpp::downCast<StatementsContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number;
                  		if (!antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->unit_name.empty()) {
                  			_localctx->unit_name +=("\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->unit_name);
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->statementContext->line_number) + ": statements : statements statement";
                  			message += "\n\n" + _localctx->unit_name;
                  			writeIntoparserLogFile(message, 2);
                  		}
                  		 
      }
      setState(244);
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
  enterRule(_localctx, 26, C2105118Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(245);
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
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext = expression_statement();
       
      			antlrcpp::downCast<StatementContext *>(_localctx)->line_number =  antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->line_number;
      			antlrcpp::downCast<StatementContext *>(_localctx)->unit_name =  antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->unit_name;
      		    if (!antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->unit_name.empty()) {

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->expression_statementContext->line_number) + ": statement : expression_statement";
      			message += "\n\n" + _localctx->unit_name;
      			writeIntoparserLogFile(message, 2);
      			}
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(251);
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
      setState(254);
      match(C2105118Parser::FOR);
      setState(255);
      match(C2105118Parser::LPAREN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->esa = expression_statement();
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->esb = expression_statement();
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(259);
      match(C2105118Parser::RPAREN);
      setState(260);
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
      setState(263);
      match(C2105118Parser::IF);
      setState(264);
      match(C2105118Parser::LPAREN);
      setState(265);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(266);
      match(C2105118Parser::RPAREN);
      setState(267);
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
      setState(270);
      match(C2105118Parser::IF);
      setState(271);
      match(C2105118Parser::LPAREN);
      setState(272);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(273);
      match(C2105118Parser::RPAREN);
      setState(274);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(275);
      match(C2105118Parser::ELSE);
      setState(276);
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
      setState(279);
      match(C2105118Parser::WHILE);
      setState(280);
      match(C2105118Parser::LPAREN);
      setState(281);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(282);
      match(C2105118Parser::RPAREN);
      setState(283);
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
      setState(286);
      match(C2105118Parser::PRINTLN);
      setState(287);
      match(C2105118Parser::LPAREN);
      setState(288);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(289);
      match(C2105118Parser::RPAREN);
      setState(290);
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
      setState(292);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105118Parser::RETURN);
      setState(293);
      antlrcpp::downCast<StatementContext *>(_localctx)->expressionContext = expression();
      setState(294);
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
  enterRule(_localctx, 28, C2105118Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(299);
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
        setState(301);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext = expression();
        setState(302);
        match(C2105118Parser::SEMICOLON);

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->line_number) + ": expression_statement : expression SEMICOLON";
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->unit_name =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->var_name ;
        			if (!_localctx->unit_name.empty()) {
        				antlrcpp::downCast<Expression_statementContext *>(_localctx)->unit_name =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->var_name+ ";";
        				message += "\n\n" + _localctx->unit_name ;
        				writeIntoparserLogFile(message, 2);
        			}
        			antlrcpp::downCast<Expression_statementContext *>(_localctx)->line_number =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->expressionContext->line_number;
        		
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
  enterRule(_localctx, 30, C2105118Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(307);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105118Parser::ID);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID";
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      			antlrcpp::downCast<VariableContext *>(_localctx)->type =  "";
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
      				stopargMismatch++;
      				stopargMismatchName = antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      				syntaxErrorCount++;

      				antlrcpp::downCast<VariableContext *>(_localctx)->type =  sinfo->getType() + "[]"; // indicate that it's an array
      			} else {
      				antlrcpp::downCast<VariableContext *>(_localctx)->type =  sinfo->getType();
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
      setState(309);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(310);
      match(C2105118Parser::LTHIRD);
      setState(311);
      antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext = expression();
      setState(312);
      match(C2105118Parser::RTHIRD);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID LTHIRD expression RTHIRD";
      			antlrcpp::downCast<VariableContext *>(_localctx)->var_name =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->expressionContext->var_name + "]";
      			antlrcpp::downCast<VariableContext *>(_localctx)->trueName =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();
      			symbolInfo* sinfo = getVarType(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
      			std::string type = sinfo ? sinfo->getType() : "";
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

C2105118Parser::Logic_expression_errContext* C2105118Parser::ExpressionContext::logic_expression_err() {
  return getRuleContext<C2105118Parser::Logic_expression_errContext>(0);
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
  enterRule(_localctx, 32, C2105118Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(317);
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
      setState(320);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->variableContext = variable();
      setState(321);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105118Parser::ASSIGNOP);
      setState(322);
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

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(325);
      variable();
      setState(326);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C2105118Parser::ASSIGNOP);
      setState(327);
      logic_expression_err();

      			antlrcpp::downCast<ExpressionContext *>(_localctx)->var_name =  "";
      			antlrcpp::downCast<ExpressionContext *>(_localctx)->line_number =  antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getLine();
      			
      		
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

//----------------- Logic_expression_errContext ------------------------------------------------------------------

C2105118Parser::Logic_expression_errContext::Logic_expression_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105118Parser::Simple_expressionContext* C2105118Parser::Logic_expression_errContext::simple_expression() {
  return getRuleContext<C2105118Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105118Parser::Logic_expression_errContext::ADDOP() {
  return getToken(C2105118Parser::ADDOP, 0);
}

tree::TerminalNode* C2105118Parser::Logic_expression_errContext::ASSIGNOP() {
  return getToken(C2105118Parser::ASSIGNOP, 0);
}

C2105118Parser::ExpressionContext* C2105118Parser::Logic_expression_errContext::expression() {
  return getRuleContext<C2105118Parser::ExpressionContext>(0);
}


size_t C2105118Parser::Logic_expression_errContext::getRuleIndex() const {
  return C2105118Parser::RuleLogic_expression_err;
}

void C2105118Parser::Logic_expression_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression_err(this);
}

void C2105118Parser::Logic_expression_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105118ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression_err(this);
}

C2105118Parser::Logic_expression_errContext* C2105118Parser::logic_expression_err() {
  Logic_expression_errContext *_localctx = _tracker.createInstance<Logic_expression_errContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105118Parser::RuleLogic_expression_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    simple_expression(0);
    setState(333);
    antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
    setState(334);
    match(C2105118Parser::ASSIGNOP);

    			cout<<"Hes the boss"<<endl;
    			antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->var_name =  "";
    			std::string message = "Error at line " + std::to_string(antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ASSIGNOP";
    			writeIntoErrorFile(message);
    			antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->line_number =  antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->addopToken->getLine();
    			writeIntoparserLogFile(message, 2);
    			syntaxErrorCount++;
    			antlrcpp::downCast<Logic_expression_errContext *>(_localctx)->type =  "INT"; // Default type for logic expressions

    		
    setState(336);
    expression();
   
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
  enterRule(_localctx, 36, C2105118Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(338);
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
      setState(341);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rl = antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();
      setState(342);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C2105118Parser::LOGICOP);
      setState(343);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->rel_expressionContext = rel_expression();

      			antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  "INT"; // Logic expressions are always of type INT
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
  enterRule(_localctx, 38, C2105118Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(356);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(348);
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
      setState(351);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1 = simple_expression(0);
      setState(352);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C2105118Parser::RELOP);
      setState(353);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl2 = simple_expression(0);

      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1->var_name + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl2->var_name;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->sl1->line_number;
      			antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  "INT"; // Relational expressions are always of type INT
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

tree::TerminalNode* C2105118Parser::Simple_expressionContext::HASH() {
  return getToken(C2105118Parser::HASH, 0);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C2105118Parser::RuleSimple_expression, precedence);

    

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
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(359);
      antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);
      setState(360);
      antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken = match(C2105118Parser::HASH);

      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
      			cout<<"sauce"<<endl;
      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getLine()+1;
      			std::string message = "Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getLine()) + ": " + "Unrecognized character "+ antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getText();
      			message +=( "\n\nLine " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getLine()+1) + ": simple_expression : term\n\n"+ antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name);
      			std:: string err = "Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->hashToken->getText();
      			writeIntoErrorFile(err);
      			writeIntoparserLogFile(message, 2);
      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "INT"; // Default type for terms
      		
      break;
    }

    case 2: {
      setState(363);
      antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number) + ": simple_expression : term";
      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number;
      			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->type;

      			message += "\n\n" + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(375);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(368);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(369);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
        setState(370);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext = term(0);
         
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number) + ": simple_expression : simple_expression ADDOP term";
                  			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->var_name + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->var_name;
                  			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->line_number;
                  			antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "INT"; // Simple expressions are always of type INT
                  			if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->type == "FLOAT" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->type == "FLOAT" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->type == "CONST_FLOAT" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->termContext->type == "CONST_FLOAT") {
                  				antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "FLOAT";
                  			}
                  			message += "\n\n" + _localctx->var_name;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(377);
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
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, C2105118Parser::RuleTerm, precedence);

    

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
    setState(379);
    antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

    			std::string message = "Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number) + ": term : unary_expression";
    			antlrcpp::downCast<TermContext *>(_localctx)->var_name =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name;
    			antlrcpp::downCast<TermContext *>(_localctx)->line_number =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->line_number;
    			antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->type;
    			message += "\n\n" + antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->var_name;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(389);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->tm = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(382);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(383);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C2105118Parser::MULOP);
        setState(384);
        antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext = unary_expression();

                  			antlrcpp::downCast<TermContext *>(_localctx)->type =  "INT"; // Term and unary expressions are always of type INT
                  			if (antlrcpp::downCast<TermContext *>(_localctx)->tm->type == "FLOAT" || antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->type == "FLOAT" || antlrcpp::downCast<TermContext *>(_localctx)->tm->type == "CONST_FLOAT" || antlrcpp::downCast<TermContext *>(_localctx)->unary_expressionContext->type == "CONST_FLOAT") {
                  				antlrcpp::downCast<TermContext *>(_localctx)->type =  "FLOAT";
                  			}
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
      setState(391);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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
  enterRule(_localctx, 44, C2105118Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105118Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(392);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C2105118Parser::ADDOP);
        setState(393);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

        			std::string message = "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->line_number) + ": unary_expression : ADDOP unary_expression";
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->var_name =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->var_name;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->line_number =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->line_number;
        			antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
        			message += "\n\n" + _localctx->var_name;
        			writeIntoparserLogFile(message, 2);
        		
        break;
      }

      case C2105118Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(396);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C2105118Parser::NOT);
        setState(397);
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
        setState(400);
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
  enterRule(_localctx, 46, C2105118Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(431);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(405);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable";
      			message += "\n\n" + antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name;
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name;
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->type;	
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			writeIntoparserLogFile(message, 2);
      	
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(408);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C2105118Parser::ID);
      setState(409);
      match(C2105118Parser::LPAREN);
      setState(410);
      antlrcpp::downCast<FactorContext *>(_localctx)->argument_listContext = argument_list();
      setState(411);
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
      			else {
      				if (sinfo->getIsFunction()) {
      					std::vector<std::string> paramTypes = sinfo->getParams();
      					// cout<<" size of paramTypes is: " << sinfo->getParamCount() << endl;
      					if (paramTypes.size() != currentArgs.size()) {
      						std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText();
      						writeIntoErrorFile(errMsg);
      						message += "\n\n" + errMsg;
      						syntaxErrorCount++;
      					}
      					else {
      						for (size_t i = 0; i < paramTypes.size(); ++i) {
      							if (paramTypes[i] != currentArgs[i] && (currentArgs[i].back() != ']' && stopargMismatch == 0)) {

      								std::string errMsg = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i + 1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText();
      								writeIntoErrorFile(errMsg);
      								message += "\n\n" + errMsg;
      								cout << "paramTypes[" << i << "] = " << paramTypes[i] << ", currentArgs[" << i << "] = " << currentArgs[i] << endl;
      								syntaxErrorCount++;
      								break;
      							}

      						}
      						antlrcpp::downCast<FactorContext *>(_localctx)->type =  sinfo->getType();
      					}
      				}
      			}

      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->argument_listContext->name_line + ")";
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine();
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      			currentArgs.clear();
      		
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(414);
      match(C2105118Parser::LPAREN);
      setState(415);
      antlrcpp::downCast<FactorContext *>(_localctx)->expressionContext = expression();
      setState(416);
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
      setState(419);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C2105118Parser::CONST_INT);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine()) + ": factor : CONST_INT";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine();
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  "INT";
      			currentIndex = "CONST_INT";
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(421);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C2105118Parser::CONST_FLOAT);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine()) + ": factor : CONST_FLOAT";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine();
      			message += "\n\n" + _localctx->var_name;
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  "FLOAT";
      			currentIndex = "CONST_FLOAT";
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(423);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(424);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C2105118Parser::INCOP);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable INCOP";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name + antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->type;
      			message += "\n\n" + _localctx->var_name;
      			writeIntoparserLogFile(message, 2);
      		
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(427);
      antlrcpp::downCast<FactorContext *>(_localctx)->variableContext = variable();
      setState(428);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C2105118Parser::DECOP);

      			std::string message = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number) + ": factor : variable DECOP";
      			antlrcpp::downCast<FactorContext *>(_localctx)->var_name =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->var_name + antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getText();
      			antlrcpp::downCast<FactorContext *>(_localctx)->line_number =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->line_number;
      			antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->variableContext->type;
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
  enterRule(_localctx, 48, C2105118Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext = arguments(0);

    			antlrcpp::downCast<Argument_listContext *>(_localctx)->name_line =  antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->name_line;
    			antlrcpp::downCast<Argument_listContext *>(_localctx)->line_number =  antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->line_number;
    			std::string message = "Line " + std::to_string(antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->line_number) + ": argument_list : arguments";
    			message += "\n\n" + antlrcpp::downCast<Argument_listContext *>(_localctx)->argumentsContext->name_line;
    			writeIntoparserLogFile(message, 2);
    			
   
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
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, C2105118Parser::RuleArguments, precedence);

    

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
    setState(437);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext = logic_expression();

    			antlrcpp::downCast<ArgumentsContext *>(_localctx)->name_line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name;
    			antlrcpp::downCast<ArgumentsContext *>(_localctx)->line_number =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number;
    			std::string message = "Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number) + ": arguments : logic_expression";
    			message += "\n\n" + _localctx->name_line;
    			cout<<"logic expression is: " << antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name << endl;
    			cout<<" logic exp type is: " << antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type << endl;
    			if (antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type != "VOID" || antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type != "" ) {
    				currentArgs.insert(currentArgs.begin(), antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type);
    			}
    			// cout<< "current args size is: " << currentArgs.size() << endl;
    			writeIntoparserLogFile(message, 2);
    		
    _ctx->stop = _input->LT(-1);
    setState(447);
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
        setState(440);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(441);
        match(C2105118Parser::COMMA);
        setState(442);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext = logic_expression();

                  			
                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->name_line =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->ar->name_line + "," + antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name;
                  			antlrcpp::downCast<ArgumentsContext *>(_localctx)->line_number =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number;
                  			std::string message = "Line " + std::to_string(antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->line_number) + ": arguments : arguments COMMA logic_expression";
                  			message += "\n\n" + _localctx->name_line;
                  			cout<<"logic expression is: " << antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->var_name << endl;
                  			cout<<" logic exp type is: " << antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type << endl;
                  			if (antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type != "VOID" || antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type != "" ) {
                  				currentArgs.insert(currentArgs.begin(), antlrcpp::downCast<ArgumentsContext *>(_localctx)->logic_expressionContext->type);
                  			}
                  			// cout<< "current args size is: " << currentArgs.size() << endl;
                  			writeIntoparserLogFile(message, 2);
                  		 
      }
      setState(449);
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
    case 11: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 12: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 20: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 21: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 25: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

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
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105118Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

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
