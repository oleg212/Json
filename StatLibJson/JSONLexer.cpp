
// Generated from JSON.g4 by ANTLR 4.13.0


#include "JSONLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct JSONLexerStaticData final {
  JSONLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JSONLexerStaticData(const JSONLexerStaticData&) = delete;
  JSONLexerStaticData(JSONLexerStaticData&&) = delete;
  JSONLexerStaticData& operator=(const JSONLexerStaticData&) = delete;
  JSONLexerStaticData& operator=(JSONLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag jsonlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
JSONLexerStaticData *jsonlexerLexerStaticData = nullptr;

void jsonlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (jsonlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(jsonlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<JSONLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "STRING", 
      "ESC", "UNICODE", "HEX", "NUMBER", "INT", "EXP", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'{'", "','", "'}'", "':'", "'true'", "'false'", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,10,136,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,5,7,59,8,7,10,7,12,7,62,9,
  	7,1,7,1,7,1,8,1,8,1,8,3,8,69,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,
  	11,3,11,80,8,11,1,11,1,11,1,11,4,11,85,8,11,11,11,12,11,86,1,11,3,11,
  	90,8,11,1,11,3,11,93,8,11,1,11,1,11,1,11,1,11,3,11,99,8,11,1,11,1,11,
  	1,11,4,11,104,8,11,11,11,12,11,105,1,11,3,11,109,8,11,1,11,3,11,112,8,
  	11,1,12,1,12,1,12,5,12,117,8,12,10,12,12,12,120,9,12,3,12,122,8,12,1,
  	13,1,13,3,13,126,8,13,1,13,1,13,1,14,4,14,131,8,14,11,14,12,14,132,1,
  	14,1,14,0,0,15,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,0,19,0,21,0,23,9,
  	25,0,27,0,29,10,1,0,8,2,0,34,34,92,92,8,0,34,34,47,47,92,92,98,98,102,
  	102,110,110,114,114,116,116,3,0,48,57,65,70,97,102,1,0,48,57,1,0,49,57,
  	2,0,69,69,101,101,2,0,43,43,45,45,3,0,9,10,13,13,32,32,147,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,23,1,0,0,0,0,29,1,0,0,0,1,31,1,0,0,0,3,33,1,0,0,
  	0,5,35,1,0,0,0,7,37,1,0,0,0,9,39,1,0,0,0,11,44,1,0,0,0,13,50,1,0,0,0,
  	15,55,1,0,0,0,17,65,1,0,0,0,19,70,1,0,0,0,21,76,1,0,0,0,23,111,1,0,0,
  	0,25,121,1,0,0,0,27,123,1,0,0,0,29,130,1,0,0,0,31,32,5,123,0,0,32,2,1,
  	0,0,0,33,34,5,44,0,0,34,4,1,0,0,0,35,36,5,125,0,0,36,6,1,0,0,0,37,38,
  	5,58,0,0,38,8,1,0,0,0,39,40,5,116,0,0,40,41,5,114,0,0,41,42,5,117,0,0,
  	42,43,5,101,0,0,43,10,1,0,0,0,44,45,5,102,0,0,45,46,5,97,0,0,46,47,5,
  	108,0,0,47,48,5,115,0,0,48,49,5,101,0,0,49,12,1,0,0,0,50,51,5,110,0,0,
  	51,52,5,117,0,0,52,53,5,108,0,0,53,54,5,108,0,0,54,14,1,0,0,0,55,60,5,
  	34,0,0,56,59,3,17,8,0,57,59,8,0,0,0,58,56,1,0,0,0,58,57,1,0,0,0,59,62,
  	1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,61,63,1,0,0,0,62,60,1,0,0,0,63,64,
  	5,34,0,0,64,16,1,0,0,0,65,68,5,92,0,0,66,69,7,1,0,0,67,69,3,19,9,0,68,
  	66,1,0,0,0,68,67,1,0,0,0,69,18,1,0,0,0,70,71,5,117,0,0,71,72,3,21,10,
  	0,72,73,3,21,10,0,73,74,3,21,10,0,74,75,3,21,10,0,75,20,1,0,0,0,76,77,
  	7,2,0,0,77,22,1,0,0,0,78,80,5,45,0,0,79,78,1,0,0,0,79,80,1,0,0,0,80,81,
  	1,0,0,0,81,82,3,25,12,0,82,84,5,46,0,0,83,85,7,3,0,0,84,83,1,0,0,0,85,
  	86,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,89,1,0,0,0,88,90,3,27,13,0,
  	89,88,1,0,0,0,89,90,1,0,0,0,90,112,1,0,0,0,91,93,5,45,0,0,92,91,1,0,0,
  	0,92,93,1,0,0,0,93,94,1,0,0,0,94,95,3,25,12,0,95,96,3,27,13,0,96,112,
  	1,0,0,0,97,99,5,45,0,0,98,97,1,0,0,0,98,99,1,0,0,0,99,100,1,0,0,0,100,
  	101,3,25,12,0,101,103,5,46,0,0,102,104,7,3,0,0,103,102,1,0,0,0,104,105,
  	1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,112,1,0,0,0,107,109,5,45,
  	0,0,108,107,1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,112,3,25,12,0,
  	111,79,1,0,0,0,111,92,1,0,0,0,111,98,1,0,0,0,111,108,1,0,0,0,112,24,1,
  	0,0,0,113,122,5,48,0,0,114,118,7,4,0,0,115,117,7,3,0,0,116,115,1,0,0,
  	0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,122,1,0,0,0,120,
  	118,1,0,0,0,121,113,1,0,0,0,121,114,1,0,0,0,122,26,1,0,0,0,123,125,7,
  	5,0,0,124,126,7,6,0,0,125,124,1,0,0,0,125,126,1,0,0,0,126,127,1,0,0,0,
  	127,128,3,25,12,0,128,28,1,0,0,0,129,131,7,7,0,0,130,129,1,0,0,0,131,
  	132,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,134,1,0,0,0,134,135,6,
  	14,0,0,135,30,1,0,0,0,16,0,58,60,68,79,86,89,92,98,105,108,111,118,121,
  	125,132,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  jsonlexerLexerStaticData = staticData.release();
}

}

JSONLexer::JSONLexer(CharStream *input) : Lexer(input) {
  JSONLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *jsonlexerLexerStaticData->atn, jsonlexerLexerStaticData->decisionToDFA, jsonlexerLexerStaticData->sharedContextCache);
}

JSONLexer::~JSONLexer() {
  delete _interpreter;
}

std::string JSONLexer::getGrammarFileName() const {
  return "JSON.g4";
}

const std::vector<std::string>& JSONLexer::getRuleNames() const {
  return jsonlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& JSONLexer::getChannelNames() const {
  return jsonlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& JSONLexer::getModeNames() const {
  return jsonlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& JSONLexer::getVocabulary() const {
  return jsonlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView JSONLexer::getSerializedATN() const {
  return jsonlexerLexerStaticData->serializedATN;
}

const atn::ATN& JSONLexer::getATN() const {
  return *jsonlexerLexerStaticData->atn;
}




void JSONLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  jsonlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(jsonlexerLexerOnceFlag, jsonlexerLexerInitialize);
#endif
}
