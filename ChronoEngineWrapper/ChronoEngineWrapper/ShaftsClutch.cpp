
#include "stdafx.h"
#include "ShaftsClutch.h"

namespace cew
{
	ShaftsClutch::ShaftsClutch() : ShaftsCouple( new chrono::ChShaftsClutch() )
	{
	}

	ShaftsClutch::ShaftsClutch(chrono::ChShaftsClutch* ptr) : ShaftsCouple(ptr )
	{
	}

	ShaftsClutch::ShaftsClutch(const chrono::ChSharedShaftsClutchPtr& ptr) : ShaftsCouple(ptr)
	{
	}

	ShaftsClutch::~ShaftsClutch()
	{
	}

	void ShaftsClutch::SetTorqueLimit(double ml, double mf)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaftsClutch>()->SetTorqueLimit(ml, mf);
	}

	void ShaftsClutch::SetTorqueLimit(double ml)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaftsClutch>()->SetTorqueLimit(ml);
	}


	PROPERTY_IMPL(ShaftsClutch, Modulation, chrono::ChShaftsClutch, Modulation, double)

	PROPERTY_IMPL(ShaftsClutch, TorqueLimit, chrono::ChShaftsClutch, TorqueLimit, double)

	PROPERTY_IMPL_GET(ShaftsClutch, TorqueLimitF, chrono::ChShaftsClutch, TorqueLimitF, double)

	PROPERTY_IMPL_GET(ShaftsClutch, TorqueLimitB, chrono::ChShaftsClutch, TorqueLimitB, double)

	PROPERTY_IMPL_GET(ShaftsClutch, Slippage, chrono::ChShaftsClutch, Slippage, double)

	PROPERTY_IMPL_GET(ShaftsClutch, SlippageDt, chrono::ChShaftsClutch, Slippage_dt, double)

	PROPERTY_IMPL_GET(ShaftsClutch, SlippageDtDt, chrono::ChShaftsClutch, Slippage_dtdt, double)

	PROPERTY_IMPL_GET(ShaftsClutch, TorqueReactionOn1, chrono::ChShaftsClutch, TorqueReactionOn1, double)

	PROPERTY_IMPL_GET(ShaftsClutch, TorqueReactionOn2, chrono::ChShaftsClutch, TorqueReactionOn2, double)
}