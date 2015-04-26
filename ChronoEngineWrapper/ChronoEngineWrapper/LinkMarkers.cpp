
#include "stdafx.h"
#include "LinkMarkers.h"

namespace cew
{
	LinkMarkers::LinkMarkers(chrono::ChLinkMarkers* ptr) : Link(ptr)
	{
	}

	LinkMarkers::LinkMarkers(const chrono::ChSharedPtr<chrono::ChLinkMarkers>& ptr) : Link(ptr)
	{
	}

	LinkMarkers::~LinkMarkers()
	{
	}

	void LinkMarkers::Initialize(Marker^ m1, Marker^ m2)
	{
		((chrono::ChLinkMarkers*)Ptr)->Initialize(	m1->SharedPtr->DynamicCastTo<chrono::ChMarker>() , 
													m2->SharedPtr->DynamicCastTo<chrono::ChMarker>()  );
	}

	void LinkMarkers::Initialize(Body^ b1, Body^ b2, CoordSys^ mpos)
	{
	
		((chrono::ChLinkMarkers*)Ptr)->Initialize( 
			b1->SharedPtr->DynamicCastTo<chrono::ChBody>(), 
			b2->SharedPtr->DynamicCastTo<chrono::ChBody>(), 
			*(mpos->Ptr));
	}

	Marker^ LinkMarkers::Marker1::get()
	{
		return gcnew Marker(((chrono::ChLinkMarkers*)Ptr)->GetMarker1());
	}

	Marker^ LinkMarkers::Marker2::get()
	{
		return gcnew Marker(((chrono::ChLinkMarkers*)Ptr)->GetMarker2());
	}
	
}