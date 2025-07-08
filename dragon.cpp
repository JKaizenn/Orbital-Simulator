/***********************************************************************
 * Source File:
 *    Dragon
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Dragon class
 ************************************************************************/

#include "dragon.h"

/***************************************************
 * DRAGON
 * the Dragon satellite default constructor
 * We will put this satellite in a low earth orbit at
 * (0.0 m, 8,000,000.0 m) with a velocity of (-7,900.0 m/s, 0.0 m/s).
 * The radius of Dragon is going to be 7 pixels.
 ***************************************************/
Dragon::Dragon()
{
   radius = 7.0;
   angularVelocity = .05;
   position.setMeters(0.0, 8000000.0);
   velocity.setDxDy(-7900.0, 0.0);
}

/***************************************************
 * destroy
 * When the Crew Dragon comes into contact with another element
 * in the simulation it breaks up into 3 pieces and 2 fragments.
 ***************************************************/
void Dragon::destroy(std::vector<std::unique_ptr<Satellite>>* satellites)
{
   // kill();
   
   // When Dragon breaks up it creates:
   // - The center drawCrewDragonCenter() at 6 pixels radius and breaking into 4 fragments
   // - The left solar array drawCrewDragonLeft() at 6 pixel radius and breaking into 2 fragments
   // - The right solar array drawCrewDragonRight() at 6 pixel radius and breaking into 2 fragments
   
   //satellites->push_back(std::make_unique<DragonCenter>(*this, Angle()));
   //satellites->push_back(std::make_unique<DragonLeft>(*this, Angle()));
   //satellites->push_back(std::make_unique<DragonRight>(*this, Angle()));
   
   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
   //satellites->push_back(std::make_unique<Fragment>(*this, Angle()));
}

/***************************************************
 * SATELLITE DRAW
 * Draw all the pieces.
 ***************************************************/
void Dragon::draw(ogstream* pgout) const
{
   if (pgout != nullptr)
   {
      pgout->drawCrewDragon(position, direction.getRadians());
   }
}
