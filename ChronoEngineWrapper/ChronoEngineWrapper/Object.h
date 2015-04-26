
#pragma once

#include "stdafx.h"

namespace cew 
{
	public ref class Object : public RawPtr<chrono::ChObj>
	{
	public:
		Object(chrono::ChObj* ptr);
		Object(const chrono::ChSharedPtr<chrono::ChObj>& ptr);
		~Object();

		property System::String^ Name
		{
			void set(System::String^ value);
			System::String^ get();
		}

		virtual bool Equals(Object^ o) override;

	};
}