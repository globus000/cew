
#include "stdafx.h"
#include "ShaftsGear.h"

namespace cew
{
	ShaftsGear::ShaftsGear() : ShaftsCouple( new chrono::ChShaftsGear() )
	{
	}

	ShaftsGear::~ShaftsGear()
	{
	}

	bool ShaftsGear::Initialize(Shaft^ s1, Shaft^ s2)
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaftsGear>()->Initialize(
			s1->SharedPtr->DynamicCastTo<chrono::ChShaft>(),
			s2->SharedPtr->DynamicCastTo<chrono::ChShaft>()
			);
	}

	double ShaftsGear::TransmissionRatio::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaftsGear>()->GetTransmissionRatio();
	}

	void ShaftsGear::TransmissionRatio::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaftsGear>()->SetTransmissionRatio(value);
	}

	PROPERTY_IMPL_GET(ShaftsGear, TorqueReactionOn1, chrono::ChShaftsGear, TorqueReactionOn1, double)

	PROPERTY_IMPL_GET(ShaftsGear, TorqueReactionOn2, chrono::ChShaftsGear, TorqueReactionOn2, double)
}