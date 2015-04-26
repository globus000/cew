
#include "stdafx.h"

#include "LinkLock.h"

namespace cew
{

	LinkLock::LinkLock() : LinkMasked( new chrono::ChLinkLock() )
	{
	}

	LinkLock::LinkLock(chrono::ChLinkLock* ptr) : LinkMasked(ptr)
	{
	}

	LinkLock::LinkLock(const chrono::ChSharedPtr<chrono::ChLinkLock>& ptr) : LinkMasked(ptr)
	{
	}

	LinkLock::~LinkLock()
	{
	}

}