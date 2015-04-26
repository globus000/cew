
#pragma once

#include "stdafx.h"

namespace cew
{
	public ref class Force : public cew::Object
	{
	public:
		Force();
		Force(chrono::ChForce* force);
		Force(const chrono::ChSharedForcePtr& ptr);
		~Force();
	};
}