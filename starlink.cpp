/***********************************************************************
 * Source File:
 *    Starlink
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Starlink class
 ************************************************************************/

#include "starlink.h"

/***************************************************
 * STARLINK
 * the Starlink satellite default constructor
 * We will therefore put our Starlink satellite at
 * (0.0 m, -13,020,000.0 m) with a velocity of (5,800.0 m/s, 0.0 m/s).
 * The radius of the satellite is 6 pixels.
 ***************************************************/
Starlink::Starlink()
{
   radius = 6.0;
   angularVelocity = .05;
   position.setMeters(0.0, -13020000.0);
   velocity.setDxDy(5800.0, 0.0);
}

/***************************************************
 * destroy
 * When a Starlink comes into contact with another element
 * in the simulation it breaks up into 2 pieces and 2 fragments.
 ***************************************************/
void Starlink::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   // kill();
   
   // When Starlink breaks up it creates:
   // - The body drawStarlinkBody() at 2 pixels radius and breaking into 3 fragments
   // - The right solar array drawStarlinkArray() at 4 pixel radius and breaking into 3 fragments
   
   //satellites->push_back(std::make_unique<StarlinkBody>(*this, Angle()));
   //satellites->push_back(std::make_unique<StarlinkArray>(*this, Angle()));
   
   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
}

/***************************************************
 * SATELLITE DRAW
 * Draw all the pieces.
 ***************************************************/
void Starlink::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawStarlink(position, direction.getRadians());
   }
}
