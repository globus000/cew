
#pragma once

#include "stdafx.h"
#include "Function.h"

namespace cew
{
	public ref class FunctionRamp : public Function
	{
	public:
		FunctionRamp();
		FunctionRamp(const chrono::ChSharedPtr<chrono::ChFunction_Ramp>& fun);
		~FunctionRamp();

		property double Ang
		{
			double get();
			void set(double value);
		}

		property double Y0
		{
			double get();
			void set(double value);
		}

		virtual double GetY(double x);
		virtual double GetYdx(double x);
		virtual double GetYdxdx(double x);


	};
}