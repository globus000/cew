
#include "stdafx.h"
#include "StringUtils.h"

#include <msclr\marshal_cppstd.h>

namespace cew
{
	std::string StringUtils::ToSTLString(System::String^ source)
	{
		return msclr::interop::marshal_as<std::string>(source);
	}

	System::String^ StringUtils::ToString(const std::string& source)
	{
		System::String^ result = gcnew System::String(source.c_str());
		return result;
	}
}