
#include "stdafx.h"
#include "ShaftsPlanetary.h"
#include "Shaft.h"

namespace cew
{
	BASIC_CONSTR_IMPL(ShaftsPlanetary, PhysicsItem, chrono::ChShaftsPlanetary)

	int ShaftsPlanetary::Initialize(Shaft^ s1,	Shaft^ s2, Shaft^ s3)
	{
		return PTR_CAST(chrono::ChShaftsPlanetary)->Initialize(
			VPTR_CAST(s1, chrono::ChShaft),
			VPTR_CAST(s2, chrono::ChShaft),
			VPTR_CAST(s3, chrono::ChShaft)
			);

	}

	void ShaftsPlanetary::SetTransmitionRatios(double mr1, double mr2, double mr3)
	{
		PTR_CAST(chrono::ChShaftsPlanetary)->SetTransmissionRatios(mr1,mr2,mr3);
	}

	PROPERTY_IMPL_GETGC(ShaftsPlanetary, Shaft1, chrono::ChShaftsPlanetary, Shaft1, Shaft)

	PROPERTY_IMPL_GETGC(ShaftsPlanetary, Shaft2, chrono::ChShaftsPlanetary, Shaft2, Shaft)

	PROPERTY_IMPL_GETGC(ShaftsPlanetary, Shaft3, chrono::ChShaftsPlanetary, Shaft3, Shaft)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TransmissionRatioOrdinary, chrono::ChShaftsPlanetary, TransmissionRatioOrdinary, double)
	
	PROPERTY_IMPL_GET(ShaftsPlanetary, TransmissionR1, chrono::ChShaftsPlanetary, TransmissionR1, double)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TransmissionR2, chrono::ChShaftsPlanetary, TransmissionR1, double)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TransmissionR3, chrono::ChShaftsPlanetary, TransmissionR1, double)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TorqueReactionOn1, chrono::ChShaftsPlanetary, TorqueReactionOn1, double)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TorqueReactionOn2, chrono::ChShaftsPlanetary, TorqueReactionOn2, double)

	PROPERTY_IMPL_GET(ShaftsPlanetary, TorqueReactionOn3, chrono::ChShaftsPlanetary, TorqueReactionOn3, double)

}