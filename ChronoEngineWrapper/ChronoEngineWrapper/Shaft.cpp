
#include "stdafx.h"
#include "Shaft.h"

namespace cew
{
	Shaft::Shaft() : PhysicsItem( new chrono::ChShaft() )
	{
	}

	Shaft::Shaft(const chrono::ChSharedShaftPtr& ptr) : PhysicsItem(ptr)
	{
	}

	Shaft::Shaft(chrono::ChShaft* ptr) : PhysicsItem(ptr)
	{
	}

	Shaft::~Shaft()
	{
	}

	double Shaft::AppliedTorque::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetAppliedTorque();
	}

	void Shaft::AppliedTorque::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetAppliedTorque(value);
	}

	double Shaft::Inertia::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetInertia();
	}

	void Shaft::Inertia::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetInertia(value);
	}

	double Shaft::Pos::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetPos();
	}

	void Shaft::Pos::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetPos(value);
	}

	double Shaft::PosDt::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetPos_dt();
	}

	void Shaft::PosDt::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetPos_dt(value);
	}

	double Shaft::PosDtDt::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetPos_dtdt();
	}

	void Shaft::PosDtDt::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetPos_dtdt(value);
	}

	bool Shaft::ShaftFixed::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChShaft>()->GetShaftFixed();
	}

	void Shaft::ShaftFixed::set(bool value)
	{
		SharedPtr->DynamicCastTo<chrono::ChShaft>()->SetShaftFixed(value);
	}
}