
#include "stdafx.h"
#include "PhysicsItem.h"
#include "Object.h"

namespace cew
{

	PhysicsItem::PhysicsItem(chrono::ChPhysicsItem* ptr) : cew::Object(ptr)
	{
	}

	PhysicsItem::PhysicsItem(const chrono::ChSharedPtr<chrono::ChPhysicsItem>& ptr): cew::Object(ptr)
	{
	}

	PhysicsItem::~PhysicsItem()
	{
	}
	/*
	ChronoSystem^ PhysicsItem::System::get()
	{
		return gcnew ChronoSystem( ((chrono::ChPhysicsItem*)Ptr)->GetSystem() );
	}

	void PhysicsItem::System::set(ChronoSystem^ system)
	{
		((chrono::ChPhysicsItem*)Ptr)->SetSystem((chrono::ChSystem*)system->Ptr);
	}*/
}