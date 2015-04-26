using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using cew;

namespace ConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {


                cew.ChronoSystem system = new cew.ChronoSystem(100, 100.0, true);

                cew.Body bodyA = new Body();
                cew.Body bodyB = new Body();
                cew.Body bodyC = new Body();

                bodyA.Name = "truss";
                bodyB.Name = "crank";
                bodyC.Name = "rod";

                system.AddBody(bodyA);
                system.AddBody(bodyB);
                system.AddBody(bodyC);
                
                bodyA.BodyFixed = true;
                bodyB.Position = new Vector(1,0,0);
                bodyC.Position = new Vector(4,0,0);
                
                Marker markerB = new Marker();
                Marker markerC = new Marker();

                markerB.Name = "crank_rev";
                markerC.Name = "rod_rev";

                bodyB.AddMarker(markerB);
                bodyC.AddMarker(markerC);

                markerB.ImposeAbsCoords(new CoordSys(new Vector(2, 0, 0)));
                markerC.ImposeAbsCoords(new CoordSys(new Vector(2, 0, 0)));
                
                LinkLockRevolute linkBC = new LinkLockRevolute();
                linkBC.Initialize(markerB, markerC); 
                linkBC.Name = "REVOLUTE crank-rod";
                
                system.AddLink(linkBC);
                
                LinkLockRevolute linkAC = new LinkLockRevolute();
                linkAC.Initialize(bodyC, bodyA, new CoordSys(new Vector(6, 0, 0)));
                system.AddLink(linkAC);

                linkAC.Marker1.Name = "rod_poinline";
                linkAC.Marker2.Name = "truss_pointline";
                linkAC.Name = "POINTLINE rod-truss";
                
                LinkEngine linkAB = new LinkEngine();
                linkAB.Initialize(bodyA, bodyB, new CoordSys(new Vector(0,0,0)));
                linkAB.SetEngMode(LinkEngine.EEngMode.ENG_MODE_SPEED);
                FunctionConst mfun = new FunctionConst( linkAB.SpeFunction );
                mfun.YConst = 3.145;
                system.AddLink(linkAB);

                linkAB.Marker1.Name = "truss_engine";
                linkAB.Marker2.Name = "crank_engine";
                linkAB.Name = "ENGINE truss-crank";
                
                double chrono_time = 0.0;
                while (chrono_time < 2.5)
                {
                    chrono_time += 0.01;
                    system.DoFrameDynamics(chrono_time);

                    Console.WriteLine("Time: " + chrono_time + " Slider X pos: " + linkAC.Marker1.AbsCoord.Pos.X);
                }
            


               
        
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
