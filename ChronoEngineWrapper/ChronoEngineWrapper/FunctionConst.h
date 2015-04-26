
#pragma once

#include "stdafx.h"
#include "Function.h"

namespace cew
{
	public ref class FunctionConst : public Function
	{

	public:
		FunctionConst();
		FunctionConst(Function^ fun);
		FunctionConst(double yconst);
		~FunctionConst();

		property double YConst
		{
			void set(double value);
			double get();
		}

		virtual double GetY(double x);
		virtual double GetYdx(double x);
		virtual double GetYdxdx(double x);
	};
}