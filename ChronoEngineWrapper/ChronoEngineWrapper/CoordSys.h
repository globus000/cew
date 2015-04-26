#pragma once

#include "stdafx.h"
#include "Vector.h"

namespace cew
{
	public ref class CoordSys 
	{
	private:
		chrono::ChCoordsys<>* _ptr;
	public:
		
		CoordSys(const chrono::ChCoordsys<>& coords);
		CoordSys();
		~CoordSys();
		CoordSys(Vector^ pos);
		
		property chrono::ChCoordsys<>* Ptr
		{
			chrono::ChCoordsys<>* get();
		}

		property Vector^ Pos
		{
			Vector^ get();
		}
	};
}