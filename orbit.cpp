/*************************************************************
 * 1. Name:
 *      Sim
 * 2. Assignment Name:
 *      Lab 09: Orbit Simulator
 *
 * Edited by:
 *      Roger Galan & Jessen Forbush
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
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
      
      // spawn stars later on not ready
      satellites.push_back(make_unique<Dreamchaser>());
      for (int i = 0; i < 6; i++) {
         satellites.push_back(make_unique<Gps>(i));
      }
      satellites.push_back(make_unique<Hubble>());
      satellites.push_back(make_unique<Sputnik>());
      satellites.push_back(make_unique<Dragon>());
      satellites.push_back(make_unique<Starlink>());
      
      phaseStar = 0;
   }
   vector<unique_ptr<Satellite>> satellites;
   
   unsigned char phaseStar;
   
   void input(const Interface* pUI);
   void move();
   void draw(ogstream* pgout);
   double computeDistance(const Position& pos1, const Position& pos2);
   
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

double Sim::computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getPixelsX() - pos2.getPixelsX()) * (pos1.getPixelsX() - pos2.getPixelsX()) +
               (pos1.getPixelsY() - pos2.getPixelsY()) * (pos1.getPixelsY() - pos2.getPixelsY()));
}

/*************************************************************************
 * INPUT
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
 * MOVE
 * Updates the state of all game objects and handles collisions.
 *************************************************************************/
void Sim::move()
{
   double time = 48.0;
   for (auto& obj : satellites)
   {
      obj->move(time);
   }
   
   // Collision detection pass
   for (size_t i = 0; i < satellites.size(); i++)
   {
      
      for (size_t j = i + 1; j < satellites.size(); j++)
      {
         if (!satellites[i]->isDead() && !satellites[j]->isDead())
         {
            double distance = computeDistance(satellites[i]->getPosition(), satellites[j]->getPosition());
            
            // Check for collision between satellites[i] and satellites[j]
            if (distance < satellites[i]->getRadius() + satellites[j]->getRadius())
            {
               // Trigger collision handling on both objects.
               // This method will mark them `dead`.
               satellites[i]->kill();
               satellites[j]->kill();
            }
         }
      }
   }
   
   std::vector<Satellite*> toDestroy; // Store raw pointers of dead objects
   
   for (const auto& obj_ptr : satellites)
   {
      if (obj_ptr->isDead())
      {
         toDestroy.push_back(obj_ptr.get());
      }
   }
   
   // Now call destroy on them. The destroy method might add new satellites
   // to the 'satellites' vector. This is safe because 'satellites' is not
   // being iterated over for removal yet.
   for (Satellite* deadObj : toDestroy)
   {
      deadObj->destroy(&satellites); // Passes pointer to the main vector
   }
   
   // Step 2: Remove the actually dead objects from the vector.
   // Use erase-remove idiom for unique_ptr vector.
   // This is safe and efficient.
   satellites.erase(
                    std::remove_if(satellites.begin(), satellites.end(),
                                   [](const std::unique_ptr<Satellite>& s) { return s->isDead(); }),
                    satellites.end());
}

/*************************************************************************
 * DRAW
 * Displays all game objects and the Earth.
 *************************************************************************/
void Sim::draw(ogstream* pgout)
{
   // Draw Earth
   earth.draw(pgout, radiansPerFrame);
   
   // Draw all satellites (polymorphically)
   for (const auto& obj : satellites)
   {
      if (!obj->isDead()) // Only draw if not dead
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
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Sim* pSim = (Sim*)p;
   
   //
   // accept input
   //
   pSim->input(pUI);
   
   //
   // perform all the game logic
   //
   pSim->move();
   pSim->phaseStar++;
   
   //
   // draw everything
   //
   ogstream gout(pSim->earth.getPosition());
   ogstream *pgout = &gout;
   
   // draw a single star
   //gout.drawStar(pDemo->ptStar, pDemo->phaseStar);
   pSim->draw(pgout);
}

double Position::metersFromPixels = 40.0;

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
   
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
                "Sim",   /* name on the window */
                ptUpperRight);
   
   // Initialize the demo
   Sim sim(ptUpperRight);
   
   // set everything into action
   ui.run(callBack, &sim);
   
   
   return 0;
}
