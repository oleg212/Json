#include "Json.h"
#include "Value.h"

#include <iostream>
#include <fstream>
#include "stdio.h"

using namespace std;

int main() {
	ifstream file("test.json");
	Json j;
	file >> j;
	cout<< j;
	return 0;
}