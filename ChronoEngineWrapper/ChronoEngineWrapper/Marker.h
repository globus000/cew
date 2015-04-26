
#pragma once

#include "stdafx.h"
#include "CoordSys.h"

namespace cew
{
	public ref class Marker : public cew::Object
	{
	public:
		Marker();
		Marker(chrono::ChMarker* ptr);
		Marker(const chrono::ChSharedMarkerPtr& ptr);
		~Marker();

		void ImposeAbsCoords(CoordSys^ coords);

		property CoordSys^ AbsCoord
		{
			CoordSys^ get();
		}
			
	};
}