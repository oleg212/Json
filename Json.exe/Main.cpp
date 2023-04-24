#include "Json.h"
#include "Value.h"

#include <iostream>
#include <fstream>
#include "stdio.h"



using namespace std;
//using namespace Json_net;
int main() {
	ifstream file("test.json");
	Json j;
	file >> j;
	cout << j;

	//cout << j.GetCur()->ToString() << endl;
	//j.GoRight();
	//cout << j.GetCur()->ToString() << endl;
	//j.GoNext();
	//cout << j.GetCur()->ToString() << endl;

	//cout << j.GetCurRow();

	j.delcur();

	cout << j.GetCur()->ToString() << endl;
	cout << j.GetCurRow();

	return 0;
}