
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "STRING", "NUMBER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'{'", "','", "'}'", "':'", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,59,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,5,
  	5,33,8,5,10,5,12,5,36,9,5,1,5,1,5,1,6,3,6,41,8,6,1,6,1,6,5,6,45,8,6,10,
  	6,12,6,48,9,6,1,6,3,6,51,8,6,1,7,4,7,54,8,7,11,7,12,7,55,1,7,1,7,1,34,
  	0,8,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,1,0,3,1,0,49,57,1,0,48,57,3,0,
  	9,10,13,13,32,32,63,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
  	9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,19,1,
  	0,0,0,5,21,1,0,0,0,7,23,1,0,0,0,9,25,1,0,0,0,11,30,1,0,0,0,13,50,1,0,
  	0,0,15,53,1,0,0,0,17,18,5,123,0,0,18,2,1,0,0,0,19,20,5,44,0,0,20,4,1,
  	0,0,0,21,22,5,125,0,0,22,6,1,0,0,0,23,24,5,58,0,0,24,8,1,0,0,0,25,26,
  	5,110,0,0,26,27,5,117,0,0,27,28,5,108,0,0,28,29,5,108,0,0,29,10,1,0,0,
  	0,30,34,5,34,0,0,31,33,9,0,0,0,32,31,1,0,0,0,33,36,1,0,0,0,34,35,1,0,
  	0,0,34,32,1,0,0,0,35,37,1,0,0,0,36,34,1,0,0,0,37,38,5,34,0,0,38,12,1,
  	0,0,0,39,41,5,45,0,0,40,39,1,0,0,0,40,41,1,0,0,0,41,42,1,0,0,0,42,46,
  	7,0,0,0,43,45,7,1,0,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,46,47,
  	1,0,0,0,47,51,1,0,0,0,48,46,1,0,0,0,49,51,5,48,0,0,50,40,1,0,0,0,50,49,
  	1,0,0,0,51,14,1,0,0,0,52,54,7,2,0,0,53,52,1,0,0,0,54,55,1,0,0,0,55,53,
  	1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,57,58,6,7,0,0,58,16,1,0,0,0,6,0,34,
  	40,46,50,55,1,6,0,0
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
