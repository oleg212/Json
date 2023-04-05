#pragma once
#include <string>
#include <iostream>;
using namespace std;



class Value {
	Value* data;
	Value* next;
	string key;
	int depth;
public:
	Value(string _key, int _depth) {
		key = _key;
		next = nullptr;
		data = nullptr;
		depth= _depth;
	};

	virtual string GetType() = 0;
	string GetKey() { return key; };
	virtual string GetContent() = 0;
	
	virtual void SetContent(string s) = 0;

	void setnext(Value* _next) { next = _next; }
	void setdata(Value* _data) { data = _data; }
	Value* getnext() { return next; }
	Value* getdata() { return data; }
	string tab(int d) {
		string res;
		for (int i = 0; i < d; i++) {
			res += "   ";
		}
		return res;
	}
	friend ostream& operator <<(ostream& out, Value& v) {
		
		out <<v.tab(v.depth) << '"' << v.GetKey() << '"' << ": ";
		if (v.GetContent()!="0")
			out << v.GetContent() << "," << endl;
		if (v.data != nullptr) {
			out <<"{"<<'\n'<< * v.data   <<v.tab(v.depth)<< "}"<< '\n';
		}

		if (v.next != nullptr) {
			out << *v.next;
		}
		
		return out;
		
	};
};

class ValueStr: public Value {
	string content="";
public:
	using Value::Value;
	void SetContent(string _str) override {content=_str;}
	string GetType() override  {
		return("string ");
	}
	string GetContent() override {
		return content;	
	};	
};

class ValueInt : public Value {
	int content;
public:
	using Value::Value;
	//ValueInt(string _key, int _content) { key = _key; }
	void SetContent(string s ) override { content = stoi(s); }
	string GetType() override {
		return("int ");
	}	
	string GetContent() override {
		return to_string(content);
	};
};

class ValueArr : public Value {

public:
	using Value::Value;
	void SetContent(Value* _data) { setdata(_data); }
	string GetType() override {
		return("array ");
	}
	string GetContent() override {
		return " ";
	};

};


 