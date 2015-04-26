
#include "stdafx.h"
#include "Force.h"

namespace cew
{
	Force::Force() : cew::Object( new chrono::ChForce())
	{
	}

	Force::Force(chrono::ChForce* force) : cew::Object(force)
	{
	}

	Force::Force(const chrono::ChSharedForcePtr& ptr) : cew::Object(ptr)
	{
	}

	Force::~Force()
	{
	}
}