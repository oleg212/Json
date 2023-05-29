#include <iostream>
#include "JsonBaseVisitor.h"
#include "Value.h"
#include "Json.h"
using namespace antlrcpp;
using namespace antlr4;

class JSONUserVisitor : public JSONBaseVisitor {
    Value* Root = nullptr;
    string tempname;
    Pointer* p = nullptr;;
    bool rb = false;
    int depth = 1;
    public:
        virtual antlrcpp::Any visitObject(JSONParser::ObjectContext* ctx) override {
            depth++;
            if (tempname != "") {
                if (p == nullptr) {
                    p = new Pointer();
                }
                if(rb==1)
                    p->AddRight(new ValueArr(tempname, ctx->depth()));
                else
                    p->AddNext(new ValueArr(tempname, ctx->depth()));
                if (Root == nullptr) { Root = p->GetCur(); }
                rb = 1;
                tempname = "";
            }
            std::cout << "{";
            int size = ctx->pair().size();
            for (int i = 0; i < size; i++) {
                visit(ctx->pair(i));
                if (i < size - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "}";
            depth--;
            if(p->GetCur() != nullptr)
            p->GoUp();
            return nullptr;
        }

        virtual antlrcpp::Any visitPair(JSONParser::PairContext* ctx) override {

            tempname = ctx->STRING()->getText();
            
            tempname.erase(0, 1);  
            tempname.erase(tempname.size() - 1); 
            std::cout << "\"" << ctx->STRING()->getText() << "\":";
            visit(ctx->element());
            return nullptr;
        }



        virtual antlrcpp::Any visitValue(JSONParser::ValueContext* ctx) override {
            antlr4::tree::TerminalNode* node = dynamic_cast<antlr4::tree::TerminalNode*>(ctx->children[0]);
            std::cout << node->getText();
            string val = node->getText();
            
            if (rb) {
                rb = false;
                if (val.find('"') == -1) {
                    p->AddRight(new ValueInt(tempname, ctx->depth()));
                    p->SetContent(val);
                }
                else {
                    p->AddRight(new ValueStr(tempname, ctx->depth()));
                    p->SetContent(val);
                }
            }
            else {
                if (val.find('"') == -1)
                    p->AddNext(new ValueInt(tempname, ctx->depth()));
                else
                    p->AddNext(new ValueStr(tempname, ctx->depth()));
                p->SetContent(val);
            }
            tempname = "";
            return nullptr;
        }
        Value* GetRoot() {
            if (Root != nullptr) {
                return Root;
            }
            else throw - 1;
        }
    };


   