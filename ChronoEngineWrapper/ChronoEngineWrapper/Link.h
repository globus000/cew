
#pragma once

#include "stdafx.h"
#include "LinkBase.h"

namespace cew
{
	
	public ref class Link : public LinkBase
	{
	public:
		
		Link(chrono::ChLink* ptr);
		Link(const chrono::ChSharedLinkPtr& ptr);
		~Link();
		
	};

}