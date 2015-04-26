
#include "stdafx.h"
#include "LinkLockRevolute.h"
#include "StringUtils.h"

namespace cew
{
	LinkLockRevolute::LinkLockRevolute() : LinkLock(new chrono::ChLinkLockRevolute())
	{

	}

	LinkLockRevolute::LinkLockRevolute(const chrono::ChSharedPtr<chrono::ChLinkLockRevolute>& ptr) : LinkLock(ptr)
	{
	}

	LinkLockRevolute::~LinkLockRevolute()
	{

	}


}