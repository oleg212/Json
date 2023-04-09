#pragma once

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
		//rfValue^ GetCur() { return gcnew rfValue(js->GetCur()); }
		void GoNext() { js->GoNext(); }
		void GoRight() { js->GoRight(); }
		void GoBack() { js->GoBack(); }
		void GoUp() { js->GoUp(); }
		void Addnext(rfValue^ next) { js->AddNext(next->GetCore()); }
		void AddRight(rfValue^ right) { js->AddRight(right->GetCore()); }
		void SetContent(int content) { js->SetContent(content); }
		void SetContent(String^ content) 
		{ 
			string _content = msclr::interop::marshal_as<std::string>(content);
			js->SetContent(_content); 
		}
	};
}