
// Generated from JSON.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4\antlr4-runtime.h"
#include "JSONVisitor.h"


/**
 * This class provides an empty implementation of JSONVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JSONBaseVisitor : public JSONVisitor {
public:

  virtual std::any visitJson(JSONParser::JsonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObject(JSONParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPair(JSONParser::PairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(JSONParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElement(JSONParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(JSONParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

