

#include "stdafx.h"
#include "CoordSys.h"

namespace cew{

	
	CoordSys::CoordSys() : _ptr(new chrono::ChCoordsys<>())
	{
		
	}

	CoordSys::CoordSys(const chrono::ChCoordsys<>& coords) : _ptr(new chrono::ChCoordsys<>(coords))
	{
	}

	CoordSys::~CoordSys()
	{
		delete _ptr;
	}

	CoordSys::CoordSys(Vector^ pos) : _ptr(new chrono::ChCoordsys<>(*(pos->Ptr)))
	{
	
	}

	chrono::ChCoordsys<>* CoordSys::Ptr::get()
	{
		return _ptr;
	}

	Vector^ CoordSys::Pos::get()
	{
		return gcnew Vector( _ptr->pos );
	}
	
}