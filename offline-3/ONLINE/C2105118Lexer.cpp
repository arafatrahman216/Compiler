
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;


// Generated from C2105118Lexer.g4 by ANTLR 4.13.2


#include "C2105118Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105118LexerStaticData final {
  C2105118LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105118LexerStaticData(const C2105118LexerStaticData&) = delete;
  C2105118LexerStaticData(C2105118LexerStaticData&&) = delete;
  C2105118LexerStaticData& operator=(const C2105118LexerStaticData&) = delete;
  C2105118LexerStaticData& operator=(C2105118LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105118lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105118LexerStaticData> c2105118lexerLexerStaticData = nullptr;

void c2105118lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105118lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105118lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105118LexerStaticData>(
    std::vector<std::string>{
      "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
      "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "DO", "BREAK", 
      "CONTINUE", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", 
      "SEMICOLON", "COMMA", "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", 
      "NOT", "RELOP", "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'do'", "'break'", "'continue'", 
      "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", "", "", "", 
      "'++'", "'--'", "'!'", "", "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "DO", 
      "BREAK", "CONTINUE", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", 
      "RTHIRD", "SEMICOLON", "COMMA", "ADDOP", "SUBOP", "MULOP", "INCOP", 
      "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", 
      "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,36,341,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,1,0,1,0,1,0,1,0,5,0,78,8,0,10,0,12,0,81,9,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,5,1,92,8,1,10,1,12,1,95,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,2,1,2,1,2,1,2,5,2,108,8,2,10,2,12,2,111,9,2,1,2,1,2,1,2,1,2,1,2,1,
  	3,4,3,119,8,3,11,3,12,3,120,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,
  	19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,
  	24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,
  	28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,
  	30,1,30,1,30,1,30,1,30,3,30,271,8,30,1,31,1,31,1,31,1,31,1,31,1,31,3,
  	31,279,8,31,1,32,1,32,1,32,1,33,1,33,5,33,286,8,33,10,33,12,33,289,9,
  	33,1,33,1,33,1,34,4,34,294,8,34,11,34,12,34,295,1,34,1,34,1,35,4,35,301,
  	8,35,11,35,12,35,302,1,35,1,35,5,35,307,8,35,10,35,12,35,310,9,35,3,35,
  	312,8,35,1,35,1,35,3,35,316,8,35,1,35,4,35,319,8,35,11,35,12,35,320,3,
  	35,323,8,35,1,35,1,35,1,35,4,35,328,8,35,11,35,12,35,329,1,35,1,35,4,
  	35,334,8,35,11,35,12,35,335,1,35,1,35,3,35,340,8,35,1,93,0,36,1,1,3,2,
  	5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,
  	55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,1,0,10,2,0,10,10,
  	13,13,4,0,10,10,13,13,34,34,92,92,3,0,9,10,12,13,32,32,2,0,43,43,45,45,
  	3,0,37,37,42,42,47,47,2,0,60,60,62,62,3,0,65,90,95,95,97,122,4,0,48,57,
  	65,90,95,95,97,122,1,0,48,57,2,0,69,69,101,101,363,0,1,1,0,0,0,0,3,1,
  	0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,
  	15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,
  	0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,
  	0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,
  	47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,
  	0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,
  	0,0,69,1,0,0,0,0,71,1,0,0,0,1,73,1,0,0,0,3,86,1,0,0,0,5,103,1,0,0,0,7,
  	118,1,0,0,0,9,124,1,0,0,0,11,129,1,0,0,0,13,136,1,0,0,0,15,142,1,0,0,
  	0,17,150,1,0,0,0,19,159,1,0,0,0,21,168,1,0,0,0,23,174,1,0,0,0,25,182,
  	1,0,0,0,27,189,1,0,0,0,29,194,1,0,0,0,31,202,1,0,0,0,33,213,1,0,0,0,35,
  	216,1,0,0,0,37,219,1,0,0,0,39,222,1,0,0,0,41,225,1,0,0,0,43,228,1,0,0,
  	0,45,231,1,0,0,0,47,234,1,0,0,0,49,237,1,0,0,0,51,240,1,0,0,0,53,243,
  	1,0,0,0,55,246,1,0,0,0,57,251,1,0,0,0,59,256,1,0,0,0,61,270,1,0,0,0,63,
  	278,1,0,0,0,65,280,1,0,0,0,67,283,1,0,0,0,69,293,1,0,0,0,71,339,1,0,0,
  	0,73,74,5,47,0,0,74,75,5,47,0,0,75,79,1,0,0,0,76,78,8,0,0,0,77,76,1,0,
  	0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,82,1,0,0,0,81,79,1,0,
  	0,0,82,83,6,0,0,0,83,84,1,0,0,0,84,85,6,0,1,0,85,2,1,0,0,0,86,87,5,47,
  	0,0,87,88,5,42,0,0,88,93,1,0,0,0,89,92,9,0,0,0,90,92,7,0,0,0,91,89,1,
  	0,0,0,91,90,1,0,0,0,92,95,1,0,0,0,93,94,1,0,0,0,93,91,1,0,0,0,94,96,1,
  	0,0,0,95,93,1,0,0,0,96,97,5,42,0,0,97,98,5,47,0,0,98,99,1,0,0,0,99,100,
  	6,1,2,0,100,101,1,0,0,0,101,102,6,1,1,0,102,4,1,0,0,0,103,109,5,34,0,
  	0,104,105,5,92,0,0,105,108,9,0,0,0,106,108,8,1,0,0,107,104,1,0,0,0,107,
  	106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,109,110,1,0,0,0,110,112,1,
  	0,0,0,111,109,1,0,0,0,112,113,5,34,0,0,113,114,6,2,3,0,114,115,1,0,0,
  	0,115,116,6,2,1,0,116,6,1,0,0,0,117,119,7,2,0,0,118,117,1,0,0,0,119,120,
  	1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,122,1,0,0,0,122,123,6,3,1,
  	0,123,8,1,0,0,0,124,125,5,105,0,0,125,126,5,102,0,0,126,127,1,0,0,0,127,
  	128,6,4,4,0,128,10,1,0,0,0,129,130,5,101,0,0,130,131,5,108,0,0,131,132,
  	5,115,0,0,132,133,5,101,0,0,133,134,1,0,0,0,134,135,6,5,5,0,135,12,1,
  	0,0,0,136,137,5,102,0,0,137,138,5,111,0,0,138,139,5,114,0,0,139,140,1,
  	0,0,0,140,141,6,6,6,0,141,14,1,0,0,0,142,143,5,119,0,0,143,144,5,104,
  	0,0,144,145,5,105,0,0,145,146,5,108,0,0,146,147,5,101,0,0,147,148,1,0,
  	0,0,148,149,6,7,7,0,149,16,1,0,0,0,150,151,5,112,0,0,151,152,5,114,0,
  	0,152,153,5,105,0,0,153,154,5,110,0,0,154,155,5,116,0,0,155,156,5,102,
  	0,0,156,157,1,0,0,0,157,158,6,8,8,0,158,18,1,0,0,0,159,160,5,114,0,0,
  	160,161,5,101,0,0,161,162,5,116,0,0,162,163,5,117,0,0,163,164,5,114,0,
  	0,164,165,5,110,0,0,165,166,1,0,0,0,166,167,6,9,9,0,167,20,1,0,0,0,168,
  	169,5,105,0,0,169,170,5,110,0,0,170,171,5,116,0,0,171,172,1,0,0,0,172,
  	173,6,10,10,0,173,22,1,0,0,0,174,175,5,102,0,0,175,176,5,108,0,0,176,
  	177,5,111,0,0,177,178,5,97,0,0,178,179,5,116,0,0,179,180,1,0,0,0,180,
  	181,6,11,11,0,181,24,1,0,0,0,182,183,5,118,0,0,183,184,5,111,0,0,184,
  	185,5,105,0,0,185,186,5,100,0,0,186,187,1,0,0,0,187,188,6,12,12,0,188,
  	26,1,0,0,0,189,190,5,100,0,0,190,191,5,111,0,0,191,192,1,0,0,0,192,193,
  	6,13,13,0,193,28,1,0,0,0,194,195,5,98,0,0,195,196,5,114,0,0,196,197,5,
  	101,0,0,197,198,5,97,0,0,198,199,5,107,0,0,199,200,1,0,0,0,200,201,6,
  	14,14,0,201,30,1,0,0,0,202,203,5,99,0,0,203,204,5,111,0,0,204,205,5,110,
  	0,0,205,206,5,116,0,0,206,207,5,105,0,0,207,208,5,110,0,0,208,209,5,117,
  	0,0,209,210,5,101,0,0,210,211,1,0,0,0,211,212,6,15,15,0,212,32,1,0,0,
  	0,213,214,5,40,0,0,214,215,6,16,16,0,215,34,1,0,0,0,216,217,5,41,0,0,
  	217,218,6,17,17,0,218,36,1,0,0,0,219,220,5,123,0,0,220,221,6,18,18,0,
  	221,38,1,0,0,0,222,223,5,125,0,0,223,224,6,19,19,0,224,40,1,0,0,0,225,
  	226,5,91,0,0,226,227,6,20,20,0,227,42,1,0,0,0,228,229,5,93,0,0,229,230,
  	6,21,21,0,230,44,1,0,0,0,231,232,5,59,0,0,232,233,6,22,22,0,233,46,1,
  	0,0,0,234,235,5,44,0,0,235,236,6,23,23,0,236,48,1,0,0,0,237,238,7,3,0,
  	0,238,239,6,24,24,0,239,50,1,0,0,0,240,241,7,3,0,0,241,242,6,25,25,0,
  	242,52,1,0,0,0,243,244,7,4,0,0,244,245,6,26,26,0,245,54,1,0,0,0,246,247,
  	5,43,0,0,247,248,5,43,0,0,248,249,1,0,0,0,249,250,6,27,27,0,250,56,1,
  	0,0,0,251,252,5,45,0,0,252,253,5,45,0,0,253,254,1,0,0,0,254,255,6,28,
  	28,0,255,58,1,0,0,0,256,257,5,33,0,0,257,258,6,29,29,0,258,60,1,0,0,0,
  	259,260,5,60,0,0,260,271,5,61,0,0,261,262,5,61,0,0,262,271,5,61,0,0,263,
  	264,5,62,0,0,264,271,5,61,0,0,265,271,7,5,0,0,266,267,5,33,0,0,267,268,
  	5,61,0,0,268,269,1,0,0,0,269,271,6,30,30,0,270,259,1,0,0,0,270,261,1,
  	0,0,0,270,263,1,0,0,0,270,265,1,0,0,0,270,266,1,0,0,0,271,62,1,0,0,0,
  	272,273,5,38,0,0,273,279,5,38,0,0,274,275,5,124,0,0,275,276,5,124,0,0,
  	276,277,1,0,0,0,277,279,6,31,31,0,278,272,1,0,0,0,278,274,1,0,0,0,279,
  	64,1,0,0,0,280,281,5,61,0,0,281,282,6,32,32,0,282,66,1,0,0,0,283,287,
  	7,6,0,0,284,286,7,7,0,0,285,284,1,0,0,0,286,289,1,0,0,0,287,285,1,0,0,
  	0,287,288,1,0,0,0,288,290,1,0,0,0,289,287,1,0,0,0,290,291,6,33,33,0,291,
  	68,1,0,0,0,292,294,7,8,0,0,293,292,1,0,0,0,294,295,1,0,0,0,295,293,1,
  	0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,298,6,34,34,0,298,70,1,0,0,
  	0,299,301,7,8,0,0,300,299,1,0,0,0,301,302,1,0,0,0,302,300,1,0,0,0,302,
  	303,1,0,0,0,303,311,1,0,0,0,304,308,5,46,0,0,305,307,7,8,0,0,306,305,
  	1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,312,1,0,0,
  	0,310,308,1,0,0,0,311,304,1,0,0,0,311,312,1,0,0,0,312,322,1,0,0,0,313,
  	315,7,9,0,0,314,316,7,3,0,0,315,314,1,0,0,0,315,316,1,0,0,0,316,318,1,
  	0,0,0,317,319,7,8,0,0,318,317,1,0,0,0,319,320,1,0,0,0,320,318,1,0,0,0,
  	320,321,1,0,0,0,321,323,1,0,0,0,322,313,1,0,0,0,322,323,1,0,0,0,323,324,
  	1,0,0,0,324,340,6,35,35,0,325,327,5,46,0,0,326,328,7,8,0,0,327,326,1,
  	0,0,0,328,329,1,0,0,0,329,327,1,0,0,0,329,330,1,0,0,0,330,331,1,0,0,0,
  	331,340,6,35,36,0,332,334,7,8,0,0,333,332,1,0,0,0,334,335,1,0,0,0,335,
  	333,1,0,0,0,335,336,1,0,0,0,336,337,1,0,0,0,337,338,5,46,0,0,338,340,
  	6,35,37,0,339,300,1,0,0,0,339,325,1,0,0,0,339,333,1,0,0,0,340,72,1,0,
  	0,0,20,0,79,91,93,107,109,120,270,278,287,295,302,308,311,315,320,322,
  	329,335,339,38,1,0,0,6,0,0,1,1,1,1,2,2,1,4,3,1,5,4,1,6,5,1,7,6,1,8,7,
  	1,9,8,1,10,9,1,11,10,1,12,11,1,13,12,1,14,13,1,15,14,1,16,15,1,17,16,
  	1,18,17,1,19,18,1,20,19,1,21,20,1,22,21,1,23,22,1,24,23,1,25,24,1,26,
  	25,1,27,26,1,28,27,1,29,28,1,30,29,1,31,30,1,32,31,1,33,32,1,34,33,1,
  	35,34,1,35,35,1,35,36
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105118lexerLexerStaticData = std::move(staticData);
}

}

C2105118Lexer::C2105118Lexer(CharStream *input) : Lexer(input) {
  C2105118Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105118lexerLexerStaticData->atn, c2105118lexerLexerStaticData->decisionToDFA, c2105118lexerLexerStaticData->sharedContextCache);
}

C2105118Lexer::~C2105118Lexer() {
  delete _interpreter;
}

std::string C2105118Lexer::getGrammarFileName() const {
  return "C2105118Lexer.g4";
}

const std::vector<std::string>& C2105118Lexer::getRuleNames() const {
  return c2105118lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105118Lexer::getChannelNames() const {
  return c2105118lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105118Lexer::getModeNames() const {
  return c2105118lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105118Lexer::getVocabulary() const {
  return c2105118lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105118Lexer::getSerializedATN() const {
  return c2105118lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105118Lexer::getATN() const {
  return *c2105118lexerLexerStaticData->atn;
}


void C2105118Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: PRINTLNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: VOIDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: BREAKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: CONTINUEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: LCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: RCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: LTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: RTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: SEMICOLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: COMMAAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: ADDOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: SUBOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: MULOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: INCOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: DECOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: NOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: RELOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: LOGICOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: ASSIGNOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: IDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: CONST_INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: CONST_FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C2105118Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <SINGLE LINE COMMENT> Lexeme "
              + getText()
            );
         break;

  default:
    break;
  }
}

void C2105118Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
          // extra braces create a new scope for your variables
          {
            std::string txt = getText();
            std::string content = txt.substr(2, txt.size() - 4);
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <MULTI LINE COMMENT> Lexeme /*"
              + content + "*/"
            );
          }
         break;

  default:
    break;
  }
}

void C2105118Lexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <STRING> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}

void C2105118Lexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::VOIDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DO> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::BREAKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <BREAK> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::CONTINUEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONTINUE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::LCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::RCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::COMMAAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::ADDOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::SUBOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SUBOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::MULOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::INCOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::DECOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::NOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::RELOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::IDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105118Lexer::CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 35: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;
    case 36: 
            writeIntoLexLogFile(
              "Line# " + std::to_string(getLine())
              + ": Token <CONST_FLOAT> Lexeme " + getText()
            );
         break;

  default:
    break;
  }
}



void C2105118Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105118lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105118lexerLexerOnceFlag, c2105118lexerLexerInitialize);
#endif
}
