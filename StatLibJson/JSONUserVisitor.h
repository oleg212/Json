#pragma once

#include "antlr4-runtime.h"
#include "JSONBaseVisitor.h"
#include "Value.h"

#include <iostream>
#include <vector>

#include <string>

using namespace std;


class  JSONUserVisitor : public JSONBaseVisitor {
public:

	Value* res;

    virtual std::any visitJson(JSONParser::JsonContext* ctx) override {
		std::cout << "json" << ctx->getTreeType() << std::endl;
		std::any r(res);
        r = visit(ctx->value());
		return visitChildren(ctx);
    }

    virtual std::any visitObj(JSONParser::ObjContext* ctx) override {

      //Value* Root;
      //for (auto pairContext : ctx->pair()) {
      //      std::string key = pairContext->STRING()->getText();
      //      std::string val = any_cast<std::string>(pairContext->value());
      //      if (val[0]='"')
      //      Root[key] = value;
      //  }
      //  return jsonObject;
        return visitChildren(ctx);




		//std::cout << "obj^" << std::endl;
		//std::vector<JSONParser::PairContext*> arr = ctx->pair();
    //    for (JSONParser::PairContext* pair : ctx->pair())
    //        visit(pair);

    //    return visitChildren(ctx);
    }

    virtual std::any visitPair(JSONParser::PairContext* ctx) override {
		std::cout << "pair" << std::endl;
        string key = any_cast<string>(visit(ctx->STRING()));
        key = key.substr(1, key.length() - 2);
        std::cout << key << std::endl;
		return visitChildren(ctx);
    }

    virtual std::any visitStr(JSONParser::StrContext* ctx) override {
		std::cout << "str" << std::endl;
        return (ctx->STRING()->getText());
    }

    virtual std::any visitInt(JSONParser::IntContext* ctx) override {
		std::cout << "int" << std::endl;
        return std::stoi(ctx->NUMBER()->getText());
    }

    virtual std::any visitObject(JSONParser::ObjectContext* ctx) override {
		std::cout << "obj" << std::endl;
        return visit(ctx->obj());
    }

    virtual std::any visitNull(JSONParser::NullContext* ctx) override {
		std::cout << "null" << std::endl;
        return nullptr;
    }


};

