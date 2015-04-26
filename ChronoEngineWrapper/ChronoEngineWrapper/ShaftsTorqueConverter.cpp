
#include "stdafx.h"
#include "ShaftsTorqueConverter.h"

namespace cew
{
	BASIC_CONSTR_IMPL(ShaftsTorqueConverter, PhysicsItem, chrono::ChShaftsTorqueConverter)

	void ShaftsTorqueConverter::Initialize(Shaft^ s1, Shaft^ s2, Shaft^ stator)
	{
		PTR_CAST(chrono::ChShaftsTorqueConverter)->Initialize(
			VPTR_CAST(s1, chrono::ChShaft),
			VPTR_CAST(s2, chrono::ChShaft),
			VPTR_CAST(stator, chrono::ChShaft)
			);
	}

	PROPERTY_IMPL_GET(ShaftsTorqueConverter, SpeedRatio, chrono::ChShaftsTorqueConverter, SpeedRatio, double)

	PROPERTY_IMPL_GET(ShaftsTorqueConverter, TorqueReactionOnInput, chrono::ChShaftsTorqueConverter, TorqueReactionOnInput, double)

	PROPERTY_IMPL_GET(ShaftsTorqueConverter, TorqueReactionOnOutput, chrono::ChShaftsTorqueConverter, TorqueReactionOnOutput, double)

	PROPERTY_IMPL_GET(ShaftsTorqueConverter, TorqueReactionOnStator, chrono::ChShaftsTorqueConverter, TorqueReactionOnStator, double)

	PROPERTY_IMPLGC(ShaftsTorqueConverter, CurveCapacityFactor, chrono::ChShaftsTorqueConverter, CurveCapacityFactor, Function)

	PROPERTY_IMPLGC(ShaftsTorqueConverter, CurveTorqueRatio, chrono::ChShaftsTorqueConverter, CurveTorqueRatio, Function)
}