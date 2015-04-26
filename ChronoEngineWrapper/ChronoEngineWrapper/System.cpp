
#include "stdafx.h"
#include "System.h"

namespace cew
{

	ChronoSystem::ChronoSystem(unsigned int max_objects, double scene_size, bool init_sys) : cew::Object(new chrono::ChSystem(max_objects, scene_size, init_sys))
	{

	}

	ChronoSystem::ChronoSystem(chrono::ChSystem* ptr) : cew::Object(ptr)
	{
	}


	ChronoSystem::~ChronoSystem()
	{

	}

	void ChronoSystem::Add(PhysicsItem^ item)
	{
		PTR_CAST(chrono::ChSystem)->Add( VPTR_CAST(item, chrono::ChPhysicsItem) );
	}

	void ChronoSystem::AddBody(Body^ newbody)
	{
		((chrono::ChSystem*)Ptr)->AddBody( chrono::ChSharedPtr<chrono::ChBody>((chrono::ChBody*)(newbody->Ptr)));
	}

	void ChronoSystem::RemoveBody(Body^ body)
	{
		((chrono::ChSystem*)Ptr)->RemoveBody(chrono::ChSharedPtr<chrono::ChBody>((chrono::ChBody*)(body->Ptr)));
	}

	void ChronoSystem::AddLink(Link^ force)
	{
		((chrono::ChSystem*)Ptr)->AddLink( chrono::ChSharedLinkPtr( (chrono::ChLink*)(force->Ptr)) );
	}

	void ChronoSystem::DoFrameDynamics(double time)
	{
		((chrono::ChSystem*)Ptr)->DoFrameDynamics(time);
	}
}