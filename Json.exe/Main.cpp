#include "Json.h"
#include "Value.h"

#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include "stdio.h"



using namespace std;
using namespace Json_net;
int main() {
	ifstream file("test.json");
	Json j;
	rfJson^ rfj = gcnew rfJson();
	rfj->ReadFromFile("D:\\git_reps\\Json\\Json\\test.json");
	//file >> j;
	//cout << j;

	//cout << j.GetCur()->ToString() << endl;
	//j.GoRight();
	//cout << j.GetCur()->ToString() << endl;
	//j.GoNext();
	//cout << j.GetCur()->ToString() << endl;
	//j.GoNext();

	//cout << j.GetCurRow();



	string content = msclr::interop::marshal_as<std::string>( rfj->WriteAsString());
	cout << content;
	rfj->GoRight();

	rfValueStr^ str = gcnew rfValueStr("key", 2);
	str->SetContent("\"content\"");

	rfj->AddNext(str);

	content = msclr::interop::marshal_as<std::string>(rfj->WriteAsString());
	cout << content;

	//j.delcur();
	//try{
	//j.GoRight();
	//}
	//catch (int a)
	//{
	//	cout << "catch" << endl;
	//	}
	//cout << j;

	return 0;
}

