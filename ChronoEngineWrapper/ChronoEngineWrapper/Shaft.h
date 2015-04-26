#pragma once
#include "stdafx.h"
#include "PhysicsItem.h"

namespace cew
{
	public ref class Shaft : public PhysicsItem
	{
	public:
		Shaft();
		Shaft(chrono::ChShaft* ptr);
		Shaft(const chrono::ChSharedShaftPtr& ptr);
		~Shaft();

		property double Inertia 
		{
			double get();
			void set(double value);
		}

		property double AppliedTorque 
		{
			double get();
			void set(double value);
		}

		property bool ShaftFixed 
		{
			bool get();
			void set(bool value);
		}

		property double Pos 
		{
			double get();
			void set(double value);
		}

		property double PosDt 
		{
			double get();
			void set(double value);
		}

		property double PosDtDt
		{
			double get();
			void set(double value);
		}


	};
}