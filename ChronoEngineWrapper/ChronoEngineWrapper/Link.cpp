
#include "stdafx.h"
#include "Link.h"

namespace cew
{
	Link::Link(chrono::ChLink* ptr) : LinkBase(ptr)
	{
	}

	Link::Link(const chrono::ChSharedLinkPtr& ptr) : LinkBase(ptr)
	{
	}

	Link::~Link()
	{
	}


}