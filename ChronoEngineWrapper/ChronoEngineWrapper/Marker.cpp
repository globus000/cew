
#include "stdafx.h"
#include "Marker.h"
#include "StringUtils.h"

namespace cew
{
	Marker::Marker() : cew::Object(new chrono::ChMarker())
	{
	}

	Marker::Marker(chrono::ChMarker* ptr) : cew::Object(ptr)
	{
	}

	Marker::Marker(const chrono::ChSharedMarkerPtr& ptr) : cew::Object(ptr)
	{
	}

	Marker::~Marker()
	{
	}


	void Marker::ImposeAbsCoords(CoordSys^ coords)
	{
		((chrono::ChMarker*)Ptr)->Impose_Abs_Coord(*(coords->Ptr));
	}

	CoordSys^ Marker::AbsCoord::get()
	{
		return gcnew CoordSys( ((chrono::ChMarker*)Ptr)->GetAbsCoord() );
	}
	
}