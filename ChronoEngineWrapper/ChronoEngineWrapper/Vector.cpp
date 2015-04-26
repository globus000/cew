
#include "stdafx.h"
#include "Vector.h"

namespace cew
{
	
	Vector::Vector() : _ptr( new chrono::ChVector<>() )
	{
	}


	Vector::Vector(double x, double y, double z) : _ptr( new chrono::ChVector<>(x,y,z) )
	{
	}

	Vector::Vector(Vector^ vector) : _ptr(new chrono::ChVector<>(vector->X, vector->Y, vector->Z))
	{
	}

	Vector::Vector(const chrono::ChVector<>& vector) : _ptr(new chrono::ChVector<>(vector))
	{
	}

	Vector::~Vector()
	{
	}

	Vector^ Vector::Null::get()
	{
	
		if(_vecNull == nullptr)
		{
			_vecNull = gcnew Vector(0,0,0);
		}
		return _vecNull;
	
	}

	Vector^ Vector::VectorX::get()
	{
	
		if(_vecX == nullptr)
		{
			_vecX = gcnew Vector(1,0,0);
		}
		return _vecX;
	
	}


	Vector^ Vector::VectorY::get()
	{
	
		if(_vecY == nullptr)
		{
			_vecY = gcnew Vector(0,1,0);
		}
		return _vecY;
	
	}

	Vector^ Vector::VectorZ::get()
	{
	
		if(_vecZ == nullptr)
		{
			_vecZ = gcnew Vector(0,0,1);
		}
		return _vecZ;
	
	}

	double Vector::X::get()
	{
		return _ptr->x;
	}

	void Vector::X::set(double value)
	{
		_ptr->x = value;
	}

	double Vector::Y::get()
	{
		return _ptr->y;
	}

	void Vector::Y::set(double value)
	{
		_ptr->y = value;
	}


	double Vector::Z::get()
	{
		return _ptr->z;
	}

	void Vector::Z::set(double value)
	{
		_ptr->z = value;
	}

	chrono::ChVector<>* Vector::Ptr::get()
	{
		return _ptr;
	}
	
	
}