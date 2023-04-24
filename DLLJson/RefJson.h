#pragma once

#include <fstream>
#include <sstream>
#include "RefValue.h"
#include "Json.h"

namespace Json_net
{


	public ref class rfJson
	{
		Json* js;
	public:
		rfJson() { js = new Json(); }
		~rfJson() { delete js; }
		rfValue^ GetCur() 
		{ 
				rfValue^ t = gcnew rfValue();
				t->SetCore(js->GetCur());
				return t;
		}
		bool empty() { return js->GetCur() == nullptr; }
		bool HasNext() { return js->HasNext(); }
		bool HasRight() { return js->HasRight(); }
		bool HasBack() { return js->HasBack(); }
		bool HasUp() { return js->HasUp(); }
		void GoNext() { js->GoNext(); }
		void GoRight() { js->GoRight(); }
		void GoBack() { js->GoBack(); }
		void GoUp() { js->GoUp(); }
		void Addnext(rfValue^ next) { js->AddNext(next->GetCore()); }
		void AddRight(rfValue^ right) { js->AddRight(right->GetCore()); }
		//void Add_Right(String^ key, int mode, String^ content)
		//{
		//	string _key = msclr::interop::marshal_as<std::string>(key);
		//	string _content = msclr::interop::marshal_as<std::string>(content);
		//	js->AddRight(_key, mode, _content);
		//}
		//void AddLeft(rfValue^ right) { js->AddRight(right->GetCore()); }
		void delcur() { js->delcur(); }
		void SetContent(int content) { js->SetContent(content); }
		void SetContent(String^ content) 
		{ 
			string _content = msclr::interop::marshal_as<std::string>(content);
			js->SetContent(_content); 
		}

		ostream& operator <<(ostream& out)
		{
			out << js;
			return out;
		}

		String^ WriteAsString()
		{
			std::stringstream ss;
			ss << *js;
			string s = ss.str();
			return gcnew String(s.c_str());
		}

		String^ WriteCurRow()
		{
			string s = js->GetCurRow();
			return gcnew String(s.c_str());
		}
		
		void ReadFromFile(String^ path)
		{
			string spath = msclr::interop::marshal_as<std::string>(path);
			std::ifstream file(spath);
			file >> *js;
			file.close();
		}

		Pointer* GetPointer() { return js->GetPointer(); }
	};

	public ref class rfPointer
	{
	public:
		Pointer* p;
		void SetPointer(rfJson^ json) { p = json->GetPointer(); }
		rfValue^ GetCur()
		{
			if (p->GetCur() == nullptr) return nullptr;
			rfValue^ t = gcnew rfValue();
			t->SetCore(p->GetCur());
			return t;
		}
		bool HasNext() { return p->HasNext(); }
		bool HasRight() { return p->HasRight(); }
		bool HasBack() { return p->HasBack(); }
		bool HasUp() { return p->HasUp(); }
		void GoNext() {
			if (!p->GetCur()) throw - 1;
			if (p->GetCur()->getnext() != nullptr)
				p->GoNext();
			else throw - 1;
		}
		void GoRight() {
			if (!p->GetCur()) throw - 1;
			if (p->GetCur()->getdata() != nullptr)
				p->GoRight();
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
	};
}