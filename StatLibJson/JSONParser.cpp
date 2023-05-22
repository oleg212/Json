
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
      "json", "obj", "pair", "value"
    },
    std::vector<std::string>{
      "", "'{'", "','", "'}'", "':'", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,37,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	5,1,16,8,1,10,1,12,1,19,9,1,1,1,1,1,1,1,1,1,3,1,25,8,1,1,2,1,2,1,2,1,
  	2,1,3,1,3,1,3,1,3,3,3,35,8,3,1,3,0,0,4,0,2,4,6,0,0,37,0,8,1,0,0,0,2,24,
  	1,0,0,0,4,26,1,0,0,0,6,34,1,0,0,0,8,9,3,6,3,0,9,10,5,0,0,1,10,1,1,0,0,
  	0,11,12,5,1,0,0,12,17,3,4,2,0,13,14,5,2,0,0,14,16,3,4,2,0,15,13,1,0,0,
  	0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,20,1,0,0,0,19,17,1,0,0,
  	0,20,21,5,3,0,0,21,25,1,0,0,0,22,23,5,1,0,0,23,25,5,3,0,0,24,11,1,0,0,
  	0,24,22,1,0,0,0,25,3,1,0,0,0,26,27,5,6,0,0,27,28,5,4,0,0,28,29,3,6,3,
  	0,29,5,1,0,0,0,30,35,5,6,0,0,31,35,5,7,0,0,32,35,3,2,1,0,33,35,5,5,0,
  	0,34,30,1,0,0,0,34,31,1,0,0,0,34,32,1,0,0,0,34,33,1,0,0,0,35,7,1,0,0,
  	0,3,17,24,34
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

JSONParser::ValueContext* JSONParser::JsonContext::value() {
  return getRuleContext<JSONParser::ValueContext>(0);
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
    setState(8);
    value();
    setState(9);
    match(JSONParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjContext ------------------------------------------------------------------

JSONParser::ObjContext::ObjContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JSONParser::PairContext *> JSONParser::ObjContext::pair() {
  return getRuleContexts<JSONParser::PairContext>();
}

JSONParser::PairContext* JSONParser::ObjContext::pair(size_t i) {
  return getRuleContext<JSONParser::PairContext>(i);
}


size_t JSONParser::ObjContext::getRuleIndex() const {
  return JSONParser::RuleObj;
}


std::any JSONParser::ObjContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitObj(this);
  else
    return visitor->visitChildren(this);
}

JSONParser::ObjContext* JSONParser::obj() {
  ObjContext *_localctx = _tracker.createInstance<ObjContext>(_ctx, getState());
  enterRule(_localctx, 2, JSONParser::RuleObj);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(11);
      match(JSONParser::T__0);
      setState(12);
      pair();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == JSONParser::T__1) {
        setState(13);
        match(JSONParser::T__1);
        setState(14);
        pair();
        setState(19);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(20);
      match(JSONParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(22);
      match(JSONParser::T__0);
      setState(23);
      match(JSONParser::T__2);
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

//----------------- PairContext ------------------------------------------------------------------

JSONParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JSONParser::PairContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::ValueContext* JSONParser::PairContext::value() {
  return getRuleContext<JSONParser::ValueContext>(0);
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
    value();
   
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


size_t JSONParser::ValueContext::getRuleIndex() const {
  return JSONParser::RuleValue;
}

void JSONParser::ValueContext::copyFrom(ValueContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StrContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::StrContext::STRING() {
  return getToken(JSONParser::STRING, 0);
}

JSONParser::StrContext::StrContext(ValueContext *ctx) { copyFrom(ctx); }


std::any JSONParser::StrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullContext ------------------------------------------------------------------

JSONParser::NullContext::NullContext(ValueContext *ctx) { copyFrom(ctx); }


std::any JSONParser::NullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* JSONParser::IntContext::NUMBER() {
  return getToken(JSONParser::NUMBER, 0);
}

JSONParser::IntContext::IntContext(ValueContext *ctx) { copyFrom(ctx); }


std::any JSONParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjectContext ------------------------------------------------------------------

JSONParser::ObjContext* JSONParser::ObjectContext::obj() {
  return getRuleContext<JSONParser::ObjContext>(0);
}

JSONParser::ObjectContext::ObjectContext(ValueContext *ctx) { copyFrom(ctx); }


std::any JSONParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JSONVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}
JSONParser::ValueContext* JSONParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, JSONParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JSONParser::STRING: {
        _localctx = _tracker.createInstance<JSONParser::StrContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(30);
        match(JSONParser::STRING);
        break;
      }

      case JSONParser::NUMBER: {
        _localctx = _tracker.createInstance<JSONParser::IntContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(31);
        match(JSONParser::NUMBER);
        break;
      }

      case JSONParser::T__0: {
        _localctx = _tracker.createInstance<JSONParser::ObjectContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(32);
        obj();
        break;
      }

      case JSONParser::T__4: {
        _localctx = _tracker.createInstance<JSONParser::NullContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(33);
        match(JSONParser::T__4);
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

void JSONParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  jsonParserInitialize();
#else
  ::antlr4::internal::call_once(jsonParserOnceFlag, jsonParserInitialize);
#endif
}
