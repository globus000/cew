
#include "stdafx.h"
#include "ShaftsBody.h"

namespace cew
{
	BASIC_CONSTR_IMPL(ShaftsBody, PhysicsItem, chrono::ChShaftsBody)

	void ShaftsBody::Initialize(Shaft^ shaft, Body^ body, Vector^ mdir)
	{
		PTR_CAST(chrono::ChShaftsBody)->Initialize(
			VPTR_CAST(shaft, chrono::ChShaft),
			VPTR_CAST(body, chrono::ChBodyFrame),
			CH_VALUE(mdir)
			);
	}

	PROPERTY_IMPL_GET(ShaftsBody, TorqueReactionOnShaft, chrono::ChShaftsBody, TorqueReactionOnShaft, double)

	PROPERTY_IMPL_GETGC(ShaftsBody, TorqueReactionOnBody, chrono::ChShaftsBody, TorqueReactionOnBody, Vector)
}