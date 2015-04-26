// cew.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "StdAfx.h"

//#include "LcpSolver.h"
//#include "LcpSystemDescriptor.h"
//#include "Vector.h"
#include "Body.h"
#include "Marker.h"
#include "Link.h"
//#include "PhysicsItem.h"
//#include "Probe.h"
//#include "Controls.h"

namespace cew {

	public ref class ChronoSystem : public cew::Object
	{
	private:
		

	public:

		enum class EIntegrationType { INT_ANITESCU = 0, INT_TASORA = 6 };

		enum class ELcpSolver { 
			LCP_ITERATIVE_SOR = 0, LCP_ITERATIVE_SYMMSOR, LCP_SIMPLEX, LCP_ITERATIVE_JACOBI, 
			LCP_ITERATIVE_SOR_MULTITHREAD, LCP_ITERATIVE_PMINRES, LCP_ITERATIVE_BARZILAIBORWEIN, LCP_ITERATIVE_PCG, 
			LCP_ITERATIVE_APGD, LCP_DEM } ;

		ChronoSystem (unsigned int max_objects, double scene_size, bool init_sys);
		ChronoSystem(chrono::ChSystem* ptr);

		~ChronoSystem ();

		void Add(PhysicsItem^ item);
		void AddBody (Body^ newbody);
		void RemoveBody(Body^ body);
		void AddLink(Link^ link);
		void DoFrameDynamics(double time);


	};

}