
#include "stdafx.h"
#include "LinkEngine.h"

namespace cew
{
	LinkEngine::LinkEngine() : LinkLock( new chrono::ChLinkEngine() )
	{
	}

	LinkEngine::~LinkEngine()
	{
	}

	LinkEngine::LinkEngine(const chrono::ChSharedPtr<chrono::ChLinkEngine>& ptr) : LinkLock(ptr)
	{
	}

	void LinkEngine::SetEngMode(LinkEngine::EEngMode mode)
	{
		((chrono::ChLinkEngine*)Ptr)->Set_eng_mode((int)mode);
	}

	Function^ LinkEngine::RotFunction::get()
	{
		return gcnew Function( ((chrono::ChLinkEngine*)Ptr)->Get_rot_funct()  );
	}

	Function^ LinkEngine::SpeFunction::get()
	{
		return gcnew Function( ((chrono::ChLinkEngine*)Ptr)->Get_spe_funct()  );
	}

	Function^ LinkEngine::TorFunction::get()
	{
		return gcnew Function( ((chrono::ChLinkEngine*)Ptr)->Get_tor_funct()  );
	}

}