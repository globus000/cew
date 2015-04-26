// ConsoleTestCLI.cpp : main project file.

#include "stdafx.h"

#include "physics/CHapidll.h" 
#include "physics/CHsystem.h"


using namespace System;

int main(array<System::String ^> ^args)
{
	chrono::DLL_CreateGlobals();
    Console::WriteLine(L"Hello World");
    return 0;
}
