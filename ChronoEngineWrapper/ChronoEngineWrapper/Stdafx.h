// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once


#include "physics/CHsystem.h"
#include "physics/ChShaftsGear.h" 
#include "physics/ChShaftsClutch.h"
#include "physics/ChShaftsPlanetary.h"
#include "physics/ChShaftsBody.h"
#include "physics/ChShaftsTorsionSpring.h"
#include "physics/ChShaftsTorqueConverter.h"
#include "physics/ChShaftsMotor.h"
#include "physics/ChShaftsTorque.h"
#include "physics/ChShaftsThermalEngine.h"
#include "RawPtr.h"
#include "Object.h"

#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)

#define PROPERTY_DECL(name, type) \
	\
		property type name\
		{\
			type get();\
			void set(type value);\
		}

#define PROPERTY_DECL_GET(name, type) \
	\
		property type name\
		{\
			type get();\
		}

#define PROPERTY_IMPL(type, name, basetype, basemethod, restype ) \
	restype type::name::get() \
	{ \
		return SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Get, basemethod)();\
	}\
	\
	void type::name::set(restype value)\
	{\
		SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Set, basemethod)(value);\
	}

#define PROPERTY_IMPLGC(type, name, basetype, basemethod, restype ) \
	restype^ type::name::get() \
	{ \
		return gcnew restype( SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Get, basemethod)() );\
	}\
	\
	void type::name::set(restype^ value)\
	{\
		SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Set, basemethod)(*(value->SharedPtr));\
	}

#define PROPERTY_IMPL_GET(type, name, basetype, basemethod, restype ) \
	restype type::name::get() \
	{ \
		return SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Get, basemethod)();\
	}\

#define PROPERTY_IMPL_GETGC(type, name, basetype, basemethod, restype ) \
	restype^ type::name::get() \
	{ \
		return gcnew restype( SharedPtr->DynamicCastTo<basetype>()->TOKENPASTE2(Get, basemethod)() );\
	}\

#define DECL_CLASS_START(name, baseclass, chronotype) \
	public ref class name : public baseclass \
	{ \
	public: \
		name(); \
		~name(); \
		name(const chrono::ChSharedPtr<chronotype>& ptr); \
		name(chronotype* ptr);

#define DECL_CLASS_START_NODEF(name, baseclass, chronotype) \
	public ref class name : public baseclass \
	{ \
	public: \
		~name(); \
		name(const chrono::ChSharedPtr<chronotype>& ptr); \
		name(chronotype* ptr);

#define DECL_CLASS_END };

#define BASIC_CONSTR_IMPL(name, baseclass, chronotype) \
	name::name() : baseclass( new chronotype() ) {} \
	\
	name::~name(){} \
	\
	name::name(const chrono::ChSharedPtr<chronotype>& ptr) : baseclass(ptr) {} \
	\
	name::name(chronotype* ptr) : baseclass(ptr) {}

#define BASIC_CONSTR_IMPL_NODEF(name, baseclass, chronotype) \
	name::~name(){} \
	\
	name::name(const chrono::ChSharedPtr<chronotype>& ptr) : baseclass(ptr) {} \
	\
	name::name(chronotype* ptr) : baseclass(ptr) {}

#define PTR_CAST(type) SharedPtr->DynamicCastTo<type>()

#define VPTR_CAST(value, type) value->PTR_CAST(type)

#define CH_VALUE(value) *(value->Ptr)
