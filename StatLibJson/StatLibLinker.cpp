#include "Json.h"
#include "JSONUserVisitor.h"
#include "antlr4-runtime.h"
#include "JSONLexer.h"
#include "JSONParser.h"

void Json::parse()
{
	ifstream file("test.json");
	std::string s;
	file >> s;
	std::stringstream stream(s);
	antlr4::ANTLRInputStream input(stream);
	JSONLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	JSONParser parser(&tokens);
	JSONUserVisitor visitor;
	visitor.visit(parser.json());

}