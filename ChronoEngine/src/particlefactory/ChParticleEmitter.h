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
// File author: A.Tasora

#ifndef CHPARTICLEEMITTER_H
#define CHPARTICLEEMITTER_H


#include "ChRandomShapeCreator.h"
#include "ChRandomParticlePosition.h"
#include "ChRandomParticleAlignment.h"
#include "ChRandomParticleVelocity.h"
#include "core/ChMathematics.h"
#include "core/ChVector.h"
#include "core/ChMatrix.h"
#include "core/ChDistribution.h"
#include "core/ChSmartpointers.h"
#include "physics/ChSystem.h"


namespace chrono {

/// Namespace for helper classes that build a system for generating
/// flows of particles. This system heavily relies on statistical
/// approaches, for example positions, rotations, shapes of particles
/// can be generated according to statistical distributions.
namespace particlefactory {


	
	/// Class for emitters of particles, with random positions,
	/// rotations, and random shapes. You can setup a variety of 
	/// different emitters by assembling different types of 
	/// items inherited by classes like ChRandomShapeCreator,
	/// ChRandomParticlePosition, etc.
class ChParticleEmitter
{
public:

	enum eChFlowMode {
		FLOW_PARTICLESPERSECOND,
		FLOW_MASSPERSECOND,
	};

	ChParticleEmitter() 
		{
			// defaults:
			flow_mode = FLOW_PARTICLESPERSECOND; 
			particles_per_second = 100;
			mass_per_second = 1;
			particle_creator     = ChSharedPtr<ChRandomShapeCreatorSpheres>(new ChRandomShapeCreatorSpheres);
			particle_positioner  = ChSharedPtr<ChRandomParticlePositionRectangleOutlet>(new ChRandomParticlePositionRectangleOutlet);
			particle_aligner     = ChSharedPtr<ChRandomParticleAlignmentUniform> (new ChRandomParticleAlignmentUniform);
			particle_velocity    = ChSharedPtr<ChRandomParticleVelocity> (new ChRandomParticleVelocity);
			particle_angular_velocity = ChSharedPtr<ChRandomParticleVelocity> (new ChRandomParticleVelocity);
			creation_callback	 = 0;
			use_praticle_reservoir = false;
			use_mass_reservoir = false;
			particle_reservoir = 1000;
			mass_reservoir =  1;
			created_particles	= 0;
			created_mass	= 0;
			off_mass = 0;
			off_count = 0;
		}

			/// Function that creates random particles with random shape, position
			/// and alignment each time it is called. 
			/// Typically, one calls this function once per timestep.
	void EmitParticles(ChSystem& msystem, double dt)
		{
			double done_particles_per_step = this->off_count;
			double done_mass_per_step = this->off_mass;

			double particles_per_step = dt*particles_per_second;
			double mass_per_step = dt*mass_per_second;

			// Loop for creating particles at the timestep. Note that 
			// it would run forever, if there were no returns when flow amount is reached.
			while (true)
			{
				if ((use_praticle_reservoir)&&(this->particle_reservoir <= 0))
					return;

				if ((use_mass_reservoir)&&(this->mass_reservoir <= 0))
					return;

				// Flow control: break cycle when done 
				// enough particles, even with non-integer cases
				if (this->flow_mode == FLOW_PARTICLESPERSECOND)
				{
					if (done_particles_per_step > particles_per_step)
					{
						this->off_count = done_particles_per_step - particles_per_step;
						return;
					}
				}
				if (this->flow_mode == FLOW_MASSPERSECOND)
				{
					if (done_mass_per_step > mass_per_step)
					{
						this->off_mass = done_mass_per_step - mass_per_step;
						return;
					}
				}

				// Create the particle

				ChCoordsys<> mcoords;
				mcoords.pos = particle_positioner->RandomPosition();
				mcoords.rot = particle_aligner->RandomAlignment();

				ChSharedPtr<ChBody> mbody = particle_creator->RandomGenerateAndCallbacks(mcoords);
				
				mbody->SetPos_dt(particle_velocity->RandomVelocity());
				mbody->SetWvel_par(particle_angular_velocity->RandomVelocity());

				if (this->creation_callback)
					this->creation_callback->PostCreation(mbody, mcoords, *particle_creator.get_ptr());

				msystem.Add(mbody);

				this->particle_reservoir	-= 1;
				this->mass_reservoir		-= mbody->GetMass();;

				this->created_particles +=1;
				this->created_mass		+= mbody->GetMass();
	
				// Increment counters for flow control
				done_particles_per_step		+= 1;
				done_mass_per_step			+= mbody->GetMass();

			}
		}

			/// Pass an object from a ChPostCreationCallback-inherited class if you want to 
			/// set additional stuff on each created particle (ex.set some random asset, set some random material, or such)
	void SetCallbackPostCreation(ChCallbackPostCreation* mcallback) {this->creation_callback = mcallback;}

			/// Set the particle creator, that is an object whose class is
			/// inherited from ChRandomShapeCreator
	void SetParticleCreator   (ChSharedPtr<ChRandomShapeCreator> mc) {particle_creator = mc;}
		
			/// Set the particle positioner, that generates different positions for each particle
	void SetParticlePositioner(ChSharedPtr<ChRandomParticlePosition> mc) {particle_positioner = mc;}

			/// Set the particle aligner, that generates different rotations for each particle
	void SetParticleAligner   (ChSharedPtr<ChRandomParticleAlignment> mc) {particle_aligner = mc;}

			/// Set the generator of particle velocities, that generates different initial speed for each particle
	void SetParticleVelocity   (ChSharedPtr<ChRandomParticleVelocity> mc) {particle_velocity = mc;}
			
			/// Set the generator of angular velocities, for different initial angular velocity for each particle
	void SetParticleAngularVelocity  (ChSharedPtr<ChRandomParticleVelocity> mc) {particle_angular_velocity = mc;}

			/// define a flow rate measured as n.of particles per second [part/s], as by default
			/// or a flow rate measured as kg per second  [kg/s]. 
			/// Then, use ParticlesPerSecond() or MassPerSecond() to tune the flow.
	void SetFlowControlMode( eChFlowMode mymode) 
			{
				this->flow_mode = mymode;
				this->off_count = 0;
				this->off_mass = 0;
			}
			/// Report if flow rate is measured as [part/s] or [kg/s]. 
	eChFlowMode GetFlowControlMode() {return this->flow_mode;}

			/// Access the flow rate, measured as n.of particles per second [part/s].
			/// This is meaningful only if in 
	double& ParticlesPerSecond() {return particles_per_second;}

			/// Access the flow rate, measured as kg per second  [kg/s].
	double& MassPerSecond() {return mass_per_second;}

			/// Turn on this to limit on max amount of particles.
	void SetUseParticleReservoir(bool ml) {this->use_praticle_reservoir = ml;}

			/// Turn on this to limit on max mass of particles.
	void SetUseMassReservoir(bool ml) {this->use_mass_reservoir = ml;}

			/// Access the max number of particles to create - after this goes to 0, the creation stops.
			/// Remember to turn on this limit with SetLimitParticleAmount()
	int& ParticleReservoirAmount() {return particle_reservoir;}

			/// Access the max mass of particles to create - after this goes to 0, the creation stops.
			/// Remember to turn on this limit with SetLimitMassAmount()
	double& MassReservoirAmount() {return mass_reservoir;}

			/// Get the total amount of created particles
	int GetTotCreatedParticles() {return created_particles;}

			/// Get the total mass of created particles
	double GetTotCreatedMass() {return created_mass;}


private:
	eChFlowMode flow_mode;
	double particles_per_second;
	double mass_per_second;
	ChSharedPtr<ChRandomShapeCreator>	   particle_creator;
	ChSharedPtr<ChRandomParticlePosition>  particle_positioner;
	ChSharedPtr<ChRandomParticleAlignment> particle_aligner;
	ChSharedPtr<ChRandomParticleVelocity>  particle_velocity;
	ChSharedPtr<ChRandomParticleVelocity>  particle_angular_velocity;
	ChCallbackPostCreation* creation_callback;
	
	int  particle_reservoir;
	bool use_praticle_reservoir;
	
	double  mass_reservoir;
	bool use_mass_reservoir;

	int  created_particles;
	double created_mass;

	double	off_count;
	double	off_mass;
};


} // end of namespace particlefactory
} // end of namespace chrono


#endif  