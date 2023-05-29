#include "Json.h"
#include "JSONUserVisitor.h"
#include "antlr4\antlr4-runtime.h"
#include "JSONLexer.h"
#include "JSONParser.h"

void Json::parse(string filename)
{
	ifstream file(filename);
	std::string s_raw;
	string temp;
	while (file) {
		getline(file,temp);
		s_raw += temp;
	}
	string s = s_raw;

	std::stringstream stream(s);
	antlr4::ANTLRInputStream input(stream);
	JSONLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	JSONParser parser(&tokens);
	JSONUserVisitor visitor;
	visitor.visit(parser.json());

	delete Root;
	Root = visitor.GetRoot();
	pointer_reset();
	return;


}