#pragma once
#include "stdafx.h"
#include "Shaft.h"
#include "PhysicsItem.h"
#include "Shaft.h"


namespace cew
{
	DECL_CLASS_START(ShaftsPlanetary, PhysicsItem, chrono::ChShaftsPlanetary)

		virtual int Initialize(Shaft^ s1, Shaft^ s2, Shaft^ s3);

		void SetTransmitionRatios(double mr1, double mr2, double mr3);
		
		PROPERTY_DECL_GET(Shaft1, Shaft^)

		PROPERTY_DECL_GET(Shaft2, Shaft^)

		PROPERTY_DECL_GET(Shaft3, Shaft^)

		PROPERTY_DECL_GET(TransmissionRatioOrdinary, double)

		PROPERTY_DECL_GET(TransmissionR1, double)

		PROPERTY_DECL_GET(TransmissionR2, double)

		PROPERTY_DECL_GET(TransmissionR3, double)

		PROPERTY_DECL_GET(TorqueReactionOn1, double)

		PROPERTY_DECL_GET(TorqueReactionOn2, double)

		PROPERTY_DECL_GET(TorqueReactionOn3, double)

	DECL_CLASS_END

}