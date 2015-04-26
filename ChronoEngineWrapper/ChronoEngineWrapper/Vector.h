#pragma once

#include "stdafx.h"

namespace cew
{
	public ref class Vector 
	{
	private:
		chrono::ChVector<>* _ptr;
		static Vector^ _vecNull;
		static Vector^ _vecX;
		static Vector^ _vecY;
		static Vector^ _vecZ;

	public:
		
		Vector();
		Vector(double x, double y, double z);
		Vector(Vector^ vector);
		Vector(const chrono::ChVector<>& vector);
		~Vector();

		static property Vector^ Null
		{
			Vector^ get();
		}

		static property Vector^ VectorX
		{
			Vector^ get();
		}

		static property Vector^ VectorY
		{
			Vector^ get();
		}

		static property Vector^ VectorZ
		{
			Vector^ get();
		}

		property double X
		{
			double get();
			void set(double value);
		}

		property double Y
		{
			double get();
			void set(double value);
		}

		property double Z
		{
			double get();
			void set(double value);
		}
		
		property chrono::ChVector<>* Ptr
		{
			chrono::ChVector<>* get();
		}
	};
}