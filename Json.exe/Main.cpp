#include "Json.h"
#include "Value.h"

#include <iostream>
#include <fstream>
#include "stdio.h"



using namespace std;

int main() {
	ifstream file("test.json");
	Json j;
	j.parse();
	cout << j;
	return 0;
}

