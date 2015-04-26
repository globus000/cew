

#pragma once

#include <string>

namespace cew
{
	public ref class StringUtils
	{
	public:
		static std::string ToSTLString(System::String^ source);
		static System::String^ ToString(const std::string& source);

	};

}