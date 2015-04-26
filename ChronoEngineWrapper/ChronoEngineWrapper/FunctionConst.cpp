
#include "stdafx.h"
#include "FunctionConst.h"

namespace cew
{

	FunctionConst::FunctionConst() : Function( new chrono::ChFunction_Const() )
	{
	}

	FunctionConst::FunctionConst(double yconst)  : Function( new chrono::ChFunction_Const(yconst) )
	{
	}

	FunctionConst::FunctionConst(Function^ fun) : Function(fun->Ptr)
	{
	}

	FunctionConst::~FunctionConst()
	{
	}

	double FunctionConst::YConst::get()
	{
		return ((chrono::ChFunction_Const*)Ptr)->Get_yconst();
	}

	void FunctionConst::YConst::set(double value)
	{
		((chrono::ChFunction_Const*)Ptr)->Set_yconst(value);
	}

	double FunctionConst::GetY(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Const>()->Get_y(x);
	}

	double FunctionConst::GetYdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Const>()->Get_y_dx(x);
	}

	double FunctionConst::GetYdxdx(double x)
	{
		return SharedPtr->DynamicCastTo<chrono::ChFunction_Const>()->Get_y_dxdx(x);
	}
}