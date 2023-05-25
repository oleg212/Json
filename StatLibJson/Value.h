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
		depth = _depth;
	};
	~Value() {
		delete data;
		delete next;
	};
	string ToString() 
	{
		string s = ( tab(GetDepth()) + '"' + GetKey() + '"' + ':');
		if (GetContent() != "")
		{
			s += GetContent();
			if (next != nullptr) s += ",";
			s += "\n";
		}
		if (GetType() == "array ") {
			s += "\t{\n";
			if (getdata() == nullptr) s += "\t}\n";
		}
		//if (next == nullptr)
		//	s += "}\n";
		return s;
	}
	string To_String() {
		return ("[D:" + to_string(GetDepth()) + "] " + GetKey() + ':' + GetContent());
	}
	virtual string GetType() = 0;
	int GetDepth() { return depth; }
	string GetKey() { return key; };
	virtual string GetContent() = 0;

	virtual void SetContent(string s) = 0;

	void setnext(Value* _next) { /*if (_next != nullptr) _next->next = next; */next = _next; }
	void setdata(Value* _data) { /*if (_data != nullptr) _data->next = data; */data = _data; }
	Value* getnext() { return next; }
	Value* getdata() { return data; }
	string tab(int d) {
		string res;
		for (int i = 0; i < d; i++) {
			res += " ";
		}
		return res;
	}
	friend ostream& operator <<(ostream& out, Value& v) {
		out << v.tab(v.depth) << '"' << v.GetKey() << '"' << ": ";
		if (v.GetContent() != "")
			out << v.GetContent();
		if (v.data != nullptr) {
			out << "{" << '\n' << *v.data << v.tab(v.depth) << "}" << '\n';
		}

		if (v.next != nullptr) {
			out <<"," << endl << *v.next;
		}

		return out;
	};

	string GetLeafs()
	{
		string s = '"' + GetKey() + '"' + ": ";
		if (GetContent() != "")
			s += GetContent() + ",";
		if (data != nullptr)
		{
			s += "\n{\n";
			Value* tmp = data;
			while (tmp != nullptr)
			{
				s += tab(1) + '"' + tmp->GetKey() + '"' + ": ";
				if (tmp->GetContent() != "")
					s += tmp->GetContent() + ",\n";
				if (tmp->data != nullptr)
					s += "{ }\n";
				tmp = tmp->next;
			}
		}
		s += "}\n";
		return s;
	}
};

class ValueStr : public Value {
	string content = "";
public:
	using Value::Value;
	//using Value::~Value;
	void SetContent(string _str) override { content = _str; }
	string GetType() override {
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
	void SetContent(string s) override { content = stoi(s); }
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
	void SetContent(string s) override { return; }
	string GetType() override {
		return("array ");
	}
	string GetContent() override {
		return "";
	};

};
