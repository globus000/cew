//
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2010 Alessandro Tasora
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be 
// found in the LICENSE file at the top level of the distribution
// and at http://projectchrono.org/license-chrono.txt.
//

///////////////////////////////////////////////////
//
//   ChLcpConstraintTwo.cpp
//
//
//    file for CHRONO HYPEROCTANT LCP solver 
//
// ------------------------------------------------
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////

  
#include "ChLcpConstraintTwo.h"

#include "core/ChMemory.h" // must be after system's include (memory leak debugger).


namespace chrono
{

// Register into the object factory, to enable run-time
// dynamic creation and persistence
ChClassRegisterABSTRACT<ChLcpConstraintTwo> a_registration_ChLcpConstraintTwo;



ChLcpConstraintTwo& ChLcpConstraintTwo::operator=(const ChLcpConstraintTwo& other)
{
	if (&other == this) return *this;

	// copy parent class data
	ChLcpConstraint::operator=(other);

	this->variables_a = other.variables_a;
	this->variables_b = other.variables_b;

	return *this;
}


void ChLcpConstraintTwo::StreamOUT(ChStreamOutBinary& mstream)
{
		// class version number
	mstream.VersionWrite(1);

		// serialize parent class too
	ChLcpConstraint::StreamOUT(mstream);

		// stream out all member data
	// NOTHING INTERESTING TO SERIALIZE (pointers to variables must be rebound in run-time.)

}

void ChLcpConstraintTwo::StreamIN(ChStreamInBinary& mstream) 
{
		// class version number
	int version = mstream.VersionRead();

		// deserialize parent class too
	ChLcpConstraint::StreamIN(mstream);

		// stream in all member data
	// NOTHING INTERESTING TO DESERIALIZE (pointers to variables must be rebound in run-time.)

}




} // END_OF_NAMESPACE____


