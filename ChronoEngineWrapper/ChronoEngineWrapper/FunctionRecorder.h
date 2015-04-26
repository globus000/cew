
#pragma once
#include "Function.h"

namespace cew
{
	DECL_CLASS_START(FunctionRecorder, Function, chrono::ChFunction_Recorder)

		void AddPoint(double x, double y);
		void AddPoint(double x, double y, double w);
		void AddPointClean(double x, double y, double dx_clean);
		void Reset();
		double GetY      (double x) ;
		double GetYdx   (double x) ;
		double GetYdxdx (double x) ;
	

	

	DECL_CLASS_END
}