#pragma once

#include "stdafx.h"
#include "Marker.h"
#include "LinkLock.h"

namespace cew
{
	public ref class LinkLockRevolute : public LinkLock
	{
	public:
		LinkLockRevolute();
		LinkLockRevolute(const chrono::ChSharedPtr<chrono::ChLinkLockRevolute>& ptr);
		~LinkLockRevolute();

	};
}