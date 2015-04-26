
#pragma once
#include "stdafx.h"
#include "ShaftsTorqueBase.h"

namespace cew
{
	DECL_CLASS_START(ShaftsTorsionSpring, ShaftsTorqueBase, chrono::ChShaftsTorsionSpring)

		PROPERTY_DECL(TorsionalStiffness, double)

		PROPERTY_DECL(TorsionalDamping, double)

	DECL_CLASS_END
}