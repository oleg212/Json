
// Generated from JSON.g4 by ANTLR 4.13.0


#include "JSONVisitor.h"

#include "JSONParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct JSONParserStaticData final {
  JSONParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JSONParserStaticData(const JSONParserStaticData&) = delete;
  JSONParserStaticData(JSONParserStaticData&&) = delete;
  JSONParserStaticData& operator=(const JSONParserStaticData&) = delete;
  JSONParserStaticData& operator=(JSONParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag jsonParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
JSONParserStaticData *jsonParserStaticData = nullptr;

void jsonParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (jsonParserStaticData != nullptr) {
    return;
  }
#else
  assert(jsonParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<JSONParserStaticData>(
    std::vector<std::string>{
      "json", "object", "pair", "array", "element", "value"
    },
    std::vector<std::string>{
      "", "'{'", "','", "'}'", "':'", "'true'", "'false'", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,10,49,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,5,1,20,8,1,10,1,12,1,23,9,1,1,1,1,1,1,2,1,2,1,2,1,2,1,
  	3,1,3,1,3,1,3,5,3,35,8,3,10,3,12,3,38,9,3,1,3,1,3,1,4,1,4,1,4,3,4,45,
  	8,4,1,5,1,5,1,5,0,0,6,0,2,4,6,8,10,0,1,1,0,5,9,46,0,12,1,0,0,0,2,15,1,
  	0,0,0,4,26,1,0,0,0,6,30,1,0,0,0,8,44,1,0,0,0,10,46,1,0,0,0,12,13,3,2,
  	1,0,13,14,5,0,0,1,14,1,1,0,0,0,15,16,5,1,0,0,16,21,3,4,2,0,17,18,5,2,
  	0,0,18,20,3,4,2,0,19,17,1,0,0,0,20,23,1,0,0,0,21,19,1,0,0,0,21,22,1,0,
  	0,0,22,24,1,0,0,0,23,21,1,0,0,0,24,25,5,3,0,0,25,3,1,0,0,0,26,27,5,8,
  	0,0,27,28,5,4,0,0,28,29,3,8,4,0,29,5,1,0,0,0,30,31,5,1,0,0,31,36,3,8,
  	4,0,32,33,5,2,0,0,33,35,3,8,4,0,34,32,1,0,0,0,35,38,1,0,0,0,36,34,1,0,
  	0,0,36,37,1,0,0,0,37,39,1,0,0,0,38,36,1,0,0,0,39,40,5,3,0,0,40,7,1,0,
  	0,0,41,45,3,10,5,0,42,45,3,2,1,0,43,45,3,6,3,0,44,41,1,0,0,0,44,42,1,
  	0,0,0,44,43,1,0,0,0,45,9,1,0,0,0,46,47,7,0,0,0,47,11,1,0,0,0,3,21,36,
  	44
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  jsonParserStaticData = staticData.release();
}

}

JSONParser::JSONParser(TokenStream *input) : JSONParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

JSONParser::JSONParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  JSONParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *jsonParserStaticData->atn, jsonParserStaticData->decisionToDFA, jsonParserStaticData->sharedContextCache, options);
}

JSONParser::~JSONParser() {
  delete _interpreter;
}

const atn::ATN& JSONParser::getATN() const {
  return *jsonParserStaticData->atn;
}

std::string JSONParser::getGrammarFileName() const {
  return "JSON.g4";
}

const std::vector<std::string>& JSONParser::getRuleNames() const {
  return jsonParserStaticData->ruleNames;
}

const dfa::Vocabulary& JSONParser::getVocabulary() const {
  return jsonParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView JSONParser::getSerializedATN() const {
  return jsonParserStaticData->serializedATN;
}


//----------------- JsonContext ------------------------------------------------------------------

JSONParser::JsonContext::JsonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JSONParser::ObjectContext* JSONParser::JsonContext::object() {
  return getRuleContext<JSONParser::ObjectContext>(0);
}

tree::TerminalNode* JSONParser::JsonContext::EOF() {
  return getToken(JSONParser::EOF, 0);
}


size_t JSONParser::JsonContext::getRuleIndex() const {
  return JSONParser::RuleJson;
}


std::any JSONParser::JsonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitJson(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::JsonContext* JSONParser::json() {
  JsonContext *_localctx = _tracker.createInstance<JsonContext>(_ctx, getState());
  enterRule(_localctx, 0, JSONParser::RuleJson);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    object();
    setState(13);
    match(JSONParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

JSONParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JSONParser::PairContext *> JSONParser::ObjectContext::pair() {
  return getRuleContexts<JSONParser::PairContext>();
}

JSONParser::PairContext* JSONParser::ObjectContext::pair(size_t i) {
  return getRuleContext<JSONParser::PairContext>(i);
}


size_t JSONParser::ObjectContext::getRuleIndex() const {
  return JSONParser::RuleObject;
}


std::any JSONParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ObjectContext* JSONParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 2, JSONParser::RuleObject);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    match(JSONParser::T__0);
    setState(16);
    pair();
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JSONParser::T__1) {
      setState(17);
      match(JSONParser::T__1);
      setState(18);
      pair();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(24);
    match(JSONParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

JSONParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::PairContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::ElementContext* JSONParser::PairContext::element() {
  return getRuleContext<JSONParser::ElementContext>(0);
}


size_t JSONParser::PairContext::getRuleIndex() const {
  return JSONParser::RulePair;
}


std::any JSONParser::PairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitPair(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::PairContext* JSONParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 4, JSONParser::RulePair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(JSONParser::STRING);
    setState(27);
    match(JSONParser::T__3);
    setState(28);
    element();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

JSONParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JSONParser::ElementContext *> JSONParser::ArrayContext::element() {
  return getRuleContexts<JSONParser::ElementContext>();
}

JSONParser::ElementContext* JSONParser::ArrayContext::element(size_t i) {
  return getRuleContext<JSONParser::ElementContext>(i);
}


size_t JSONParser::ArrayContext::getRuleIndex() const {
  return JSONParser::RuleArray;
}


std::any JSONParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ArrayContext* JSONParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 6, JSONParser::RuleArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(JSONParser::T__0);
    setState(31);
    element();
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JSONParser::T__1) {
      setState(32);
      match(JSONParser::T__1);
      setState(33);
      element();
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(39);
    match(JSONParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

JSONParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JSONParser::ValueContext* JSONParser::ElementContext::value() {
  return getRuleContext<JSONParser::ValueContext>(0);
}

JSONParser::ObjectContext* JSONParser::ElementContext::object() {
  return getRuleContext<JSONParser::ObjectContext>(0);
}

JSONParser::ArrayContext* JSONParser::ElementContext::array() {
  return getRuleContext<JSONParser::ArrayContext>(0);
}


size_t JSONParser::ElementContext::getRuleIndex() const {
  return JSONParser::RuleElement;
}


std::any JSONParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ElementContext* JSONParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 8, JSONParser::RuleElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      object();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(43);
      array();
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

//----------------- ValueContext ------------------------------------------------------------------

JSONParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::ValueContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

tree::TerminalNode* JSONParser::ValueContext::NUMBER() {
  return getToken(JSONParser::NUMBER, 0);
}


size_t JSONParser::ValueContext::getRuleIndex() const {
  return JSONParser::RuleValue;
}


std::any JSONParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ValueContext* JSONParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 10, JSONParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 992) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void JSONParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  jsonParserInitialize();
#else
  ::antlr4::internal::call_once(jsonParserOnceFlag, jsonParserInitialize);
#endif
}
