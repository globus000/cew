
#include "stdafx.h"
#include "Object.h"
#include "StringUtils.h"

namespace cew
{
	Object::Object(chrono::ChObj* ptr) : RawPtr(ptr)
	{
	}

	Object::Object(const chrono::ChSharedPtr<chrono::ChObj>& ptr) : RawPtr(ptr)
	{
	}

	Object::~Object()
	{
	}

	void Object::Name::set(System::String^ name)
	{
		Ptr->SetName(StringUtils::ToSTLString(name).c_str());
	}

	System::String^ Object::Name::get()
	{
		return StringUtils::ToString(Ptr->GetName());
	}

	bool Object::Equals(Object^ other)
	{
		return Ptr == other->Ptr;
	}
}