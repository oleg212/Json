#pragma once
#include "Value.h"
#include <sstream>
#include <stack>

using namespace std;

class Pointer {
	Value* cur;
	stack<Value*> path;
public:
	Pointer() { cur = nullptr; }
	Pointer(Value* root) { cur = root; }
	void init(Value* root) { cur = root; path = stack<Value*>(); }
	Value* GetCur() { return cur; }
	bool HasNext() { return GetCur()->getnext() != nullptr; }
	bool HasRight() { return GetCur()->getdata() != nullptr; }
	bool HasBack() { return !isempty(); }
	bool HasUp() { return !isempty(); }
	void GoNext() { path.push(cur); cur = cur->getnext(); }
	void GoRight() { path.push(cur); cur = cur->getdata(); }
	void GoBack() { if (path.empty()) return; cur = path.top(); path.pop(); }
	void GoUp() {
		if (path.empty()) return;
		Value* prev = cur;
		GoBack();
		while ((cur->getdata() != prev)) {
			if (cur->GetDepth() == 1) break;
			prev = cur;
			GoBack();
		}
	}
	void AddNext(Value* _next) {
		if (cur == nullptr) {
			cur = _next; return; 
		}
		_next->setnext(cur->getnext());
		cur->setnext(_next);
		GoNext();
	}
	void AddRight(Value* _right) {
		_right->setnext(cur->getdata());
		cur->setdata(_right);

		GoRight();
	}
	void SetContent(int _content) {
		cur->SetContent(to_string(_content));
	}
	void SetContent(string _content) {
		cur->SetContent(_content);
	}
	void SetNext(Value* _next) {
		cur->setnext(_next);
	}
	void delcur() {
		if (cur == nullptr) return;
		Value* tmp = cur;
		if (path.empty())
		{
			cur = nullptr;
			delete tmp;
			return;
		}

		GoBack();
		if (cur->getdata() == tmp) {
			cur->setdata(tmp->getnext());
			tmp->setnext(nullptr);
		}
		else {
			cur->setnext(tmp->getnext());
			tmp->setnext(nullptr);
		}
		delete tmp;
		}
		bool isempty() { return path.empty(); }
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
	void pointer_reset() {
		while (!p->isempty()) {
			p->GoBack();
		}
		p->AddNext(Root);
	}
public:
	Pointer* p;
	Json() { Root = nullptr; p = new Pointer(); }
	~Json() {
		//if (p->GetCur())
		delete Root;
		delete p;
	}
	friend ostream& operator <<(ostream& out, Json& v) {
		if (v.GetCur() != nullptr)
			out << "\n{" << endl << *v.Root << "}\n" << endl;
		else out << "empty" << endl;
		return out;
	}
	void parse(string filename);
	friend istream& operator>>(istream& istr, Json& json)
	{
		//string temp;
		//int depth = 1;
		//string key = "";
		//string val = "";
		//int type; //1 - string, 2 - int, 3 - array
		//bool state = 1; // ìû ñ÷èòûâàåì ëèáî êëþ÷ ëèáî çíà÷åíèå
		//char cur = '0';
		//bool rb = 0;	//æäåò ëè ìàññèâ ïåðâîå çíà÷åíèå
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
		string* tokens;
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
		json.p->init(json.Root);

		return istr;
	}
	Value* process(string s, int depth) {
		string name = get_key(s);
		s = s.erase(s.find('"'), name.length() + 2);
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
	Value* GetCur() { if (p->GetCur() == nullptr) return Root; return p->GetCur(); }
	bool HasNext() { return p->HasNext(); }
	void GoNext() {
		if (!p->GetCur()) throw -1;
		if (GetCur()->getnext() != nullptr)p->GoNext();
		else throw - 1;
	}
	bool HasRight() { return p->HasRight(); }
	void GoRight() {
		if (!p->GetCur()) throw -1;
		if (GetCur()->getdata() != nullptr)
		{
			p->GoRight();
		}
		else { throw - 1; }
	}
	bool HasBack() { return p->HasBack(); }
	void GoBack() {
		if (!p->isempty()) p->GoBack();
		else throw - 1;
	}
	bool HasUp() { return p->HasUp(); }
	void GoUp() {
		if (!p->isempty()) p->GoUp();
		else throw - 1;
	}
	void AddNext(Value* _next) {
		if (GetCur() == nullptr)
		{
			Root = _next;
			p->init(Root);
			return;
		}
		p->AddNext(_next);
	}
	void AddRight(Value* _right) {
		if (GetCur() == nullptr)
		{
			Root = _right;
			p->init(Root);
			return;
		}
		p->AddRight(_right);
	}
	void AddRight(string key, int mode, string content) {
		switch (mode)
		{
		case 0:
		{
			ValueStr* _right = new ValueStr(key, GetCur()->GetDepth() + 1);
			_right->SetContent(content);
			p->AddRight(_right);
			break;
		}
		case 1:
		{
			ValueInt* _right = new ValueInt(key, GetCur()->GetDepth() + 1);
			_right->SetContent(content);
			p->AddRight(_right);
			break;
		}
		case 2:
		{
			ValueArr* _right = new ValueArr(key, GetCur()->GetDepth() + 1);
			p->AddRight(_right);
			break;
		}
		}
	}
	void SetContent(int _content) {
		p->SetContent(_content);
	}
	void SetContent(string _content) {
		p->SetContent(_content);
	}
	void delcur() {
		p->delcur();
	}

	string GetCurRow()
	{
		if (GetCur() == nullptr) return "empty";
		return GetCur()->GetLeafs();
	}

	Pointer* GetPointer() { return new Pointer(Root); }
};
