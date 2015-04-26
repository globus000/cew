
#pragma once

#include "stdafx.h"
#include "PhysicsItem.h"

namespace cew
{
	public ref class LinkBase : public PhysicsItem
	{
	public:
		
		LinkBase(chrono::ChLinkBase* ptr);
		LinkBase(const chrono::ChSharedPtr<chrono::ChLinkBase>& ptr);
		~LinkBase();
	};
}