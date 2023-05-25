#include "Json.h"
#include "JSONUserVisitor.h"
#include "antlr4\antlr4-runtime.h"
#include "JSONLexer.h"
#include "JSONParser.h"

void Json::parse()
{
	ifstream file("test.json");
	std::string s_raw;
	//file >> s_raw;
	string temp;
	while (file) {
		getline(file,temp);
		s_raw += temp;
	}
	/*int len = s_raw.length();
	string s = "";
	bool name = false;
	for (int i = 0; i < len; i++) {
		if (s_raw[i] != ' ') {
			if (s_raw[i] == '"') name = !name;
			s += s_raw[i];
		}
		else {
			if (name) {
				s += '_';
			}
		}
	}*/

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


}