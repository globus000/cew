
#pragma once

#include "stdafx.h"
#include "LinkMarkers.h"

namespace cew
{
	public ref class LinkMasked : public LinkMarkers
	{
	public:
		LinkMasked();
		LinkMasked(chrono::ChLinkMasked* ptr);
		LinkMasked(const chrono::ChSharedPtr<chrono::ChLinkMasked>& ptr);
		~LinkMasked();
	};
}