//
// PROJECT CHRONO - http://projectchrono.org
//
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be 
// found in the LICENSE file at the top level of the distribution
// and at http://projectchrono.org/license-chrono.txt.
//
///////////////////////////////////////////////////
//
//  Summary: Validate a throttle driven DriveChain system.
//  Components: Gear, Powertrain, tensioned and passive Idler(s),
//              
//  Throttle, Brakes, Gear and pin damping interactively controlled w/ GUI.
//  Alternatively, scripted simulations supported, with or without interactive GUI visuals.
//  User Settings include: write to file/console, timing info, model info.
//  Supported visualization and collision geometry types found in ModelDefs.h
//  List of GUI keyboard commands in driver/ChIrrGuiTrack.cpp, ::OnEvent(SEvent& event)
//  IF you have python and pandas, data files written can all be auto-plotted with DriveChain_panda.py,
//    just need to specify the data directory, found in the script section: __name__ == '__main__':   
//
//   Output to text files for Python postProcessing, uncomment #define WRITE_OUTPUT
//	 Author: Justin Madsen, 2015
///////////////////////////////////////////////////
  
 
#include "physics/ChSystem.h"
// #include "particlefactory/ChParticleEmitter.h"

#include "core/ChFileutils.h"
#include "core/ChStream.h"
#include "core/ChRealtimeStep.h"
#include "physics/ChSystem.h"
#include "physics/ChLinkDistance.h"
#include "physics/ChBodyEasy.h"

#include "utils/ChUtilsInputOutput.h"
#include "utils/ChUtilsData.h"
#include "assets/ChTexture.h"
#include "assets/ChColorAsset.h"

/*
#if IRRLICHT_ENABLED
*/
#include "unit_IRRLICHT/ChIrrApp.h"
#include "subsys/driver/ChIrrGuiTrack.h"
// Use the main namespaces of Irrlicht
using namespace irr;    
using namespace core;
 /*
 # define USE_IRRLICHT
#endif
 */
 
#include "subsys/trackVehicle/DriveChain.h"
#include "subsys/driver/Track_FuncDriver.h"
#include "ModelDefs.h"
// Use the main namespace of Chronossssssssssssssssssssssssssssssssssssssssssss
using namespace chrono;

// =============================================================================
// User Settings
// =============================================================================

// *****  General system settings
size_t num_idlers = 1;
size_t num_wheels = 2;
double pin_damping_coef = 0.05;  // inter-shoe rev. joint damping coef. [N-s/m]
double tensioner_preload = 5e4; // idler subsystem tensioner preload [N]

// Initial position and heading
ChVector<> initLoc(0, 1.0, 0);
//ChQuaternion<> initRot = Q_from_AngAxis(CH_C_PI_4, VECT_Y);
ChQuaternion<> initRot(QUNIT);

// *****  Simulation step size, end time
double step_size = 1e-3;
// stop at a certain time
double end_time = 10;  // 99999

// *****  Driver settings
// Automated simulation controls, applies positive half a sine wave.
// Otherwise, control throttle with W/S
bool autopilot = true;
double sineAmp = 0.4;
double sineFreq = 0.3;
double tStart = 0.1;

// ***** write to console or a file
// #define WRITE_OUTPUT         // write output data to file
// #define CONSOLE_SYSTEM_INFO  // display the system heirarchy in the console
// #define CONSOLE_DEBUG_INFO      // log constraint violations to console,
#define CONSOLE_TIMING       // time each render and simulation step, log to console

int what_to_save = DBG_FIRSTSHOE | DBG_GEAR | DBG_COLLISIONCALLBACK | DBG_PTRAIN; // | DBG_IDLER  | DBG_CONSTRAINTS;
int what_to_console = DBG_PTRAIN | DBG_GEAR;  // DBG_COLLISIONCALLBACK | DBG_CONSTRAINTS | DBG_IDLER | DBG_FIRSTSHOE;
// int what_to_console = DBG_ALL_CONTACTS;
double save_step_size = 1e-3;  // Time interval for writing data to file, don't exceed 1 kHz.
double console_step_size = 1.0;       // time interval for writing data to console
std::string save_filename = "driveChain_CC";
std::string save_outDir = "../outdata_driveChain";

// *****  Visualization and camera settings
// control how often to render a frame, write to file, write to console.
int FPS = 80; // render Frames Per Second
double render_step_size = 1.0 / FPS;  // Time increment for rendered frames

// camera controls, either static or  GUI controlled chase camera:
bool use_fixed_camera = true;
// static camera position, global c-sys. (Longitude, Vertical, Lateral)
ChVector<> fixed_cameraPos(0.6, 1.2, 1.8); // (0.15, 1.15, 1.5);    // 

// Both cameras track this point, relative to the center of the gear
ChVector<> trackPoint(-0.4, -0.2, 0.0);

// if chase cam enabled:
double chaseDist = 2.5;
double chaseHeight = 0.5;

bool do_shadows = false; // shadow map is experimental


  /*
#else
  double tend = 20.0;

  const std::string out_dir = "../test_driveChain";
  const std::string pov_dir = out_dir + "/POVRAY";
#endif
  */

// =============================================================================
// =============================================================================
int main(int argc, char* argv[])
{
  // NOTE: utils library built with this sets this statically
  // SetChronoDataPath(CHRONO_DATA_DIR);

  // --------------------------
  // Create the Chain system (drive gear, idler, chain)

  // The drive chain inherits ChSystem. Specify the 
  // collision type used by the gear here.
  DriveChain chainSystem("Justins driveChain system", 
    VisualizationType::Mesh,
    //VisualizationType::Primitives,
    CollisionType::CallbackFunction,
    //CollisionType::Primitives,
    pin_damping_coef,
    tensioner_preload,
    num_idlers,
    num_wheels);
  
  // set the chassis REF at the specified initial config.
  chainSystem.Initialize(ChCoordsys<>(initLoc, initRot) );

  // if writing an output file, setup what debugInformation we want added each step data is saved.
#ifdef WRITE_OUTPUT
  chainSystem.Setup_log_to_file(what_to_save,
   save_filename,
    save_outDir);
#endif

  if(autopilot)
    chainSystem.SetDriveMode(TrackPowertrain::REVERSE);
/*
#ifdef USE_IRRLICHT
*/
  // Setup the Irrlicht GUI
  size_t window_x_len = 1200;
  size_t window_y_len = 800;
  // Create the Irrlicht visualization applicaiton
  ChIrrApp application(chainSystem.GetSystem(),
                      L"test driveChain demo",
                      dimension2d<u32>(window_x_len, window_y_len),
                      false,
                      do_shadows);
  // assumes Y-up
  application.AddTypicalSky();
 
  irr::scene::ILightSceneNode* mlight = 0;

  if (do_shadows)
  {
    mlight = application.AddLightWithShadow(
      irr::core::vector3df(-50.f, -20.f, 80.f),
      irr::core::vector3df(-30.f, 80.f, -50.f),
      150, 60, 80, 15, 512, irr::video::SColorf(1, 1, 1), false, false);
  }
  else
  {
    application.AddTypicalLights(
      irr::core::vector3df(50.f, -25.f, 30.f),
      irr::core::vector3df(-30.f, 80.f, -50.f),
      150, 125);
  }

  application.SetTimestep(step_size);

  // the GUI driver
  ChIrrGuiTrack driver(application, chainSystem, trackPoint, chaseDist, chaseHeight,window_x_len-150);
  // even though using a chase camera, set the initial camera position laterally
  if(use_fixed_camera)
    driver.SetCameraPos(fixed_cameraPos);

  // Set the time response for steering and throttle keyboard inputs.
  // NOTE: this is not exact, since we do not render quite at the specified FPS.
  double throttle_time = 2.0;  // time to go from 0 to +1
  double braking_time = 0.5;	// time to go from 0 to +1
  // driver.SetSteeringDelta(render_step_size / 1);
  driver.SetThrottleDelta(render_step_size / throttle_time);
  driver.SetBrakingDelta(render_step_size / braking_time);
  driver.SetDampingDelta(render_step_size / 3.0);

  // Set up the assets for rendering
  application.AssetBindAll();
  application.AssetUpdateAll();
  if (do_shadows)
  {
    application.AddShadowAll();
  }
/*
#else
  
#endif
*/
  Track_FuncDriver function_driver(1, sineFreq, sineAmp, tStart);


  // ---------------------
  // GUI and render settings

  // GUI driver inputs
  std::vector<double> throttle_input;
  std::vector<double> braking_input;

  // Number of simulation steps between two 3D view render frames
  int render_steps = (int)std::ceil(render_step_size / step_size);

  // Number of simulation steps between two output frames
  int save_steps = (int)std::ceil(save_step_size / step_size);

  // Number of steps between two log to consoles
  int console_steps = (int)std::ceil(console_step_size / step_size);

  // ---------------------
  // Simulation loop
#ifdef CONSOLE_SYSTEM_INFO
  GetLog() << "\n\n============ System Configuration ============\n";
  chainSystem.GetSystem()->ShowHierarchy(GetLog() );
#endif

  // Initialize simulation frame counter and simulation time
  int step_number = 0;
  double time = 0;

  // create some timers, for the render and total time
  ChTimer<double> step_timer;
  double total_step_time = 0;
  double time_since_last_output = 0;
//  #ifdef USE_IRRLICHT
  // using Irrlicht? time that too.
  ChTimer<double> render_timer;
  double total_render_time = 0;
//  #endif
/*
#ifdef USE_IRRLICHT
*/
// write data to file?
#ifdef WRITE_OUTPUT
      chainSystem.Log_to_file();  // needs to already be setup before sim loop calls it
#endif
  ChRealtimeStepTimer realtime_timer;
  bool is_end_time_reached = false;
  while ( application.GetDevice()->run() && (!is_end_time_reached) )
	{ 
		// keep track of the time spent calculating each sim step
    step_timer.start();
		
    // Render scene
    if (step_number % render_steps == 0) {
      render_timer.start(); // start the time it takes to render the scene
      application.GetVideoDriver()->beginScene(true, true,irr::video::SColor(255, 140, 161, 192));
      driver.DrawAll();
      application.GetVideoDriver()->endScene();

      render_timer.stop();  // stop the scene timer
      total_render_time += render_timer();  // increment the time it took to render this step
    }
    //  input is specified by the user, or by a function (autopilot)
    if(autopilot)
    {
      throttle_input = function_driver.GetThrottle();
      braking_input = function_driver.GetBraking();
      // set the GUI info
      driver.SetThrottleFunc(throttle_input[0]);

      // driver.SetBrakingFunc(braking_input);
    }

    else
    {
      // Collect output data from modules (for inter-module communication)
      throttle_input = driver.GetThrottle();
      braking_input = driver.GetBraking();
    }

    // Update
    time = chainSystem.GetSystem()->GetChTime();

    driver.Update(time);

    if(autopilot)
      function_driver.Update(time);

    chainSystem.Update(time, throttle_input[0], braking_input[0]);

    // Advance simulation for one timestep for all modules
    // step_size = realtime_timer.SuggestSimulationStep(step_size);
    use_fixed_camera ? driver.Advance(step_size, fixed_cameraPos): driver.Advance(step_size); 

    // Settlings phase has hardcoded solver settings, for the first few timesteps
    if( !application.GetPaused() )
    {
      chainSystem.Advance(step_size);
      step_number++;
    }



    // DEBUGGING
    if( chainSystem.GetCollisionCallback()->GetNcontacts() > 0 && 0)
    {
      // write contact info to console when narrow phase passes
      chainSystem.Log_to_console(DBG_ALL_CONTACTS);
      int arg = 2;
    }

    // stop and increment the step timer
    step_timer.stop();
    total_step_time += step_timer();
    time_since_last_output += step_timer();

#ifdef WRITE_OUTPUT
    if (step_number % save_steps == 0) 
    {
      // write data to file
      chainSystem.Log_to_file();  // needs to already be setup before sim loop calls it
    }
#endif

    if(step_number % console_steps == 0)
    {
      // log desired output to console
#ifdef CONSOLE_DEBUG_INFO
      chainSystem.Log_to_console(what_to_console);
#endif

#ifdef CONSOLE_TIMING
      GetLog() << "\n --------- TIMING -------- : time: " << chainSystem.GetSystem()->GetChTime()
       << "\n total render time: " << total_render_time << ",  % of total: " << 100.*total_render_time / total_step_time
       << "\n total compute time: " << total_step_time 
       << "\n Avg. time per step " << time_since_last_output * chainSystem.GetSystem()->GetStep() / save_steps
       << "\n overall avg. time/step: " << total_step_time/step_number << "    for a stepsize: " << chainSystem.GetSystem()->GetStep()
       << "\n RTR : " << total_step_time / chainSystem.GetSystem()->GetChTime();
      time_since_last_output = 0;
#endif
    }
   
    // see if the end time is reached
    if(time > end_time)
      is_end_time_reached = true;

  }

  // application.GetDevice()->drop();

/*
#else

  int render_frame = 0;

  if(ChFileutils::MakeDirectory(out_dir.c_str()) < 0) {
    std::cout << "Error creating directory " << out_dir << std::endl;
    return 1;
  }
  if(ChFileutils::MakeDirectory(pov_dir.c_str()) < 0) {
    std::cout << "Error creating directory " << pov_dir << std::endl;
    return 1;
  }

  chainSystem.ExportMeshPovray(out_dir);

  char filename[100];

  while (time < tend)
  {
    if (step_number % render_steps == 0) {
      // Output render data
      sprintf(filename, "%s/data_%03d.dat", pov_dir.c_str(), render_frame + 1);
      utils::WriteShapesPovray(chainSystem.GetSystem(), filename);
      std::cout << "Output frame:   " << render_frame << std::endl;
      std::cout << "Sim frame:      " << step_number << std::endl;
      std::cout << "Time:           " << time << std::endl;
      std::cout << " throttle: " << driver.GetThrottle() << " braking: " << driver.GetBraking() << std::endl;
      std::cout << std::endl;
      render_frame++;
    }

    // Collect output data from modules (for inter-module communication)
    throttle_input = driver.GetThrottle();
    braking_input = driver.GetBraking();

    // Update modules (process inputs from other modules)
    time = chainSystem.GetSystem()->GetChTime();

    driver.Update(time);

    chainSystem.Update(time, throttle_input, braking_input);

    // Advance simulation for one timestep for all modules
    driver.Advance(step_size);

    chainSystem.Advance(step_size);

    // Increment frame number
    step_number++;
  }

#endif

*/

	return 0;
}


