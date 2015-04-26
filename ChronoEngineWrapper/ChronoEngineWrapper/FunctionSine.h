

#include "stdafx.h"
#include "Function.h"

namespace cew
{
	public ref class FunctionSine : public Function
	{
	public:
		FunctionSine();
		~FunctionSine();

		property double Amp
		{
			double get();
			void set(double value);
		}

		property double Phase
		{
			double get();
			void set(double value);
		}

		property double Freq
		{
			double get();
			void set(double value);
		}

		property double W
		{
			double get();
			void set(double value);
		}

		virtual double GetY(double x);
		virtual double GetYdx(double x);
		virtual double GetYdxdx(double x);
	};
}