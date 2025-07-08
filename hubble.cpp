/***********************************************************************
 * Source File:
 *    HUBBLE
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    The Hubble class
 ************************************************************************/


#include "hubble.h"

/***************************************************
 * HUBBLE
 * the Hubble satellite default constructor
 * We will start with the telescope at (0.0 m, -42,164,000.0 m)
 * with a velocity of (3,100.0 m/s, 0.0 m/s).
 * The radius of Hubble is going to be 10 pixels
 ***************************************************/
Hubble::Hubble()
{
   radius = 10.0;
   angularVelocity = .05;
   position.setMeters(0.0, -42164000.0);
   velocity.setDxDy(3100.0, 0.0);
};

/***************************************************
 * destroy
 * When the Hubble breaks, it creates 4 Parts
 ***************************************************/
void Hubble::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   // kill();
   
   //satellites->push_back(std::make_unique<HubbleTelescope>(*this, Angle()));
   //satellites->push_back(std::make_unique<HubbleComputer>(*this, Angle()));
   //satellites->push_back(std::make_unique<HubbleLeft>(*this, Angle()));
   //satellites->push_back(std::make_unique<HubbleRight>(*this, Angle()));
}

/***************************************************
 * SATELLITE DRAW
 * Draw all the pieces.
 ***************************************************/
void Hubble::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawHubble(position, direction.getRadians());
   }
}
