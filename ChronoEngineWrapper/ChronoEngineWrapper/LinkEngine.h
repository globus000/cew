
#pragma once

#include "stdafx.h"
#include "LinkLock.h"
#include "Function.h"

namespace cew
{
	public ref class LinkEngine : public LinkLock
	{
	public:
       enum class EEngMode {
			ENG_MODE_ROTATION = 0,
			ENG_MODE_SPEED,
			ENG_MODE_TORQUE,
			ENG_MODE_KEY_ROTATION,
			ENG_MODE_KEY_POLAR,
			ENG_MODE_TO_POWERTRAIN_SHAFT
		};

	   LinkEngine();
	   LinkEngine(const chrono::ChSharedPtr<chrono::ChLinkEngine>& ptr);
	   ~LinkEngine();

	   void SetEngMode(EEngMode engMode);

	   property Function^ SpeFunction
	   {
		   Function^ get();
	   }

	   property Function^ RotFunction
	   {
		   Function^ get();
	   }

	   property Function^ TorFunction
	   {
		   Function^ get();
	   }
	};
}