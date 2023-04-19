#pragma once
#include "Value.h"
#include <stack>
using namespace std;

class Pointer {
	Value* cur;
	stack<Value*> path;
public:
	Pointer() { cur = nullptr; }
	Pointer(Value* root) { cur = root; }
	Value* GetCur() { return cur; }
	void GoNext() { path.push(cur); cur = cur->getnext(); }
	void GoRight() { path.push(cur); cur = cur->getdata(); }
	void GoBack() { cur = path.top(); path.pop(); }
	void GoUp() {
		Value* prev = cur;
		GoBack();
		while (cur->getdata() != prev) {
			if (cur->GetDepth() == 1) break;
			prev = cur;
			GoBack();
		}
	}
	void AddNext(Value* _next) {
		if (cur == nullptr) { cur = _next; return; }
		cur->setnext(_next);
		GoNext();
	}
	void AddRight(Value* _right) {
		cur->setdata(_right);
		GoRight();
	}
	void SetContent(int _content) {
		cur->SetContent(to_string(_content));
	}
	void SetContent(string _content) {
		cur->SetContent(_content);
	}
	bool isempty() { return path.empty(); }
	string show() {
		return cur->GetKey() + ":" + cur->GetContent() + '\n';
	}
};

class Json {
	Value* Root;
	int count_elems(string s) {
		int res = 0;
		int size = s.size();
		for (int i = 0; i < size; i++) { if (s[i] != ' ') { res++; } };
		return res;
	}
	string get_key(string s) {
		string res = "";
		int size = s.size();
		int i = s.find('"');
		i++;
		while (s[i] != '"') {
			res += s[i];
			i++;
		}
		return res;
	}
	string get_value(string s) {
		string res = "";
		int size = s.size();
		int i = s.find(':');
		i++;
		while ((s[i] != ',') && (i < size)) {
			res += s[i];
			i++;
		}
		return res;
	}
public:
	Pointer* p;
	Json() { Root = nullptr; p = new Pointer(); }
	~Json() {
		delete Root;
		delete p;
	}
	friend ostream& operator <<(ostream& out, Json& v) {
		out << "\n{" << endl << *v.Root << "}\n" << endl;
		return out;
	}
	friend istream& operator>>(istream& istr, Json& json)
	{
		//string temp;
		//int depth = 1;
		//string key = "";
		//string val = "";
		//int type; //1 - string, 2 - int, 3 - array
		//bool state = 1; // мы считываем либо ключ либо значение
		//char cur = '0';
		//bool rb = 0;	//ждет ли массив первое значение
		//getline(istr, temp);

		//getline(istr, temp);

		//key = json.get_key(temp);
		//if (temp.find('{') != -1) {
		//	type = 3;

		//	json.Root = (new ValueArr(key, depth));
		//	depth++;
		//	rb = 1;
		//}
		//else {
		//	val = json.get_value(temp);
		//	if (val.find('"') == val.size()) {
		//		type = 2;
		//		json.Root = (new ValueInt(key, depth));
		//		json.Root->SetContent(val);
		//		rb = 0;

		//	}
		//	else {
		//		type = 1;
		//		json.Root = (new ValueStr(key, depth));

		//		json.Root->SetContent(val);
		//		rb = 0;
		//	}
		//}
		//json.p = new Pointer(json.Root);
		//while (istr) {

		//	getline(istr, temp);
		//	if (temp.find('}') != -1) {
		//		depth--;
		//		if (json.p->isempty())break;
		//		json.p->GoUp(); continue;

		//	};
		//	key = json.get_key(temp);

		//	if (temp.find('{') != -1) {
		//		type = 3;

		//		if (rb == 0)json.p->AddNext(new ValueArr(key, depth));
		//		else json.p->AddRight(new ValueArr(key, depth));
		//		rb = 1;
		//		depth++;
		//	}
		//	else {
		//		val = json.get_value(temp);
		//		if (val.find('"') == -1) {
		//			type = 2;
		//			if (rb == 0) json.p->AddNext(new ValueInt(key, depth));
		//			else json.p->AddRight(new ValueInt(key, depth));
		//			json.p->SetContent(stoi(val));
		//			rb = 0;

		//		}
		//		else {
		//			type = 1;
		//			if (rb == 0)json.p->AddNext(new ValueStr(key, depth));
		//			else json.p->AddRight(new ValueStr(key, depth));
		//			json.p->SetContent(val);
		//			rb = 0;
		//		}
		//	}
		//}
		string file = "";
		string temp;
		while (istr) {
			getline(istr, temp);
			file += temp;
		}
		//string* tokens;
		int l = file.length();
		int type; //1 - string, 2 - int, 3 - array
		int depth = 1;
		int i = 1;
		bool rb = 0;
		bool first = 1;
		string s;
		while (i<l-1) {
			if ((file[i] != ',')&&((file[i] != '{')) && ((file[i] != '}'))) {
				s += file[i];
			}
			else {
				if ((s == "")||(s.find('"')==-1)) {
					i++;
					continue;
				}
				if (file[i] == '{') {
					s += file[i];
					Value* newvalue = json.process(s, depth);
					if (rb) {
						json.p->AddRight(newvalue);
					}
					else {
						if (first) json.Root = newvalue;
						json.p->AddNext(newvalue);
					}
					depth++;
					rb = 1;
				}
				else {
					Value* newvalue = json.process(s, depth);
					if (rb) { json.p->AddRight(newvalue);rb = 0; }
					else { json.p->AddNext(newvalue); 
					if (first) json.Root = newvalue;
					}
					
				}
				if (file[i] == '}') {
					json.p->GoUp();
 					depth--;
				}
				s.clear();
				first = 0;
			}
			i++;

		}


		return istr;
	}
	Value* process(string s, int depth) {
		string name = get_key(s);
		if (s.find('{') != -1) {
			Value* res = new ValueArr(name, depth);
			return res;
		}
		else {			
			string value = get_value(s);
			if (s.find('"') == -1) {
				Value* res = new ValueInt(name, depth);
				res->SetContent(value);
				return res;
			}
			else {
				Value* res = new ValueStr(name, depth);
				res->SetContent((value));
				return res;
			}

		}
		
	}
	Value* GetCur() { return p->GetCur(); }
	void GoNext() {
		if (GetCur()->getnext() != nullptr)p->GoNext();
		else throw - 1;
	}
	void GoRight() {
		if (GetCur()->getdata() != nullptr)
		{
			p->GoRight();
		}
		else { throw - 1; }
	}
	void GoBack() {
		if (!p->isempty()) p->GoBack();
		else throw - 1;
	}
	void GoUp() {
		if (!p->isempty()) p->GoUp();
		else throw - 1;
	}
	void AddNext(Value* _next) {
		p->AddNext(_next);
	}
	void AddRight(Value* _right) {
		p->AddRight(_right);
	}
	void SetContent(int _content) {
		p->SetContent(_content);
	}
	void SetContent(string _content) {
		p->SetContent(_content);
	}

	string GetCurRow()
	{
		return GetCur()->GetLeafs();
	}
};
