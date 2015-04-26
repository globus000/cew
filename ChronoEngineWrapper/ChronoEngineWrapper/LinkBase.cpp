
#include "stdafx.h"
#include "LinkBase.h"

namespace cew
{
	LinkBase::LinkBase(chrono::ChLinkBase* ptr) : cew::PhysicsItem(ptr) 
	{
	}

	LinkBase::LinkBase(const chrono::ChSharedPtr<chrono::ChLinkBase>& ptr) : cew::PhysicsItem(ptr)
	{
	}

	LinkBase::~LinkBase()
	{
	}
}