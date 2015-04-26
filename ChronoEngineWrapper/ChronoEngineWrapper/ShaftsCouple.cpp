
#include "stdafx.h"
#include "ShaftsCouple.h"

namespace cew
{
	ShaftsCouple::ShaftsCouple() : PhysicsItem( new chrono::ChShaftsCouple() )
	{
	}

	ShaftsCouple::ShaftsCouple(chrono::ChShaftsCouple* ptr) : PhysicsItem( ptr )
	{
	}

	ShaftsCouple::ShaftsCouple(const chrono::ChSharedShaftsCouplePtr& ptr) : PhysicsItem( ptr )
	{
	}

	ShaftsCouple::~ShaftsCouple()
	{
	}

	bool ShaftsCouple::Initialize(Shaft^ s1, Shaft^ s2)
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaftsCouple>()->Initialize(
			s1->SharedPtr->DynamicCastTo<chrono::ChShaft>(),
			s2->SharedPtr->DynamicCastTo<chrono::ChShaft>()
			);
	}

	int ShaftsCouple::NumCoords::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaftsCouple>()->GetNumCoords();
	}

	Shaft^ ShaftsCouple::Shaft1::get()
	{
		return gcnew Shaft(SharedPtr->DynamicCastTo<chrono::ChShaftsCouple>()->GetShaft1());
	}

	Shaft^ ShaftsCouple::Shaft2::get()
	{
		return gcnew Shaft(SharedPtr->DynamicCastTo<chrono::ChShaftsCouple>()->GetShaft2());
	}

	PROPERTY_IMPL_GET(ShaftsCouple, RelativeRotation, chrono::ChShaftsCouple, RelativeRotation, double)

	PROPERTY_IMPL_GET(ShaftsCouple, RelativeRotationDt, chrono::ChShaftsCouple, RelativeRotation_dt, double)

	PROPERTY_IMPL_GET(ShaftsCouple, RelativeRotationDtDt, chrono::ChShaftsCouple, RelativeRotation_dtdt, double)
}