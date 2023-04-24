#pragma once

#include <msclr\marshal_cppstd.h>
#include "Value.h"

using namespace System;
using namespace System::IO;

namespace Json_net
{
	public ref class rfValue
	{
	protected:
		Value* value;
	public:
		//rfValue(String^ key, int depth)
		//{
		//	string _key = msclr::interop::marshal_as<std::string>(key);
		//	value = new Value(_key, depth);
		//}
		//~rfValue()
		//{
		//	delete value;
		//}

		String^ tab(int d) {
			string res;
			for (int i = 0; i < d; i++) {
				res += "   ";
			}
			return gcnew String(res.c_str());
		}

		Value* GetCore() { return value; }
		void SetCore(Value* core) { value = core; }

		String^ GetType() { return gcnew String(value->GetType().c_str()); }
		String^ GetContent() { return gcnew String(value->GetContent().c_str()); }
		//void SetContent(String^ s)
		//{
		//	string content = msclr::interop::marshal_as<std::string>(s);
		//	value->SetContent(content);
		//}
		String^ To_String()
		{
			return gcnew String(value->ToString().c_str());
		}
		int GetDepth() { return value->GetDepth(); }
		String^ GetKey() { return gcnew String(value->GetKey().c_str()); }

		void setnext(rfValue^ _next) { value->setnext(_next->value->getnext()); }
		void setdata(rfValue^ _data) { value->setdata(_data->value->getdata()); }
		Value* getnext() { return value->getnext(); }
		Value* getdata() { return value->getdata(); }
		//rfValue^ getnext() 
		//{ 
		//	String^ key = gcnew String(value->getnext()->GetKey().c_str());
		//	if (value->getnext()->GetType() == "string ")
		//	{
		//		rfValueStr^ t = gcnew rfValueStr(key, value->GetDepth());
		//		t->SetCore(value->getnext());
		//		return t;
		//	}
		//	else 			if (value->getnext()->GetType() == "int ")
		//	{
		//		rfValueInt^ t = gcnew rfValueInt(key, value->GetDepth());
		//		t->SetCore(value->getnext());
		//		return t;
		//	}
		//	else 			if (value->getnext()->GetType() == "array ")
		//	{
		//		rfValueArr^ t = gcnew rfValueArr(key, value->GetDepth());
		//		t->SetCore(value->getnext());
		//		return t;
		//	}
		//}
		//rfValue^ getdata()
		//{
		//	String^ key = gcnew String(value->getdata()->GetKey().c_str());
		//	if (value->getdata()->GetType() == "string ")
		//	{
		//		rfValueStr^ t = gcnew rfValueStr(key, value->GetDepth());
		//		t->SetCore(value->getdata());
		//		return t;
		//	}
		//	else 			if (value->getdata()->GetType() == "int ")
		//	{
		//		rfValueInt^ t = gcnew rfValueInt(key, value->GetDepth());
		//		t->SetCore(value->getdata());
		//		return t;
		//	}
		//	else 			if (value->getdata()->GetType() == "array ")
		//	{
		//		rfValueArr^ t = gcnew rfValueArr(key, value->GetDepth());
		//		t->SetCore(value->getdata());
		//		return t;
		//	}
		//}
		ostream& operator<<(ostream& out)
		{
			out << value;
			return out;
		}
		bool equals(rfValue^ v)
		{
			return GetCore() == v->GetCore();
		}
	};

	public ref class rfValueStr : public rfValue
	{
	public:
		rfValueStr(String^ key, int depth)
		{
			string _key = msclr::interop::marshal_as<std::string>(key);
			value = new ValueStr(_key, depth);
		}
		void SetContent(String^ s)
		{
			string content = msclr::interop::marshal_as<std::string>(s);
			value->SetContent(content);
		}
	};

	public ref class rfValueInt : public rfValue
	{
	public :
		rfValueInt(String^ key, int depth)
		{
			string _key = msclr::interop::marshal_as<std::string>(key);
			value = new ValueInt(_key, depth);
		}
		void SetContent(String^ s)
		{
			string content = msclr::interop::marshal_as<std::string>(s);
			value->SetContent(content);
		}
	};

	public ref class rfValueArr : public rfValue
	{
	public:
		rfValueArr(String^ key, int depth)
		{
			string _key = msclr::interop::marshal_as<std::string>(key);
			value = new ValueArr(_key, depth);
		}
		void SetContent(rfValue^ _data)
		{
			setdata(_data);
		}
	};
}