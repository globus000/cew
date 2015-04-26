
#pragma once

#include "stdafx.h"
#include "Link.h"
#include "Marker.h"
#include "Body.h"
#include "CoordSys.h"

namespace cew
{

	public ref class LinkMarkers : public Link
	{
	public:

	
		LinkMarkers(chrono::ChLinkMarkers* ptr);
		LinkMarkers(const chrono::ChSharedPtr<chrono::ChLinkMarkers>& ptr);
		~LinkMarkers();

		void Initialize(Marker^ m1, Marker^ m2);
		void Initialize(Body^ b1, Body^ b2, CoordSys^ mpos);

		property Marker^ Marker1
		{
			Marker^ get();
	
		}

		property Marker^ Marker2
		{
			Marker^ get();

		}
	};
}