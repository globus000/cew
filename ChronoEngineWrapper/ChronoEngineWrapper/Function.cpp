
#include "stdafx.h"
#include "Function.h"

namespace cew
{
	Function::Function(const chrono::ChSharedPtr<chrono::ChFunction>& ptr) : RawPtr(ptr)
	{
	}

	Function::Function(chrono::ChFunction* ptr) : RawPtr( ptr )
	{
	}

	Function::~Function()
	{
	}
		
}