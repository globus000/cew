
#pragma once

#include "stdafx.h"
#include "Object.h"
/*
#include "System.h"
*/
namespace cew
{
	public ref class PhysicsItem : public cew::Object
	{
	public:
		
		PhysicsItem(chrono::ChPhysicsItem* ptr);
		PhysicsItem(const chrono::ChSharedPtr<chrono::ChPhysicsItem>& ptr);
		~PhysicsItem();
		/*
		property ChronoSystem^ System
		{
			ChronoSystem^ get();
			void set(ChronoSystem^ system);

		}
		*/
	};
}