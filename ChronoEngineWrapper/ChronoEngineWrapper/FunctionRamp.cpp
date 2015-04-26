
#include "stdafx.h"
#include "FunctionRamp.h"

namespace cew
{
	FunctionRamp::FunctionRamp() : Function( new chrono::ChFunction_Ramp() )
	{
	}

	FunctionRamp::FunctionRamp( const chrono::ChSharedPtr<chrono::ChFunction_Ramp>& ptr ) : Function(ptr)
	{
	}

	FunctionRamp::~FunctionRamp()
	{
	}

	double FunctionRamp::Ang::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Get_ang();
	}

	void FunctionRamp::Ang::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Set_ang(value);
	}

	double FunctionRamp::Y0::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Get_y0();
	}

	void FunctionRamp::Y0::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Set_y0(value);
	}

	double FunctionRamp::GetY(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Get_y(x);
	}

	double FunctionRamp::GetYdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Get_y_dx(x);
	}

	double FunctionRamp::GetYdxdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Ramp>()->Get_y_dxdx(x);
	}
}