
#pragma once
#include "stdafx.h"
#include "PhysicsItem.h"
#include "Shaft.h"
#include "Function.h"

namespace cew
{
	DECL_CLASS_START(ShaftsTorqueConverter, PhysicsItem, chrono::ChShaftsTorqueConverter)

		void Initialize(Shaft^ s1, Shaft^ s2, Shaft^ stator);

		PROPERTY_DECL(CurveCapacityFactor, Function^)

		PROPERTY_DECL(CurveTorqueRatio, Function^)

		PROPERTY_DECL_GET(TorqueReactionOnInput, double)

		PROPERTY_DECL_GET(TorqueReactionOnOutput, double)

		PROPERTY_DECL_GET(TorqueReactionOnStator, double)

		PROPERTY_DECL_GET(SpeedRatio, double)

	DECL_CLASS_END
}