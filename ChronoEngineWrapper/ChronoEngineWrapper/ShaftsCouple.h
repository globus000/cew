#pragma once

#include "stdafx.h"
#include "PhysicsItem.h"
#include "Shaft.h"

namespace cew
{
	public ref class ShaftsCouple : public PhysicsItem
	{
	public:
		ShaftsCouple();
		ShaftsCouple(chrono::ChShaftsCouple* ptr);
		ShaftsCouple(const chrono::ChSharedShaftsCouplePtr& ptr);
		~ShaftsCouple();

		virtual bool Initialize(Shaft^ s1, Shaft^ s2);

		virtual property int NumCoords
		{
			int get();
		}

		property Shaft^ Shaft1
		{
			Shaft^ get();
		}

		property Shaft^ Shaft2
		{
			Shaft^ get();
		}

		PROPERTY_DECL_GET(RelativeRotation, double)

		PROPERTY_DECL_GET(RelativeRotationDt, double)

		PROPERTY_DECL_GET(RelativeRotationDtDt, double)
	};
}