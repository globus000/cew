
#include "stdafx.h"
#include "Body.h"
#include "StringUtils.h"

namespace cew
{
	
	Body::Body() : cew::PhysicsItem(new chrono::ChBody())
	{
	}
	
	
	Body::Body(chrono::ChBody* ptr) : cew::PhysicsItem(ptr)
	{
	}

	Body::Body(const chrono::ChSharedBodyPtr& ptr) : cew::PhysicsItem(ptr)
	{
	}
	
	
	Body::~Body()
	{
	}
	
	
	void Body::AddMarker(Marker^ marker)
	{
		((chrono::ChBody*)Ptr)->AddMarker( chrono::ChSharedMarkerPtr( (chrono::ChMarker*)(marker->Ptr)) );
	}
	
	void Body::AddForce(Force^ force)
	{
		((chrono::ChBody*)Ptr)->AddForce( chrono::ChSharedForcePtr( (chrono::ChForce*)(force->Ptr)) );
	}

	void Body::AccumulateTorque(Vector^ torque, int local)
	{
		PTR_CAST(chrono::ChBody)->Accumulate_torque(*(torque->Ptr), local);
	}

	
	
	void Body::RemoveAllForces()
	{
		((chrono::ChBody*)Ptr)->RemoveAllForces();
	}

	

	void Body::BodyFixed::set(bool fixed)
	{
		((chrono::ChBody*)Ptr)->SetBodyFixed(fixed);
	}

	bool Body::BodyFixed::get()
	{
		return ((chrono::ChBody*)Ptr)->GetBodyFixed();
	}

	Vector^ Body::Position::get()
	{
		return gcnew Vector(((chrono::ChBody*)Ptr)->GetPos());
	}

	void Body::Position::set(Vector^ value)
	{
		((chrono::ChBody*)Ptr)->SetPos( *(value->Ptr) );
	}
	

}