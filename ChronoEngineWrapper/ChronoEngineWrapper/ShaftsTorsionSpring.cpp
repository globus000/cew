
#include "stdafx.h"
#include "ShaftsTorsionSpring.h"

namespace cew
{
	BASIC_CONSTR_IMPL(ShaftsTorsionSpring, ShaftsTorqueBase, chrono::ChShaftsTorsionSpring)

	PROPERTY_IMPL(ShaftsTorsionSpring, TorsionalStiffness, chrono::ChShaftsTorsionSpring, TorsionalStiffness, double)

	PROPERTY_IMPL(ShaftsTorsionSpring, TorsionalDamping, chrono::ChShaftsTorsionSpring, TorsionalDamping, double)
	
}