#pragma once
#include "stdafx.h"


namespace cew
{
	public ref class LcpVariables
	{
	private:
		chrono::ChLcpVariables* _ptr;

	public:
		LcpVariables(chrono::ChLcpVariables* ptr);
		~LcpVariables();


	};

}