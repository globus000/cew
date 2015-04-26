#pragma once

#include "stdafx.h"

namespace cew
{

	public ref class Function : RawPtr<chrono::ChFunction>
	{
	public:
		
		Function(const chrono::ChSharedPtr<chrono::ChFunction>& ptr);
		Function(chrono::ChFunction* ptr);
		~Function();


	};
}

