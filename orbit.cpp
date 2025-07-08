/*************************************************************
 * 1. Name:
 *      Sim
 * 2. Assignment Name:
 *      Lab 10: Orbit All Satellites
 *
 * Edited by:
 *      Roger Galan & Jessen Forbush
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "test.h"
#include "earth.h"
#include "satellite.h"
#include "dreamchaser.h"
#include "sputnik.h"
#include "gps.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"

using namespace std;

double Position::metersFromPixels = 40.0;

/*************************************************************************
 * Sim
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Sim
{
   public:
   Sim(Position ptUpperRight) :
   ptUpperRight(ptUpperRight)
   {
      frameRate = 30.0;
      hoursPerDay = 24.0;
      minutesPerHour = 60.0;
      secondsPerMinute = 60.0;
      secondsPerDay = hoursPerDay * minutesPerHour * secondsPerMinute;
      timeDilation = hoursPerDay * minutesPerHour;
      radiansInOneDay = -2.0 * M_PI;
      radiansPerFrame = (radiansInOneDay / frameRate) * (timeDilation / secondsPerDay);
      
      satellites.push_back(make_unique<Dreamchaser>());
      for (int i = 0; i < 6; i++) {
         satellites.push_back(make_unique<Gps>(i));
      }
      satellites.push_back(make_unique<Hubble>());
      satellites.push_back(make_unique<Sputnik>());
      satellites.push_back(make_unique<Dragon>());
      satellites.push_back(make_unique<Starlink>());
      
      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }
   vector<unique_ptr<Satellite>> satellites;
   
   unsigned char phaseStar;
   double angleShip;
   double angleEarth;
   
   void draw(ogstream* pgout);
   void move();
   void input(const Interface* pUI);
   Position ptUpperRight;
   Earth earth;
   
   double frameRate;
   double hoursPerDay;
   double minutesPerHour;
   double secondsPerMinute;
   double secondsPerDay;
   double timeDilation;
   double radiansInOneDay;
   double radiansPerFrame;
};

/*************************************************************************
 * move
 * Updates the state of all game objects and handles collisions.
 *************************************************************************/
void Sim::move()
{
   double time = 48.0;
   for (auto& obj : satellites)
   {
      obj->move(time);
   }
}

/*************************************************************************
 * input
 * Handle user input for the DreamChaser ship.
 *************************************************************************/
void Sim::input(const Interface* pUI)
{
   for (auto& satellite : satellites)
   {
      Dreamchaser* dreamChaser = dynamic_cast<Dreamchaser*>(satellite.get());
      if (dreamChaser != nullptr)
      {
         dreamChaser->input(pUI);
         if (pUI->isSpace())
         {
            dreamChaser->fireProjectile(&satellites);
         }
         break;
      }
   }
}

/*************************************************************************
 * draw
 * Draws all game objects and the Earth.
 *************************************************************************/
void Sim::draw(ogstream* pgout)
{
   earth.draw(pgout, radiansPerFrame);
   
   for (const auto& obj : satellites)
   {
      if (!obj->isDead())
      {
         obj->draw(pgout);
      }
   }
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Sim* pSim = (Sim*)p;
   
   pSim->input(pUI);
   pSim->move();
   pSim->phaseStar++;
   
   ogstream gout(pSim->earth.getPosition());
   ogstream *pgout = &gout;
   
   pSim->draw(pgout);
}

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
                    _In_ HINSTANCE hInstance,
                    _In_opt_ HINSTANCE hPrevInstance,
                    _In_ PWSTR pCmdLine,
                    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();
   
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
                "Sim",   /* name on the window */
                ptUpperRight);
   
   Sim sim(ptUpperRight);
   
   ui.run(callBack, &sim);
   
   return 0;
}
