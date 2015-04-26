
#include "stdafx.h"
#include "LcpVariables.h"

namespace cew
{
	LcpVariables::LcpVariables(chrono::ChLcpVariables* ptr)
	{
		_ptr = ptr;
		
	}


	LcpVariables::~LcpVariables()
	{
	}
}