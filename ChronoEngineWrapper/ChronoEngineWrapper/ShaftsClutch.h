#pragma once
#include "stdafx.h"
#include "ShaftsCouple.h"

namespace cew
{
	public ref class ShaftsClutch : public ShaftsCouple
	{
	public:
		ShaftsClutch();
		ShaftsClutch(const chrono::ChSharedShaftsClutchPtr& ptr);
		ShaftsClutch(chrono::ChShaftsClutch* ptr);
		~ShaftsClutch();

		PROPERTY_DECL(TorqueLimit, double)

		PROPERTY_DECL(Modulation, double)

		PROPERTY_DECL_GET(TorqueLimitB, double)

		PROPERTY_DECL_GET(TorqueLimitF, double)

		PROPERTY_DECL_GET(Slippage, double)

		PROPERTY_DECL_GET(SlippageDt, double)

		PROPERTY_DECL_GET(SlippageDtDt, double)

		PROPERTY_DECL_GET(TorqueReactionOn1, double)

		PROPERTY_DECL_GET(TorqueReactionOn2, double)

		void SetTorqueLimit(double ml, double mu);

		void SetTorqueLimit(double ml);

	};

}