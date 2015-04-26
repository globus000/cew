#pragma once
#include "stdafx.h"
#include "ShaftsCouple.h"

namespace cew
{
	public ref class ShaftsGear : public ShaftsCouple
	{
	public:

		ShaftsGear();
		~ShaftsGear();

		virtual bool Initialize(Shaft^ s1, Shaft^ s2) override;

		property double TransmissionRatio
		{
			double get();
			void set(double value);
		}

		PROPERTY_DECL_GET(TorqueReactionOn1, double)

		PROPERTY_DECL_GET(TorqueReactionOn2, double)
	};
}