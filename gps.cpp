/***********************************************************************
 * Header File:
 *    Gps
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Gps class
 ************************************************************************/

#include "gps.h"

/***************************************************
 * Gps
 * a GPS satellite, there will be 6 in the program
 ***************************************************/
Gps::Gps(int index)
{
   radius = 12.0;                  
   angularVelocity = .05;
   
   if (index == 0)
   {
      position.setMeters(0.0, 26560000.0);
      velocity.setDxDy(-3880.0, 0.0);
   }
   if (index == 1)
   {
      position.setMeters(23001634.72, 13280000.0);
      velocity.setDxDy(-1940.0, 3360.18);
   }
   if (index == 2)
   {
      position.setMeters(23001634.72, -13280000.0);
      velocity.setDxDy(1940.0, 3360.18);
   }
   if (index == 3)
   {
      position.setMeters(0.0, -26560000.0);
      velocity.setDxDy(3880.0, 0.0);
   }
   if (index == 4)
   {
      position.setMeters(-23001634.72, -13280000.0);
      velocity.setDxDy(1940.0, -3360.18);
   }
   if (index == 5)
   {
      position.setMeters(-23001634.72, 13280000.0);
      velocity.setDxDy(-1940.0, -3360.18);
   }
};

/***************************************************
 * destroy
 * When a GPS breaks, it creates 3 Parts and 2 Fragments.
 ***************************************************/
void Gps::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   // kill();

   //satellites->push_back(std::make_unique<GPSCenter>(*this, Angle()));
   //satellites->push_back(std::make_unique<GPSLeftSolarArray>(*this, Angle()));
   //satellites->push_back(std::make_unique<GPSRightSolarArray>(*this, Angle()));

   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
}

/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Gps::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawGPS(position, direction.getRadians());
   }
}
