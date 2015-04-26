using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using cew;

namespace demo_powertrain
{
    class Program
    {
        static void Main(string[] args)
        {
            if (false)
            {
                // EXAMPLE 1
                cew.ChronoSystem system = new cew.ChronoSystem(100, 100.0, true);

                Shaft shaftA = new Shaft();
                shaftA.Inertia = 10;
                shaftA.AppliedTorque = 6;
                system.Add(shaftA);

                Shaft shaftB = new Shaft();
                shaftB.Inertia = 100;
                shaftB.ShaftFixed = false;
                system.Add(shaftB);

                ShaftsGear shaftGearAB = new ShaftsGear();
                shaftGearAB.Initialize(shaftA, shaftB);
                shaftGearAB.TransmissionRatio = -0.1;
                system.Add(shaftGearAB);

                double chronoTime = 0;
                while (chronoTime < 2.5)
                {
                    chronoTime += 0.01;

                    // PERFORM SIMULATION UP TO chronoTime
                    system.DoFrameDynamics(chronoTime);

                    Console.Write("Time: " + chronoTime +
                        "\n shaft A rot: " + shaftA.Pos +
                        " shaft A speed: " + shaftA.PosDt +
                        " shaft A accel: " + shaftA.PosDtDt +
                        "\n shaft B rot: " + shaftB.Pos +
                        " shaft B speed: " + shaftB.PosDt +
                        " shaft B accel: " + shaftB.PosDtDt +
                        "\n"  +
                        "AB gear, toruq on A: " + shaftGearAB.TorqueReactionOn1 +
                        " torque on B " + shaftGearAB.TorqueReactionOn2);
                        

                }
            }

            if (false)
            {
                // EXAMPLE 2
                cew.ChronoSystem system = new cew.ChronoSystem(100, 100.0, true);
                Shaft shaftA = new Shaft();
                shaftA.Inertia = 0.5;
                shaftA.PosDt = 30;
                system.Add(shaftA);

                Shaft shaftB = new Shaft();
                shaftB.Inertia = 0.6;
                shaftA.PosDt = -10;
                system.Add(shaftB);

                ShaftsClutch clutch = new ShaftsClutch();
                clutch.Initialize(shaftA, shaftB);
                clutch.SetTorqueLimit(60);
                system.Add(clutch);

                clutch.Modulation = 0;

                double chronoTime = 0;
                while (chronoTime < 1.5)
                {
                    chronoTime += 0.01;

                    // PERFORM SIMULATION UP TO chronoTime
                    system.DoFrameDynamics(chronoTime);

                    // Activate the clutch only after 0.8 seconds of simulation:
                    if (chronoTime > 0.8)
                    {
                        clutch.Modulation = 1;
                    }
                    Console.Write("Time: " + chronoTime +
                               "\n shaft A rot: " + shaftA.Pos +
                               " shaft A speed: " + shaftA.PosDt +
                               " shaft A accel: " + shaftA.PosDtDt +
                               "\n shaft B rot: " + shaftB.Pos +
                               " shaft B speed: " + shaftB.PosDt +
                               " shaft B accel: " + shaftB.PosDtDt +
                               "\n" +
                               "AB gear, toruq on A: " + clutch.TorqueReactionOn1 +
                               " torque on B " + clutch.TorqueReactionOn2);
                }
            
            }

            if (true)
            {
                // EXAMPLE 3
                cew.ChronoSystem system = new cew.ChronoSystem(100, 100.0, true);
                Shaft shaftA = new Shaft();
                shaftA.Inertia = 0.5;
                shaftA.AppliedTorque = 10;
                system.Add(shaftA);

                Shaft shaftB = new Shaft();
                shaftB.Inertia = 0.5; 
                system.Add(shaftB);

                Shaft shaftC = new Shaft();
                shaftC.ShaftFixed = true;
                system.Add(shaftC);

                ShaftsPlanetary planetaryBAC = new ShaftsPlanetary();
                planetaryABC.Initialize(shaftB, shaftA, shaftC);
                system.Add(planetaryBAC);

                Shaft shaftD = new Shaft();
                shaftD.ShaftFixed = true;
                system.Add(shaftD);

                ShaftsClutch clutch = new ShaftsClutch();
                clutch.Initialize(shaftB, shaftD);

                double chronoTime = 0;
                while (chronoTime < 1.5)
                {
                    chronoTime += 0.01;

                    // PERFORM SIMULATION UP TO chronoTime
                    system.DoFrameDynamics(chronoTime);
                    Console("Time: " +  chronoTime + 
                                         "\n shaft A rot: " + shaftA.Pos +
                               " shaft A speed: " + shaftA.PosDt +
                               " shaft A accel: " + shaftA.PosDtDt +
                               "\n shaft B rot: " + shaftB.Pos +
                               " shaft B speed: " + shaftB.PosDt +
                               " shaft B accel: " + shaftB.PosDtDt +
                               "\n epicycloidal react torques on shafts - on A: " + 
                               planetaryBAC.TorqueReactionOn2 + " "
                               "on B: " + planetaryBAC.TorqueReactionOn1 + " ") 

                }


            }
        }
    }
}
