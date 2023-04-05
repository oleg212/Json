#pragma once
#include <string>
#include <iostream>;
using namespace std;








template<class T>
class Value {
	T data;
	Value* next;
	string key;
public:
	Value(string _key) {
		key = _key;
		next = nullptr;
		
	};
	Value(string _key, T _data) {
		key = _key;
		next = nullptr;
		data = _data;
	};
	string GetType() { return typeof(T); };
	string GetKey() { return key; };
	void SetData(T _data) {
		data = _data;
	}
	template<class T>
	void setnext(string _key, T _data) {
		next = new Value<T>(_key, data);
	}

	Value* getnext() { return next; }
	T* getdata() { return data; }
	friend ostream& operator <<(ostream& out, Value& v) {

		out << '"' << v.GetKey() << '"' << ": " << v.GetContent();
		if (v.GetContent() != " ") out << "," << endl;
		if (v.data != nullptr) {
			out << "{" << '\n' << *v.data << "}";
		}

		if (v.next != nullptr) {
			out << *v.next;
		}

		return out;

	};
};

