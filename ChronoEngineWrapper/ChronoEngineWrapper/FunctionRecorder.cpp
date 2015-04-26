
#include "stdafx.h"
#include "FunctionRecorder.h"

namespace cew
{
	BASIC_CONSTR_IMPL(FunctionRecorder, Function, chrono::ChFunction_Recorder)

	double FunctionRecorder::GetY(double x)
	{
		return PTR_CAST(chrono::ChFunction_Recorder)->Get_y(x);
	}

	double FunctionRecorder::GetYdx(double x)
	{
		return PTR_CAST(chrono::ChFunction_Recorder)->Get_y_dx(x);
	}

	double FunctionRecorder::GetYdxdx(double x)
	{
		return PTR_CAST(chrono::ChFunction_Recorder)->Get_y_dxdx(x);
	}

	void FunctionRecorder::AddPoint(double x, double y)
	{
		PTR_CAST(chrono::ChFunction_Recorder)->AddPoint(x,y);
	}

	void FunctionRecorder::AddPoint(double x, double y, double w)
	{
		PTR_CAST(chrono::ChFunction_Recorder)->AddPoint(x,y,w);
	}

	void FunctionRecorder::AddPointClean(double x, double y, double w)
	{
		PTR_CAST(chrono::ChFunction_Recorder)->AddPointClean(x,y,w);
	}

	void FunctionRecorder::Reset()
	{
		PTR_CAST(chrono::ChFunction_Recorder)->Reset();
	}
}