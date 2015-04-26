
#pragma once
#include "stdafx.h"
#include "PhysicsItem.h"
#include "Shaft.h"
#include "Body.h"
#include "Vector.h"

namespace cew
{
	DECL_CLASS_START(ShaftsBody, PhysicsItem, chrono::ChShaftsBody)

		void Initialize(Shaft^ shaft, Body^ body, Vector^ mdir);

		PROPERTY_DECL_GET(TorqueReactionOnShaft, double)

		PROPERTY_DECL_GET(TorqueReactionOnBody, Vector^)

	DECL_CLASS_END
}