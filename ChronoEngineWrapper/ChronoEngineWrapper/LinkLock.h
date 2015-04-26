
#pragma once

#include "stdafx.h"
#include "LinkMasked.h"

namespace cew
{
	public ref class LinkLock : public LinkMasked
	{
	public:
		LinkLock();
		LinkLock(chrono::ChLinkLock* ptr);
		LinkLock(const chrono::ChSharedPtr<chrono::ChLinkLock>& ptr);
		~LinkLock();
	};
}