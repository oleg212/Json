
// Generated from JSON.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "JSONParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by JSONParser.
 */
class  JSONVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by JSONParser.
   */
    virtual std::any visitJson(JSONParser::JsonContext *context) = 0;

    virtual std::any visitObj(JSONParser::ObjContext *context) = 0;

    virtual std::any visitPair(JSONParser::PairContext *context) = 0;

    virtual std::any visitStr(JSONParser::StrContext *context) = 0;

    virtual std::any visitInt(JSONParser::IntContext *context) = 0;

    virtual std::any visitObject(JSONParser::ObjectContext *context) = 0;

    virtual std::any visitNull(JSONParser::NullContext *context) = 0;


};

