//#include "Json.h"
//#include "Value.h"


//#include "..\DLLJson\RefJson.h"

#include <iostream>
#include <fstream>
#include "stdio.h"


using namespace Json_net;
using namespace std;

int main() {

	rfJson js;
	js.ReadFromFile("test.json");
	js.print();


	/*ifstream file("test.json");
	Json* j = new Json();
	j->parse("test.json");
	cout << *j;
	delete j;*/
	return 0;
}

