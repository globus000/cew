#pragma once

#include "stdafx.h"
#include "Marker.h"
#include "Force.h"
#include "Vector.h"
#include "Link.h"
#include "PhysicsItem.h"

namespace cew
{
	public ref class Body : public PhysicsItem
	{
	public:
		Body();
		Body(chrono::ChBody* ptr);
		Body(const chrono::ChSharedBodyPtr& ptr);
		~Body();

		void AddMarker(Marker^ marker);
		void AddForce(Force^ force);
		void RemoveAllForces();
		void AccumulateTorque(Vector^ torque, int local);

		
		property bool BodyFixed
		{
			void set(bool value);
			bool get();
		}
		
		property Vector^ Position
		{
			Vector^ get();
			void set(Vector^ value);
		}
		
		
		

	};
}