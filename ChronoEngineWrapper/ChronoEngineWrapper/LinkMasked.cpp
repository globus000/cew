
#include "stdafx.h"

#include "LinkMasked.h"

namespace cew
{
	LinkMasked::LinkMasked() : LinkMarkers(new chrono::ChLinkMasked())
	{
	}

	LinkMasked::LinkMasked(chrono::ChLinkMasked* ptr) : LinkMarkers(ptr)
	{
	}

	LinkMasked::LinkMasked(const chrono::ChSharedPtr<chrono::ChLinkMasked>& ptr) : LinkMarkers(ptr)
	{
	}

	LinkMasked::~LinkMasked()
	{
	}
}