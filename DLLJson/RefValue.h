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
		ostream& operator<<(ostream& out)
		{
			out << value;
			return out;
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