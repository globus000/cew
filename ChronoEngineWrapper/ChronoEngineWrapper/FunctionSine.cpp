
#include "stdafx.h"
#include "Functionsine.h"

namespace cew
{
	FunctionSine::FunctionSine() : Function( new chrono::ChFunction_Sine() )
	{
	}

	FunctionSine::~FunctionSine()
	{
	}

	double FunctionSine::Amp::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_amp();
	}

	void FunctionSine::Amp::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Set_amp(value);
	}

	double FunctionSine::Freq::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_freq();
	}

	void FunctionSine::Freq::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Set_freq(value);
	}

	double FunctionSine::W::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_w();
	}

	void FunctionSine::W::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Set_w(value);
	}

	double FunctionSine::Phase::get()
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_phase();
	}

	void FunctionSine::Phase::set(double value)
	{
		SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Set_phase(value);
	}

	double FunctionSine::GetY(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_y(x);
	}	

	double FunctionSine::GetYdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_y_dx(x);
	}

	double FunctionSine::GetYdxdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Sine>()->Get_y_dxdx(x);
	}
}